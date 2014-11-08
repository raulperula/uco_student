/**
 * @file    p7q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT aux.ename, aux.dname, aux.sal
FROM (SELECT e.ename, d.dname, e.sal
			FROM emp e, dept d
			WHERE e.deptno=d.deptno AND d.loc='DALLAS') aux;
