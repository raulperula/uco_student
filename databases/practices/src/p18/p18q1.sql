/**
 * @file    p18q1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

VARIABLE g_max_deptno NUMBER;

DECLARE
	deptnum dept.deptno%TYPE;
BEGIN
	SELECT MAX(deptno)
		INTO deptnum
	FROM dept;
	:g_max_deptno := deptnum;
END;
/

PRINT g_max_deptno

/* Otra forma de hacer el ejercicio */

SET serveroutput on

DECLARE
	g_max_deptno dept.deptno%TYPE;
BEGIN
	SELECT MAX(deptno)
		INTO g_max_deptno
	FROM dept;
	dbms_output.put_line(g_max_deptno);
END;
/
