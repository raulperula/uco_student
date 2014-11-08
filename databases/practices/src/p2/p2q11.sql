/**
 * @file    p2q11.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename
FROM emp
WHERE ename LIKE '%LL%' AND (deptno=30 OR mgr=7782);
