/**
 * @file    r4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
ACCEPT n PROMPT 'Please insert the value of n: '

CREATE VIEW candidatos
AS SELECT e1.ename EMPLEADO1, e2.ename EMPLEADO2, e3.ename EMPLEADO3, e1.sal+e2.sal+e3.sal CAPITAL
FROM emp e1, emp e2, emp e3
WHERE e1.comm IS NOT NULL
AND e2.comm IS NOT NULL
AND e3.comm IS NOT NULL
AND e1.empno < e2.empno
AND e2.empno < e3.empno
AND &n > (SELECT COUNT(*)
					FROM emp e11, emp e21, emp e31
					WHERE e11.sal+e21.sal+e31.sal > e1.sal+e2.sal+e3.sal
					AND e11.comm IS NOT NULL
					AND e21.comm IS NOT NULL
					AND e31.comm IS NOT NULL
					AND e11.empno < e21.empno
					AND e21.empno < e31.empno)
ORDER BY capital DESC;
