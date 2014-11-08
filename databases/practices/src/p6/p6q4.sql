/**
 * @file    p6q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, deptno, job
FROM emp
WHERE deptno=(SELECT deptno
							FROM dept
							WHERE loc='DALLAS');
