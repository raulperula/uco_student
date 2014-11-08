/**
 * @file    p6q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT empno, ename
FROM emp
WHERE sal>(SELECT AVG(sal)
						FROM emp)
ORDER BY sal;
