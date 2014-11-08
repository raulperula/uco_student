/**
 * @file    p4q12.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT RPAD(ename||CHR(9),ROUND(sal/100,0)+LENGTH(ename),'*') EMPLOYEE_AND_THEIR_SALARIES
FROM emp
ORDER BY sal DESC;
