/**
 * @file    p3q6.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, ROUND(MONTHS_BETWEEN(sysdate, hiredate), 0) MONTHS_WORKED
FROM emp
ORDER BY MONTHS_WORKED;
