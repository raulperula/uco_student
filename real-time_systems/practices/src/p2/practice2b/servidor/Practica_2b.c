/**
 * @file    Practica_2b.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

// Sensores
#define SONAR_PORT		NXT_PORT_S1
#define PUL_PARO_PORT	NXT_PORT_S4
#define PUL_CHOQUE_PORT	NXT_PORT_S2
// Actuadores
#define MOT_I 			NXT_PORT_C
#define MOT_D 			NXT_PORT_B
// Otros
#define VEL_GIRO 50
#define VEL_DESP 50

/*--------------------------------------------------------------------------*/
/* OSEK declarations                                                        */
/*--------------------------------------------------------------------------*/
DeclareTask(LeerPulsadores);
DeclareTask(LeerSonar);
DeclareTask(Comparar);
DeclareTask(Mirar);
DeclareTask(Avanzar);
DeclareTask(PantallaLCD);
DeclareCounter(SysTimerCnt);

// Dirección MAC del robot (cambiar segun el cliente)
const U8 bd_addr[7] = {0x00,0x16,0x53,0x01,0x86,0x58,0x00}; // carlos
// const U8 bd_addr[7] = {0x00,0x16,0x53,0x01,0x83,0x78,0x00}; // miguel

// Zona de variables globales
int sensor = 0;				// almacena la medida en bruto del sonar
int desact_comparar = 0;	// flag que desactiva temporalmente la tarea de comparacion
int giro = 0; 				
int giro_ant = 0;
int distancia = 0;			
int choque = 0;				// flag que almacena si el pulsador de choque esta activado o no
int parada = 0;				// flag que almecena si el pulsador de parada esta activado o no

// Globales para log de movimientos
int pulsado = 0;			// flag que controla la pulsacion para enviar los movimientos al cliente
int paso = 0;				// variable que almacena el numero de pasos que ha dado el servidor para salir del laberinto
int listamovimientos[500][2];	// matriz que almacena el tipo de 
								// movimiento (0 -> adelante, 1-> giro
								// y los grado de movimiento o giro

void ecrobot_device_initialize()
{
	// Inicializar los sensores activos
	ecrobot_init_sonar_sensor(SONAR_PORT);
	// Inicializar modulo bluetooth
	ecrobot_init_bt_master(bd_addr,"STR");
}
void ecrobot_device_terminate()
{
	// Finalizar los sensores activos
	ecrobot_term_sonar_sensor(SONAR_PORT);
	// Finalizar conexion bluetooth
	ecrobot_term_bt_connection();
}

/*--------------------------------------------------------------------------*/
/* Function to be invoked from a category 2 interrupt                       */
/*--------------------------------------------------------------------------*/
void user_1ms_isr_type2(){
	StatusType ercd;

	ercd = SignalCounter(SysTimerCnt);
	
	if(ercd != E_OK){
		ShutdownOS(ercd);
	}
}

/*--------------------------------------------------------------------------*/
/* Definitions                                                              */
/*--------------------------------------------------------------------------*/

// Esta funcion detiene ambos servos para parar el robot
void parar_motor()
{
	// parar motor
	nxt_motor_set_speed(MOT_I, 0, 1);
	nxt_motor_set_speed(MOT_D, 0, 1);
}

// Esta funcion toma tres muestras del sonar y se queda con la media
int obtener_distancia()
{
	int sensor1, sensor2, sensor3, sensor;
	// Cuando detecte el sensor de sonar que hay una distancia 
	// de 1m se reduce la potencia de los motores a la mitad
	sensor1 = ecrobot_get_sonar_sensor(SONAR_PORT);
	systick_wait_ms(20);
	sensor2 = ecrobot_get_sonar_sensor(SONAR_PORT);
	systick_wait_ms(20);
	sensor3 = ecrobot_get_sonar_sensor(SONAR_PORT);
	systick_wait_ms(20);
	
	sensor = (sensor1+sensor2+sensor3)/3;
	// if(sensor == 255) sensor = 0;
	return (sensor);
}

// Funcion para mover el motor x la distancia en mm y a la velocidad z
void mover_motor(U32 motor, int distancia, int velocidad)
{
	int grados = (360*distancia)/188;
	if(velocidad < 0){
		grados = grados*(-1);
	}
	int ref = nxt_motor_get_count(motor)+grados;
	nxt_motor_set_speed(motor, velocidad, 1);
	
	if(velocidad < 0){
		while(nxt_motor_get_count(motor) > ref);
	}
	else{
		while(nxt_motor_get_count(motor) < ref);
	}
	
	nxt_motor_set_speed(motor, 0, 1);
}

