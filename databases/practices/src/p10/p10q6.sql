/**
 * @file    p10q6.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

CREATE TABLE employee2
AS
	SELECT empno ID, ename LAST_NAME, deptno DEPT_ID
	FROM emp;
