/**
 * @file    p1.1q5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT deptno
FROM dept
MINUS
SELECT deptno
FROM emp
WHERE job='ANALYST';
