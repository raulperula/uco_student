/**
 * @file    p18q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

ACCEPT dept_no PROMPT 'Please enter the department number: '
ACCEPT d_name PROMPT 'Please enter the department name: '

BEGIN
	INSERT INTO dept(deptno, dname)
		VALUES (&dept_no, '&d_name');
END;
/

SELECT deptno, dname, loc
FROM dept
WHERE deptno=&dept_no;
