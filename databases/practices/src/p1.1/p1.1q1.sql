/**
 * @file    p1.1q1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT deptno, dname
FROM dept
MINUS
SELECT emp.deptno, dept.dname
FROM emp, dept
WHERE emp.deptno = dept.deptno;
