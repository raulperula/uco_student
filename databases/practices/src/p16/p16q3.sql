/**
 * @file    p16q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

VARIABLE g_message VARCHAR2(25)

DECLARE
	aux VARCHAR2(25) := 'My PL/SQL Block Works';
BEGIN
	:g_message := aux;
END;
/

PRINT g_message
