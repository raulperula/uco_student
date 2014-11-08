/**
 * @file    p17q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

VARIABLE g_total NUMBER

ACCEPT salary PROMPT 'Please enter the salary amount: '
ACCEPT bonus PROMPT 'Please enter the bonus percentage: '

DECLARE
	v_sal		NUMBER		:= NVL(&salary, 0);
	v_bonus NUMBER(4,2) := &bonus/100;
BEGIN
	:g_total := v_sal+v_sal*v_bonus;
END;
/

PRINT g_total
