/**
 * @file    p1.1q6.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT job
FROM emp
WHERE deptno = 10 OR deptno = 20
MINUS
(SELECT job
	FROM emp
	WHERE deptno = 10
	INTERSECT
SELECT job
	FROM emp
	WHERE deptno = 20);
