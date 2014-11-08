/**
 * @file    p2q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, sal
FROM emp
WHERE NOT(sal BETWEEN 1500 AND 2850);
