/**
 * @file    p2.2q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, sal SALARY, e1.deptno, DEPT_AVG
FROM emp e1, (SELECT deptno, AVG(sal) DEPT_AVG
							FROM emp
							GROUP BY deptno) b
WHERE e1.deptno=b.deptno
AND sal > (SELECT AVG(sal)
							FROM emp e2
							WHERE e1.deptno=e2.deptno)
ORDER BY sal;
