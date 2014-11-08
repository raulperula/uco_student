/**
 * @file    Practica_2bC.c
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
DeclareTask(Avanzar);
DeclareTask(PantallaLCD);
DeclareCounter(SysTimerCnt);

// Dirección MAC del robot
const U8 bd_addr[7] = {0x00,0x16,0x53,0x01,0x86,0x58,0x00};

// Zona de variables globales
int sensor = 0;
int desact_comparar = 0;
int giro = 0;
int giro_ant = 0;
int distancia = 0;
int choque = 0;
int parada = 0;

// Globales para log de movimientos
int pulsado = 0;
int paso = 0;
int inicio_movimiento = 0;
int rev_inicio;
int rev_fin;
int listamovimientos[500][2];

void ecrobot_device_initialize()
{
	// Inicializar modulo bluetooth en modo slave
	ecrobot_init_bt_slave("STR");
}

void ecrobot_device_terminate()
{
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

// funcion para detener los servomotores del robot
void parar_motor()
{
	// parar motor
	nxt_motor_set_speed(MOT_I, 0, 1);
	nxt_motor_set_speed(MOT_D, 0, 1);
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
	int llega1 = 0;
	int llega2 = 0;
	int dir1 = 1;  //1 -> adelante, -1 -> atras, 0 -> parado
	int dir2 = 1;
	
	int grados1 = (360*dist1)/188;
	int grados2 = (360*dist2)/188;
	
	if(vel1 < 0){
		grados1 = -grados1;
		dir1 = -dir1;
	}
	if(vel2 < 0){
		grados2 = -grados2;
		dir2 = -dir2;
	}
	
	int ref1 = nxt_motor_get_count(motor1) + grados1;
	int ref2 = nxt_motor_get_count(motor2) + grados2;
	
	nxt_motor_set_speed(motor1, vel1, 1);
	nxt_motor_set_speed(motor2, vel2, 1);
	
	while((llega1 != 1)||(llega2 != 1)){
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

// Funcion para recibir la matriz de movimientos del servidor mediante bluetooth
void recibir_movimientos_bt(void)
{
	int i;
	U8 nmovs[1], mov[5];
	
	nmovs[0] = 0;
	
	// Leemos hasta que nos llegue el dato correcto
	while(nmovs[0] == 0){
		ecrobot_read_bt_packet(nmovs,1);
	};
	paso = (int)nmovs[0];
	
	display_clear(0);
	display_goto_xy(0,0);
	display_int(paso,2);
	display_update();

	// Leemos la matriz por columnas y transformamos los 4 octetos
	// en un entero de 32 bits
	for(i=0;i<paso;i++){ 
		while(ecrobot_read_bt_packet(mov, 5) != 5);

		listamovimientos[i][0] = mov[0];
		listamovimientos[i][1] = mov[4] + mov[3]*10+ mov[2]*100 + mov[1]*1000;
		if(mov[0]==1){
			listamovimientos[i][1] -= 90;
		}
	}
}

//##############################################################################

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Avanzar		                                                */
/* Priority: 5                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que recibe los movimientos del servidor y sigue dichos  */
/* 			  movimientos.													*/
/*--------------------------------------------------------------------------*/
TASK(Avanzar)
{
	int i = 0;
	int opcion = 2;
	
	// recibe los movimientos por bluetooth del servidor
	recibir_movimientos_bt();

	// Muestra la lista de movimientos recibidos
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

	// Segun el tipo de movimiento se hace la accion correspondiente
	for(i=0;i<paso;i++){
		opcion = listamovimientos[i][0];
		switch(opcion)
		{
			// Movimiento recto
			case 0:
				mover_motores(MOT_I,MOT_D,listamovimientos[i][1]/2,listamovimientos[i][1]/2,VEL_DESP,VEL_DESP);
				break; 
			
			// Giro
			case 1:
				if(listamovimientos[i][1] < 0){
					mover_motores(MOT_I,MOT_D,-listamovimientos[i][1],-listamovimientos[i][1],-VEL_DESP,VEL_DESP);
				}
				else{
					mover_motores(MOT_I,MOT_D,listamovimientos[i][1]*2,listamovimientos[i][1]*2,VEL_DESP,-VEL_DESP);
				}
				break;
		}
	}
	
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
	ecrobot_status_monitor("");
	
	// Termina la tarea actual
	TerminateTask();
}
