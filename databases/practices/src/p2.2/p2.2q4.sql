/**
 * @file    p2.2q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename
FROM emp e1
WHERE sal < (SELECT AVG(sal)/2
							FROM emp e2
							WHERE e1.deptno=e2.deptno);
