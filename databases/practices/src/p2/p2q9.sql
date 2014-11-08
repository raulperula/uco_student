/**
 * @file    p2q9.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, sal, comm
FROM emp
WHERE NOT comm IS NULL
ORDER BY sal DESC, comm;
