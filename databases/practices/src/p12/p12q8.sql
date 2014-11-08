/**
 * @file    p12q8.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

CREATE VIEW salary_vu
AS SELECT ename "Employee", deptno "Department", sal "Salary", grade "Grade"
FROM emp, salgrade
WHERE sal BETWEEN losal AND hisal;
