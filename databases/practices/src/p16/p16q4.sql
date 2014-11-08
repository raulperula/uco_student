/**
 * @file    p16q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

VARIABLE v_char	CHAR(16)
VARIABLE v_num	NUMBER

DECLARE
	vchar	VARCHAR2(16) := '42 is the answer';
	vnum	NUMBER := TO_NUMBER(SUBSTR(vchar, 1, 2));
BEGIN
	:v_char := vchar;
	:v_num := vnum;
END;
/

PRINT v_char
PRINT v_num
