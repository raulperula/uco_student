/**
 * @file    p5q12.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT job "Job",
	SUM(DECODE(deptno, 10, sal)) "Dept 10",
	SUM(DECODE(deptno, 20, sal)) "Dept 20",
	SUM(DECODE(deptno, 30, sal)) "Dept 30",
	SUM(DECODE(deptno, deptno, sal)) "Total"
FROM emp
GROUP BY job;
