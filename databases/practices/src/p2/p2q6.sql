/**
 * @file    p2q6.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename "Employee", sal "Monthly Salary"
FROM emp
WHERE sal>1500 AND (deptno=10 OR deptno=30);
