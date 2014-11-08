/**
 * @file    p4q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT e.ename, d.dname
FROM emp e, dept d
WHERE e.deptno=d.deptno AND e.ename LIKE '%A%';
