/**
 * @file    p4q9.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

DESC salgrade

SELECT e.ename, e.job, d.dname, e.sal, s.grade
FROM emp e, dept d, salgrade s
WHERE e.deptno=d.deptno AND e.sal BETWEEN s.losal AND s.hisal;
