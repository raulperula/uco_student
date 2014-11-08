/**
 * @file    Practica_1c.c
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
#define SONAR_PORT NXT_PORT_S2
#define PULSADOR1_PORT NXT_PORT_S1
#define PULSADOR2_PORT NXT_PORT_S4
// Actuadores
#define MOT_I NXT_PORT_C
#define MOT_D NXT_PORT_A

/*--------------------------------------------------------------------------*/
/* OSEK declarations                                                        */
/*--------------------------------------------------------------------------*/
DeclareTask(VelBaja);
DeclareTask(VelMedia);
DeclareTask(VelAlta);
DeclareTask(Retroceso);
DeclareTask(CambioDir);
DeclareTask(PararMotor);
DeclareTask(ChequeoDistancia);
DeclareTask(ChequeoSonar);
DeclareTask(ChequeoPulsadores);
DeclareTask(PantallaLCD);
DeclareCounter(SysTimerCnt);

// Zona de variables globales
int sensor = 0;
int pulsado = 0;
int atras = 0;

void ecrobot_device_initialize()
{
	// Inicializar los sensores activos
	ecrobot_init_sonar_sensor(SONAR_PORT);
}
void ecrobot_device_terminate()
{
	// Finalizar los sensores activos
	ecrobot_term_sonar_sensor(SONAR_PORT);
}

/*--------------------------------------------------------------------------*/
/* Definitions                                                              */
/*--------------------------------------------------------------------------*/

// Funcion para mover el motor izq. o der. una distancia 'y' a una velocidad 'z'
void mover_motor(U32 motor, int distancia, int velocidad)
{
	int grados = (360*distancia)/18;
	if(velocidad < 0){
		grados = grados*(-1);
	}
	int ref = nxt_motor_get_count(motor) + grados;
	nxt_motor_set_speed(motor, velocidad, 1);

	if(velocidad < 0){
		while(nxt_motor_get_count(motor) > ref);
	}
	else{
		while(nxt_motor_get_count(motor) < ref);
	}

	nxt_motor_set_speed(motor, 0, 1);
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

//##############################################################################

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : VelBaja                                                        */
/* Priority: 4                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que pone los servomotores a un cuarto de velocidad.     */
/*--------------------------------------------------------------------------*/
TASK(VelBaja)
{
	// Pone los motores a un cuarto de velocidad
	nxt_motor_set_speed(MOT_I, 25, 1);
	nxt_motor_set_speed(MOT_D, 22, 1);

	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : VelMedia                                                       */
/* Priority: 3                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que pone los servomotores a la mitad de velocidad.      */
/*--------------------------------------------------------------------------*/
TASK(VelMedia)
{
	// Pone los motores a la mitad de velocidad
	nxt_motor_set_speed(MOT_I, 50, 1);
	nxt_motor_set_speed(MOT_D, 48, 1);

	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : VelAlta                                                        */
/* Priority: 2                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que pone los servomotores a maxima velocidad.		    */
/*--------------------------------------------------------------------------*/
TASK(VelAlta)
{
	atras = 0;

	// Pone los motores a maxima velocidad
	nxt_motor_set_speed(MOT_I, 100, 1);
	nxt_motor_set_speed(MOT_D, 98, 1);

	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Retroceso                                                      */
/* Priority: 7                                                  	        */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que mueve los servomotores hacia atras.			        */
/*--------------------------------------------------------------------------*/
TASK(Retroceso)
{
	// Poner los motores para retroceder
	nxt_motor_set_speed(MOT_I, -25, 1);
	nxt_motor_set_speed(MOT_D, -24, 1);
	// Esperar un segundo
	systick_wait_ms(1000);
	// Parar los motores
	nxt_motor_set_speed(MOT_I, 0, 1);
	nxt_motor_set_speed(MOT_D, 0, 1);

	// Cambio de tarea para realizar el giro
	ChainTask(CambioDir);

	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : CambioDir		                                    	        */
/* Priority: 6                                                      	    */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: 1		                                    		            */
/* Objective: Tarea que realiza un giro de 90 grados.					    */
/*--------------------------------------------------------------------------*/
TASK(CambioDir)
{
	// Realiza un giro de 90 grados
	mover_motor(MOT_I, 19, 50);

	atras = 0;

	// Cambia de tarea a maxima velocidad
	ChainTask(VelAlta);

	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : PararMotor                                                     */
/* Priority: 5                                  	                        */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que para los servomotores.						        */
/*--------------------------------------------------------------------------*/
TASK(PararMotor)
{
	// Para los motores
	nxt_motor_set_speed(MOT_I, 0, 1);
	nxt_motor_set_speed(MOT_D, 0, 1);

	// Termina la tarea actual
	TerminateTask();
}

//##############################################################################

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : ChequeoDistancia                                               */
/* Priority: 10                                                             */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea periodica que chequea a que distancia se encuentra.     */
/*--------------------------------------------------------------------------*/
TASK(ChequeoDistancia)
{
	if(sensor == -1){
		ActivateTask(PararMotor);
	}
	// Si la distancia es mayor a 120 cm los motores se encuentran a maxima velocidad
	else if(sensor > 120){
		ActivateTask(VelAlta);
	}
	// Si la distancia se encuentra entre 120 cm y 40 cm se reduce la potencia de los motores a la mitad
	else if((sensor <= 120) && (sensor > 40)){
		ActivateTask(VelMedia);
	}
	// Si la distancia es menor que 40 cm se reduce la potencia de los motores a la mitad
	else if(sensor <= 40){
		ActivateTask(VelBaja);
	}

	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : ChequeoSonar     		                                        */
/* Priority: 10                                                             */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea periodica que captura el valor del sonar.			    */
/*--------------------------------------------------------------------------*/
TASK(ChequeoSonar)
{
	// Se coge el valor que capta el sonar
	sensor = ecrobot_get_sonar_sensor(SONAR_PORT);
	systick_wait_ms(20);

	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : ChequeoPulsadores                                      	    */
/* Priority: 11                                                             */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea que chequea si los pulsadores estan activos		   		*/
/*--------------------------------------------------------------------------*/
TASK(ChequeoPulsadores)
{
	// Si alguno de los dos pulsadores se encuentra activo y no se encuentra en
	// el momento de retroceder, se empieza a retroceder
	if((ecrobot_get_touch_sensor(PULSADOR1_PORT) == 1 || ecrobot_get_touch_sensor(PULSADOR2_PORT) == 1) && (atras == 0)){
		if(!pulsado){
			pulsado = 1;
			atras = 1;
			ActivateTask(Retroceso);
		}
	}
	else{
		pulsado = 0;
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
	// Muestra por la pantalla del nxt los datos de los servomotores
	ecrobot_status_monitor("");

	// Termina la tarea actual
	TerminateTask();
}
