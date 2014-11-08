/**
 * @file    p3q7.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename||' earns '||TO_CHAR(sal, 'fm$9,999.00')||' monthly but wants '||TO_CHAR(3*sal, 'fm$99,999.00')||'.' "Dream Salary"
FROM emp;
