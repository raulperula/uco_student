/**
 * @file    p17q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

VARIABLE v_result NUMBER

ACCEPT num1 PROMPT 'Please enter the first number: '
ACCEPT num2 PROMPT 'Please enter the second number: '

BEGIN
	:v_result := (&num1/&num2)+&num2;
END;
/

PRINT v_result
