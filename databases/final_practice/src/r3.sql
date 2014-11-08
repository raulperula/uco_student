/**
 * @file    r3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
SELECT grade, ename, sal
FROM emp o, dept d, salgrade s
WHERE o.deptno=d.deptno
AND loc='DALLAS'
AND sal BETWEEN losal AND hisal
AND 1 = (SELECT COUNT(DISTINCT i.sal)
           FROM emp i, dept de
           WHERE i.sal > o.sal
           AND i.deptno=de.deptno
           AND loc='DALLAS');
