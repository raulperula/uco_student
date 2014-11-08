/**
 * @file    p2q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, job, hiredate
FROM emp
WHERE hiredate BETWEEN '20/FEB/81' AND '01/MAY/81'
ORDER BY hiredate ASC;
