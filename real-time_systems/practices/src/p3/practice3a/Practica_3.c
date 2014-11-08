/**
 * @file    Practica_3.c
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
#define LIGTH_PORT	NXT_PORT_S4
// Actuadores
#define MOT_I 		NXT_PORT_C
#define MOT_D 		NXT_PORT_B

/*--------------------------------------------------------------------------*/
/* OSEK declarations                                                        */
/*--------------------------------------------------------------------------*/
DeclareTask(Calibrar);
DeclareTask(Equilibrar);
DeclareTask(PantallaLCD);
DeclareCounter(SysTimerCnt);

// Zona de variables globales
int luz_act = 0;
int dif_act = 0;
int dif_ant = 0;
int calibrado = 0;
int equilibrio = 0;
int integral = 0;

/* Errores que se calculan en cada ejecucion de la tarea equilibrar */
int Ep = 0;		// Error proporcional
int Ed = 0;		// Error derivativo
int Ei = 0;		// Error integral

/* Las siguientes constantes se pueden modificar para calibrar el robot */
int Kp = 5;		// Constante proporcional 	(valores recomendados de 0 a 10)
int Ki = 1;		// Constante integral		(valores recomendados de 0 a 5)
int Kd = 2;		// Constante derivativa		(valores recomendados de 0 a 3)
int Kai = 1;	// Constante de amortiguacion de la integral (valores de 0 a 1)
int Kri = 1;	// Constante de reseteado de la integral (valores de 1 a 10)

void ecrobot_device_initialize()
{
	// Inicializar los sensores activos
	ecrobot_set_light_sensor_active(LIGTH_PORT);
}
void ecrobot_device_terminate()
{
	// Finalizar los sensores activos
	ecrobot_set_light_sensor_inactive(LIGTH_PORT);
}

/*--------------------------------------------------------------------------*/
/* Definitions                                                              */
/*--------------------------------------------------------------------------*/

// Funcion que para y frena ambos motores del robot
void parar_motor()
{
	// parar motor
	nxt_motor_set_speed(MOT_I, 0, 1);
	nxt_motor_set_speed(MOT_D, 0, 1);
}

/*	Funcion que calcula el error proporcional. Este error depende
	exclusivamente de la desviacion respecto al punto de equilibrio.
	Actua sobre la potencia de los motores de manera directamente
	proporcional a la desviacion que sufra el robot en cada instante.
*/
void calcular_error_proporcional()
{
	// Ponemos la desviacion actual en la anterior antes de actualizar
	dif_ant = dif_act;
	// Actualizamos la desviacion actual
	dif_act = (luz_act - equilibrio);
	
	Ep = dif_act;
}

/*	Funcion que calcula el error derivativo. Este error se basa en el
	comportamiento actual y el anterior del robot e intenta predecir
	para donde se desviara el robot en el siguiente instante. Permite
	adelantarse a desequilibrios del robot y actuar sobre los motores
	antes de que sea tarde
*/
void calcular_error_derivativo()
{
	Ed = dif_act - dif_ant;
}

