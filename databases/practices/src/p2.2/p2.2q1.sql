/**
 * @file    p2.2q1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, sal
FROM emp e1
WHERE 3 > (SELECT COUNT(empno)
						FROM emp e2
						WHERE e2.sal>e1.sal);
