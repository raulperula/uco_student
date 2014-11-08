/**
 * @file    p6q5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, sal
FROM emp
WHERE mgr=(SELECT empno
						FROM emp
						WHERE ename='KING');
