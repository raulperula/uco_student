/**
 * @file    p6q7.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT empno, ename, sal
FROM emp
WHERE deptno=ANY(SELECT deptno
									FROM emp
									WHERE ename LIKE '%T%')
AND sal>(SELECT AVG(sal)
					FROM emp);
