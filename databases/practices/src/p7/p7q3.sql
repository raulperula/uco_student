/**
 * @file    p7q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT e.ename, e.hiredate, e.sal
FROM emp e, (SELECT sal, comm
							FROM emp
							WHERE ename='SCOTT') aux
WHERE e.sal=aux.sal AND NOT(e.ename='SCOTT');

/* Forma alternativa */

SELECT ename, hiredate, sal
FROM emp
WHERE (sal, NVL(comm, 0)) IN (SELECT sal, NVL(comm, 0)
															FROM emp
															WHERE ename='SCOTT')
AND NOT(ename='SCOTT');
