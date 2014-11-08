/**
 * @file    p5q5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT job, MAX(sal) "Maximum", MIN(sal) "Minimum", SUM(sal) "Sum", ROUND(AVG(sal),0) "Average"
FROM emp
GROUP BY job;