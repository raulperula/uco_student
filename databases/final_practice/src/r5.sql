/**
 * @file    r5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
DELETE messages;

ACCEPT emp_job PROMPT 'Please insert the job: '

DECLARE
	CURSOR c1 IS
		SELECT ename, loc
		FROM emp e, dept d
		WHERE job = '&emp_job'
		AND e.deptno=d.deptno;
	aux c1%ROWTYPE;
	v_ename emp.ename%TYPE;
	v_loc dept.loc%TYPE;
BEGIN
	SELECT ename, loc
	INTO v_ename, v_loc
	FROM emp e, dept d
	WHERE job = '&emp_job'
	AND e.deptno=d.deptno;
	
	FOR aux IN c1 LOOP
		INSERT INTO messages (results)
		VALUES ('Ename: '||aux.ename||' Loc: '||aux.loc);
	END LOOP;
EXCEPTION
	WHEN NO_DATA_FOUND THEN
		INSERT INTO messages (results)
		VALUES ('No employees with a job of &emp_job');
END;
/

SELECT *
FROM messages;