// Funcion para mover dos motores x la distancia y a la velocidad z
void mover_motores(U32 motor1, U32 motor2, int dist1, int dist2, int vel1, int vel2)
{
	int llega1 = 0;	// flag para determinar el final del movimiento del motor 1
	int llega2 = 0;	// flag para determinar el final del movimiento del motor 1
	int dir1 = 1; 	//1 -> adelante, -1 -> atras, 0 -> parado
	int dir2 = 1;	//1 -> adelante, -1 -> atras, 0 -> parado
	
	// Obtenemos los grados que tienen que girar las ruedas
	int grados1 = (360*dist1)/188;
	int grados2 = (360*dist2)/188;
	
	// Esta conversion permite especificar velocidades negativas y positivas
	if(vel1 < 0){
		grados1 = -grados1;
		dir1 = -dir1;
	}
	if(vel2 < 0){
		grados2 = -grados2;
		dir2 = -dir2;
	}
	
	// Calculamos angulos de referencia
	int ref1 = nxt_motor_get_count(motor1)+grados1;
	int ref2 = nxt_motor_get_count(motor2)+grados2;
	
	// Iniciamos los motores
	nxt_motor_set_speed(motor1, vel1, 1);
	nxt_motor_set_speed(motor2, vel2, 1);
	
	// Comprobamos si hemos llegado al angulo de referencia y si es asi
	// paramos los motores
	while((llega1 != 1) || (llega2 != 1)){
		if(dir1 < 0){
			if(nxt_motor_get_count(motor1) <= ref1){
				llega1 = 1;
				nxt_motor_set_speed(motor1,0,1);
			}
		}
		else{
			if(nxt_motor_get_count(motor1) >= ref1){
				llega1 = 1;
				nxt_motor_set_speed(motor1,0,1);
			}
		}
		if(dir2 < 0){
			if(nxt_motor_get_count(motor2) <= ref2){
				llega2 = 1;
				nxt_motor_set_speed(motor2,0,1);
			}
		}
		else{
			if(nxt_motor_get_count(motor2) >= ref2){
				llega2 = 1;
				nxt_motor_set_speed(motor2,0,1);
			}
		}
	}		
}


// Funcion que envia la matriz de movimientos por filas
void enviar_movimientos_bt(void)
{
	int i,j;
	U8 nmovs[1], mov[5];

	nmovs[0] = (U8) paso;

	ecrobot_send_bt_packet(nmovs, 1);

	for(i=0;i<paso;i++){
		mov[0] = (U8) listamovimientos[i][0];

		for(j=4;j>0;j--){
			mov[j] = listamovimientos[i][1]%10;
			listamovimientos[i][1] = listamovimientos[i][1]/10;
		}
		while(ecrobot_send_bt_packet(mov,5) != 5);
	}
}

