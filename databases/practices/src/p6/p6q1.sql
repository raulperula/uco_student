/**
 * @file    p6q1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, hiredate
FROM emp
WHERE deptno=(SELECT deptno
							FROM emp
							WHERE ename='BLAKE')
			AND NOT(ename='BLAKE');
