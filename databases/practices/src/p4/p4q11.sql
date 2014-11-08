/**
 * @file    p4q11.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT e.ename "Employee", e.hiredate "Emp Hiredate", j.ename "Manager", j.hiredate "Mgr Hiredate"
FROM emp e, emp j
WHERE e.mgr=j.empno AND e.hiredate<j.hiredate;