//##############################################################################

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : LeerPulsadores                                                 */
/* Priority: 10                                                             */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que lee ambos pulsadores (choque y parada) y actua en   */
/* 			  consecuencia.     											*/
/*--------------------------------------------------------------------------*/
TASK(LeerPulsadores)
{
	int i;
	
	// Cuando detecte el sensor de pulsacion de paro, almacena el ultimo
	// movimiento y muestra los movimientos por pantalla
	if(ecrobot_get_touch_sensor(PUL_PARO_PORT) == 1 || parada == 1){
		desact_comparar = 1;
		parada = 1;
		parar_motor();
		
		if(pulsado == 0){
			pulsado = 1;
			// Almacena el ultimo movimiento
			listamovimientos[paso][0] = 0;
			listamovimientos[paso][1] = nxt_motor_get_count(MOT_I);
			paso++;
		
			// Muestra la lista de movimientos a enviar
			display_clear(0);
			for(i=0;i<paso;i++){
				display_goto_xy(0,i);
				display_string("PASO ");
				display_int(i,1);
				display_string(": ");
				display_int(listamovimientos[i][0],1);
				display_string(" ");
				display_int(listamovimientos[i][1],3);
			}
			display_update();
			
			// envia los movimientos por bluetooth al cliente
			enviar_movimientos_bt();
		}
	}
	// Comprobamos si ha habido un choque y asignamos el valor correspondiente al flag
	if(ecrobot_get_touch_sensor(PUL_CHOQUE_PORT) == 1){
		choque = 1;
	}
	else{
		choque = 0;
	}
	
	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : LeerSonar		                                                */
/* Priority: 9                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que toma tres muestras del sonar y se queda con la media*/
/*--------------------------------------------------------------------------*/
TASK(LeerSonar)
{
	int sensor1, sensor2, sensor3;
	
	// Cuando detecte el sensor de sonar que hay una distancia 
	// de 1m se reduce la potencia de los motores a la mitad
	sensor1 = ecrobot_get_sonar_sensor(SONAR_PORT);
	systick_wait_ms(20);
	sensor2 = ecrobot_get_sonar_sensor(SONAR_PORT);
	systick_wait_ms(20);
	sensor3 = ecrobot_get_sonar_sensor(SONAR_PORT);
	systick_wait_ms(20);
	
	sensor = (sensor1+sensor2+sensor3)/3;
	
	// Activa la comparacion
	ChainTask(Comparar);
	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Comparar		                                                */
/* Priority: 6                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que realiza las tareas pertinentes segun la distancia 	*/
/* 			  del robot a la pared.											*/
/*--------------------------------------------------------------------------*/
TASK(Comparar)
{
	// Comprobamos que no se este mirando la distancia maxima
	if(desact_comparar == 0){
		// Si estamos cerca de un obstaculo paramos y miramos una nueva ruta
		if(sensor <= 25){
			// Almacenamos el paso anterior
			listamovimientos[paso][0] = 0;
			listamovimientos[paso][1] = nxt_motor_get_count(MOT_I);
			paso++;

			desact_comparar = 1;
			parar_motor();
			
			// Buscamos nueva ruta
			ActivateTask(Mirar);
			nxt_motor_set_count(MOT_I,0);
			nxt_motor_set_count(MOT_D,0);
		}
		// Si nos hemos chocado nos movemos hacia atras y miramos una nueva ruta
		else if(choque == 1){
			desact_comparar = 1;
			parar_motor();
			mover_motores(MOT_I,MOT_D,75,75,-VEL_GIRO,-VEL_GIRO);
			
			// Almacenamos el movimiento
			listamovimientos[paso][0] = 0;
			listamovimientos[paso][1] = nxt_motor_get_count(MOT_I);
			nxt_motor_set_count(MOT_I,0);
			nxt_motor_set_count(MOT_D,0);
			paso++;
			
			// Buscamos nueva ruta
			ActivateTask(Mirar);
		}
		else{
			ActivateTask(Avanzar);
		}
	}	
	
	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Mirar			                                                */
/* Priority: 7                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: NON		                                                    */
/* Objective: Tarea que busca la distancia maxima en un radio de 180º		*/
/* 			  delante del robot.											*/
/*--------------------------------------------------------------------------*/
TASK(Mirar)
{
	int dist = 0;
	int nuevadist = 0;
	int max_dist = 0;
	int ind_giro = 0;
	int i;
	
	// se gira 90 grados a la izquierda
	mover_motores(MOT_I,MOT_D,90,90,-VEL_GIRO,VEL_GIRO);
	
	// chequear la distancia maxima
	for(i=0;i<17;i++){	
		nuevadist = obtener_distancia();
		if(nuevadist != 255){
			dist = nuevadist;
		}
		display_clear(0);
		display_goto_xy(0,0);
		display_int(dist,3);
		display_update();
		
		if(dist > max_dist){
			max_dist = dist;
			ind_giro = i;
		}
		mover_motores(MOT_I,MOT_D,10,10,VEL_GIRO,-VEL_GIRO);	
	}
	
	// volver a la posicion donde se encontraba la distancia maxima
	mover_motores(MOT_I,MOT_D,190-(10*ind_giro),190-(10*ind_giro),-VEL_GIRO,VEL_GIRO);
	
	listamovimientos[paso][0] = 1;
	// Se le suma 90 para poder pasar el número positivo por bluetooth
	listamovimientos[paso][1] = (90-(180-(10*ind_giro)))+90;
	paso++;
	
	// se activa la comprobacion otra vez
	desact_comparar = 0;

	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Avanzar                                                        */
/* Priority: 5                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que pone en marcha los motores del robot.			    */
/*--------------------------------------------------------------------------*/
TASK(Avanzar)
{
	nxt_motor_set_speed(MOT_I, VEL_DESP, 1);
	nxt_motor_set_speed(MOT_D, VEL_DESP-1, 1);
	
	// Termina la tarea actual
	TerminateTask();
}

//##############################################################################

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : PantallaLCD		                                            */
/* Priority: 1                  	                                        */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL	                	                                    */
/* Objective: Tarea que muestra los valores de estado por la LCD.           */
/*--------------------------------------------------------------------------*/
TASK(PantallaLCD)
{
	// Tarea que muestra las medidas del robot por pantalla
	ecrobot_status_monitor("");
	
	// Termina la tarea actual
	TerminateTask();
}
