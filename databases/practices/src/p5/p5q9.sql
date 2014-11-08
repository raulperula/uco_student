/**
 * @file    p5q9.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT mgr, MIN(sal)
FROM emp
WHERE mgr IS NOT NULL
GROUP BY mgr
HAVING MIN(sal)>1000
ORDER BY MIN(sal) DESC;
