/**
 * @file    p18q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

ACCEPT d_no PROMPT 'Please enter the department number: '
ACCEPT d_loc PROMPT 'Please enter the department location: '

BEGIN
	UPDATE dept
		SET loc = '&d_loc'
		WHERE deptno = &d_no;
END;
/

SELECT deptno, dname, loc
FROM dept
WHERE deptno=&d_no;
