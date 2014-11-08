/**
 * @file    p7q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, job, sal
FROM emp
WHERE sal > (SELECT MAX(sal)
							FROM emp
							WHERE job='CLERK')
ORDER BY sal DESC;
