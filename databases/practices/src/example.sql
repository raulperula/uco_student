/**
 * @file    example.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

VAR g_max_deptno NUMBER

DECLARE
	
BEGIN
	SELECT MAX(deptno)
		INTO :g_max_deptno
		FROM dept;
END;
/
ACCEPT v_max_deptno PROMPT 'Please enter the departament number: ';
ACCEPT v_name PROMPT 'Please enter the departament name: ';

DECLARE
	
BEGIN
	INSERT INTO dept(deptno, dname, loc)
		VALUES(&v_max_deptno, &v_name, NULL);
END;
/

SELECT deptno
	FROM dept
	WHERE deptno = 50;