/* 	Funcion que calcula el error integral. Este error se basa en la
	historia de errores anteriores a lo largo del tiempo e intenta
	predecir la tendencia actual del error. Permite bajar la potencia
	a los motores antes de pasarse del punto de equilibrio por inercia
	y aumentar la potencia de los mismos si el error no se corrige con
	la potencia actual
*/
void calcular_error_integral()
{
	integral = Kai*integral + dif_act;
	if(dif_act == 0) integral = integral/Kri;
	Ei = integral;
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

/* 	Esta tarea permite recalibrar el robot. Para ello se intentara dejar el robot
	sobre las dos ruedas de la manera mas equilibrada posible y se pulsara el boton
	situado en la parte superior izquierda del mismo, tras lo cual el robot comenzara
	el proceso de equilibrado automatico. Si se desea recalibrar el robot basta con
	pulsar de nuevo el boton para parar el robot y comenzar el proceso de nuevo 
*/
TASK(Calibrar)
{
	// Paramos motores
	parar_motor();
	
	// Esperamos a que el usuario suelte el boton
	while(ecrobot_get_touch_sensor(NXT_PORT_S3) == 1);
	
	// Reseteamos flag calibrado
	calibrado = 0;
	
	// Reseteamos errores y contador de integral
	Ei = 0;
	Ep = 0;
	Ed = 0;
	integral = 0;
	
	// Mostramos mensaje de advertencia al usuario
	display_clear(0);
	display_goto_xy(0,0);
	display_string("Calibrando");
	display_goto_xy(0,1);
	display_string("equilibrar y ");
	display_goto_xy(0,2);
	display_string("pulsar.");
	display_update();
	
	// Recogemos valor de equilibrio
	while(calibrado == 0){
		while(ecrobot_get_touch_sensor(NXT_PORT_S3) == 1){
			calibrado = 1;
			equilibrio = ecrobot_get_light_sensor(LIGTH_PORT);
		}
	}
	TerminateTask();
}

/* 	En esta tarea se equilibra el aparato. Para ello se usara un modelo PID 
	(proporcional, integrador, derivativo) para intentar predecir el
	comportamiento del robot y actuar en consecuencia. Los coeficientes
	Kp, Ki y Kd permiten ponderar los errores proporcional, integral y
	derivativo respectivamente. Actualmente, estos coeficientes estan
	calibrados, pero puede que sea necesario recalibrarlos para su uso en
	superficies distintas a la usada como prueba.
*/
TASK(Equilibrar)
{	
	
		
	// Tomamos la medida actual
	luz_act = ecrobot_get_light_sensor(LIGTH_PORT);
	
	// Calculamos el error respecto al punto de equilibrio
	calcular_error_proporcional();
	
	// Calculamos el error integral
	calcular_error_integral();
	
	// Actualizamos la tasa de desviacion
	calcular_error_derivativo();
		
	// Movemos motores
	nxt_motor_set_speed(MOT_I, Kp*Ep+Ki*Ei+Kd*Ed, 1);
	nxt_motor_set_speed(MOT_D, Kp*Ep+Ki*Ei+Kd*Ed, 1);
	
	// Comprobamos pulsador de calibrado
	if(ecrobot_get_touch_sensor(NXT_PORT_S3) == 1){
		ActivateTask(Calibrar);
	}
		
	TerminateTask();
}

//##############################################################################

/*--------------------------------------------------------------------------*/
/* Task information:                                                        */
/* -----------------                                                        */
/* Name    : PantallaLCD		                                            */
/* Priority: 5                  	                                        */
/* Typ     : EXTENDED TASK                                                  */
/* Schedule: 1		                	                                    */
/* Objective: Tarea que muestra los valores de estado por la LCD            */
/*--------------------------------------------------------------------------*/
TASK(PantallaLCD)
{
	// Limpiamos pantalla
	display_clear(0);
	
	// Mostramos constantes
	display_goto_xy(0,0);
	display_string("Kp:");
	display_int(Kp,1);
	display_string(" Ki:");
	display_int(Ki,1);
	display_string(" Kd:");
	display_int(Kd,1);
	
	// Mostramos valores de luz y de equilibrio
	display_goto_xy(0,1);
	display_string("Luz:");
	display_int(luz_act,3);
	display_string(" Equ:");
	display_int(equilibrio,3);
	
	// Mostramos errores absolutos y ponderados
	display_goto_xy(0,2);
	display_string("Ep:");
	display_int(Ep,3);
	display_string(" (");
	display_int(Kp*Ep,3);
	display_string(")");
	display_goto_xy(0,3);
	display_string("Ei:");
	display_int(Ei,3);
	display_string(" (");
	display_int(Ki*Ei,3);
	display_string(")");
	display_goto_xy(0,4);
	display_string("Ed:");
	display_int(Ed,3);
	display_string(" (");
	display_int(Kd*Ed,3);
	display_string(")");
	
	// Mostramos movimiento actual de los motores
	display_goto_xy(0,6);
	display_string("MOT:");
	display_int(Kp*Ep+Ki*Ei+Kd*Ed,4);
	
	// Actualizamos pantalla y terminamos
	display_update();
	TerminateTask();
}
