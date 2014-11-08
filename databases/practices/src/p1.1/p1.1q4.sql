/**
 * @file    p1.1q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT DISTINCT job, deptno
FROM emp
WHERE deptno = 10
UNION ALL
SELECT DISTINCT job, deptno
FROM emp
WHERE deptno = 30
UNION ALL
SELECT DISTINCT job, deptno
FROM emp
WHERE deptno = 20;
