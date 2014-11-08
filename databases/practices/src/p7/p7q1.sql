/**
 * @file    p7q1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, deptno, sal
FROM emp
WHERE (deptno, sal) IN (SELECT deptno, sal
												FROM emp
												WHERE comm IS NOT NULL);
