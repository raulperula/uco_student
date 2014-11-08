/**
 * @file    p5q7.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT COUNT(DISTINCT j.ename) "Number of Managers"
FROM emp e, emp j
WHERE e.mgr=j.empno;
