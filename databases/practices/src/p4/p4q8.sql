/**
 * @file    p4q8.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT DISTINCT e.deptno DEPARTMENT, e.ename EMPLOYEE, c.ename COLLEAGUE
FROM emp e, emp c
WHERE e.deptno=c.deptno AND NOT(e.ename=c.ename);
