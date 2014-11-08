/**
 * @file    p23q1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

DELETE messages;

ACCEPT e_sal PROMPT 'Please insert the salary: '

DECLARE
	v_ename emp.ename%TYPE := NULL;
	data_found EXCEPTION;
BEGIN
	SELECT ename
	INTO v_ename
	FROM emp
	WHERE sal = &e_sal;
	RAISE data_found;
EXCEPTION
	WHEN TOO_MANY_ROWS THEN
		INSERT INTO messages (results)
		VALUES ('More than one employee with a salary of &e_sal');
	WHEN NO_DATA_FOUND THEN
		INSERT INTO messages (results)
		VALUES ('No employees with a salary of &e_sal');
	WHEN data_found THEN
		INSERT INTO messages (results)
		VALUES (v_ename || ' with salary: ' || &e_sal);
	WHEN OTHERS THEN
		INSERT INTO messages (results)
		VALUES ('Some other error occurred');
END;
/

SELECT *
FROM messages;
