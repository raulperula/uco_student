/**
 * @file    p18q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

VARIABLE g_result CHAR(50)

ACCEPT num_dept PROMPT 'Please enter the department number: '

BEGIN
	DELETE FROM dept
		WHERE deptno = &num_dept;
		:g_result := SQL%ROWCOUNT || ' row(s) deleted.';
END;
/
PRINT g_result

SELECT deptno, dname, loc
FROM dept
WHERE deptno = &num_dept;
