/**
 * @file    p4q10.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT e.ename, e.hiredate
FROM emp e, emp b
WHERE b.ename='BLAKE' AND e.hiredate<b.hiredate;
