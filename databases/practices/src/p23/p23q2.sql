/**
 * @file    p23q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

ACCEPT d_no PROMPT 'Please enter the new department number: '
ACCEPT d_loc PROMPT 'Please enter the new department location: '

DECLARE
	v_deptno dept.deptno%TYPE;
	v_dname dept.dname%TYPE;
	v_loc dept.loc%TYPE;
BEGIN
	UPDATE dept
		SET loc = '&d_loc'
		WHERE deptno = &d_no;
	SELECT deptno, dname, loc
	INTO v_deptno, v_dname, v_loc
	FROM dept
	WHERE deptno = &d_no;
EXCEPTION
	WHEN NO_DATA_FOUND THEN
		dbms_output.put_line('The department does not exist');
END;
/
