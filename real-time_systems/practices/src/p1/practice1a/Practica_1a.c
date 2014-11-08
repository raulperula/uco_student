/**
 * @file    Practica_1a.c
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

/*--------------------------------------------------------------------------*/
/* OSEK declarations                                                        */
/*--------------------------------------------------------------------------*/
DeclareTask(Avance);
DeclareTask(Final);

/*--------------------------------------------------------------------------*/
/* Definitions                                                              */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* Function to be invoked from a category 2 interrupt                       */
/*--------------------------------------------------------------------------*/
void user_1ms_isr_type2(){}

void ecrobot_device_terminate(){
	ecrobot_set_motor_speed(NXT_PORT_A, 0);
	ecrobot_set_motor_speed(NXT_PORT_C, 0);
}

//##############################################################################

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Avance                                                         */
/* Priority: 1                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL		                                                    */
/* Objective: Funcion para avanzar y a la vez calibrar los servomotores     */
/*--------------------------------------------------------------------------*/
TASK(Avance)
{
	//int time_out = systick_get_ms()+5000; // Se calcula 5 segundos

	// Activa motores para comprobar si existe desvio en la navegacion
	nxt_motor_set_speed(NXT_PORT_A, 49, 1);    
	nxt_motor_set_speed(NXT_PORT_C, 50, 1);

	// Espera hasta que se agote el time_out
	systick_wait_ms(5000);

	// Despierta la tarea de parada de motores
	ActivateTask(Final);

	// Termina la tarea actual
	TerminateTask();
}

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : Final                                                          */
/* Priority: 2                                                              */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: FULL 	                                       		            */
/* Objective: Funcion para parar los servomotores                           */
/*--------------------------------------------------------------------------*/
TASK(Final)
{
    // Parar los motores
    nxt_motor_set_speed(NXT_PORT_A, 0, 1);
    nxt_motor_set_speed(NXT_PORT_C, 0, 1);

    // Termina la tarea actual
	TerminateTask();

}
