/**
 * @file    p12q5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

CREATE VIEW dept20
AS SELECT empno EMPLOYEE_ID, ename EMPLOYEE, deptno DEPARTMENT_ID
FROM emp
WHERE deptno=20
WITH CHECK OPTION CONSTRAINT dept20_ck;
