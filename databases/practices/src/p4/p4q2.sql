/**
 * @file    p4q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT DISTINCT e.job, d.loc
FROM emp e, dept d
WHERE e.deptno=d.deptno AND e.deptno=30;
