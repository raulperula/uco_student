/**
 * @file    p4q6.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT e.ename "Employee", e.empno "Emp#", j.ename "Manager", j.empno "Mgr#"
FROM emp e, emp j
WHERE e.mgr=j.empno;
