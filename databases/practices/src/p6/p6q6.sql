/**
 * @file    p6q6.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT deptno, ename, job
FROM emp
WHERE deptno=(SELECT deptno
							FROM dept
							WHERE dname='SALES');
