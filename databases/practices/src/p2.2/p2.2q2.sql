/**
 * @file    p2.2q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename
FROM emp e
WHERE NOT EXISTS (SELECT DISTINCT e.ename
									FROM emp m
									WHERE m.mgr=e.empno);
