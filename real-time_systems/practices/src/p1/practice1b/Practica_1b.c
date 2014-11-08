/**
 * @file    Practica_1b.c
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

#define MOT_I NXT_PORT_C
#define MOT_D NXT_PORT_A
#define MED_IZD 50
#define MED_DCH 49

//##############################################################################

// Funcion para mover el motor izq. o der. una distancia 'y' a una velocidad 'z'
void mover_motor(U32 motor, int distancia, int velocidad)
{
	int grados = (360*distancia)/18;
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

// Funcion para mover los dos motores una distancia 'y' a una velocidad 'z'
void mover_motores(U32 motor1, U32 motor2, int dist1, int dist2, int vel1, int vel2)
{
	int llega1 = 0;
	int llega2 = 0;
	int dir1 = 1;  //1 -> adelante, -1 -> atras, 0 -> parado
	int dir2 = 1;
	
	// Las ruedas motrices tienen 18 cm de circunferencia
	int grados1 = (360*dist1)/18;
	int grados2 = (360*dist2)/18;
	
	if(vel1 < 0){
		grados1 = -grados1;
		dir1 = -dir1;
	}
	if(vel2 < 0){
		grados2 = -grados2;
		dir2 = -dir2;
	}
	
	int ref1 = nxt_motor_get_count(motor1)+grados1;
	int ref2 = nxt_motor_get_count(motor2)+grados2;
	
	nxt_motor_set_speed(motor1, vel1, 1);
	nxt_motor_set_speed(motor2, vel2, 1);
	
	while((llega1 != 1) || (llega2 != 1)){
		if(dir1 < 0){
			if(nxt_motor_get_count(motor1) <= ref1){
				llega1 = 1;
				nxt_motor_set_speed(motor1, 0, 1);
			}
		}
		else{
			if(nxt_motor_get_count(motor1) >= ref1){
				llega1 = 1;
				nxt_motor_set_speed(motor1, 0, 1);
			}
		}
		if(dir2 < 0){
			if(nxt_motor_get_count(motor2) <= ref2){
				llega2 = 1;
				nxt_motor_set_speed(motor2, 0, 1);
			}
		}
		else{
			if(nxt_motor_get_count(motor2) >= ref2){
				llega2 = 1;
				nxt_motor_set_speed(motor2, 0, 1);
			}
		}
	}
}

//##############################################################################

/*--------------------------------------------------------------------------*/
/* OSEK declarations                                                        */
/*--------------------------------------------------------------------------*/
DeclareTask(Avance);
DeclareTask(Giro);
DeclareTask(Final);
DeclareTask(PantallaLCD);
DeclareCounter(SysTimerCnt);

/*--------------------------------------------------------------------------*/
/* Definitions                                                              */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* Function to be invoked from a category 2 interrupt                       */
/*--------------------------------------------------------------------------*/
void user_1ms_isr_type2(){
	StatusType ercd;

	ercd = SignalCounter(SysTimerCnt); /* Incrementa el contador de alarma */
	if (ercd != E_OK)
	{
		ShutdownOS(ercd);
	}
}

void ecrobot_device_terminate(){
	ecrobot_set_motor_speed(MOT_I, 0);
	ecrobot_set_motor_speed(MOT_D, 0);
}

//##############################################################################

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Avance                                                         */
/* Priority: 10                                                             */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea para avanzar moviendo los servomotores                  */
/*--------------------------------------------------------------------------*/
TASK(Avance)
{
	// Esperar 5 segundos para empezar el programa
	systick_wait_ms(5000);
	
	// Mover los motores hacia delante
	mover_motores(MOT_I, MOT_D, 40, 40, 50, 49);
	
	// Activar la tarea de giro
	ActivateTask(Giro);
	
	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Giro                                                           */
/* Priority: 10                                                             */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Tarea para girar haciendo uso de los servomotores             */
/*--------------------------------------------------------------------------*/
TASK(Giro)
{
	// Activa motores para comprobar si existe desvio en la navegacion 
	mover_motor(MOT_I, 19, 50);
	mover_motores(MOT_I, MOT_D, 5, 5, 50, 49);
	mover_motor(MOT_D, 19, 49);
	
	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Final                                                          */
/* Priority: 11                                                             */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL 	                                       		            */
/* Objective: Tarea para parar los servomotores                             */
/*--------------------------------------------------------------------------*/
TASK(Final)
{
    // Parar los motores
    nxt_motor_set_speed(MOT_D, 0, 1);
    nxt_motor_set_speed(MOT_I, 0, 1);

    // Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : PantallaLCD                                                    */
/* Priority: 11                                                             */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL 	                                       		            */
/* Objective: Tarea que muestra los valores de estado por la LCD            */
/*--------------------------------------------------------------------------*/
TASK(PantallaLCD)
{
	// Muestra por la pantalla del nxt los datos de los servomotores
	ecrobot_status_monitor("Aparcamiento");
	
	// Termina la tarea actual
	TerminateTask();
}
