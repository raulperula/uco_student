/**
 * @file    p2q5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, deptno
FROM emp
WHERE deptno=10 OR deptno=30
ORDER BY ename;
