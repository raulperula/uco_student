/**
 * @file    p22q1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

DELETE messages;

DECLARE
	CURSOR c1 IS
		SELECT DISTINCT deptno
		FROM dept;
	CURSOR c2(dept_no dept.deptno%TYPE) IS
		SELECT ename
		FROM emp
		WHERE deptno = dept_no;
	aux_deptno dept.deptno%TYPE;
	aux_ename emp.ename%TYPE;
BEGIN
	OPEN c1;
	
	LOOP
		FETCH c1 INTO aux_deptno;
		EXIT WHEN c1%NOTFOUND;
		
		OPEN c2(aux_deptno);
		
		LOOP
			FETCH c2 INTO aux_ename;
			EXIT WHEN c2%NOTFOUND;
			INSERT INTO messages(results)
			VALUES (aux_ename||' - Department '||TO_CHAR(aux_deptno));
		END LOOP;
		
		CLOSE c2;
	END LOOP;
	
	CLOSE c1;
END;
/

SELECT *
FROM messages;
