/**
 * @file    r1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
CREATE VIEW vmanloc
AS SELECT ename, aux.empno, num_sub, loc, avggrade
FROM emp e, dept d, salgrade s, (SELECT j.empno, COUNT(e.empno) NUM_SUB, AVG(grade) AVGGRADE
																	FROM emp e, emp j, salgrade
																	WHERE j.empno=e.mgr
																	AND e.sal BETWEEN losal AND hisal
																	GROUP BY j.empno) aux
WHERE e.deptno=d.deptno
AND e.empno=aux.empno
AND e.sal BETWEEN losal AND hisal
AND grade > avggrade
AND avggrade > (SELECT AVG(grade)
								FROM emp a, dept b, salgrade
								WHERE a.deptno=b.deptno
								AND sal BETWEEN losal AND hisal
								AND b.loc = d.loc);
