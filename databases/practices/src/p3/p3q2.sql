/**
 * @file    p3q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT empno, ename, sal, ROUND(sal+sal*0.15) "New Salary"
FROM emp;
