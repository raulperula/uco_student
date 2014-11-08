/**
 * @file    p3q10.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, hiredate, TO_CHAR(hiredate, 'DAY') DAY
FROM emp
ORDER BY DAY;
