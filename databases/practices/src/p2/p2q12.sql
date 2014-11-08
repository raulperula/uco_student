/**
 * @file    p2q12.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, job, sal
FROM emp
WHERE (job='CLERK' OR job='ANALYST') AND NOT(sal IN(1000, 3000, 5000));
