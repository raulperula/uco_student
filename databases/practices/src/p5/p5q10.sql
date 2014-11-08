/**
 * @file    p5q10.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT dname, loc, COUNT(*) "Number of People", ROUND(AVG(sal),2) "Salary"
FROM emp, dept
WHERE emp.deptno=dept.deptno
GROUP BY dname, loc;
