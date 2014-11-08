/**
 * @file    p19q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

ACCEPT v_empno PROMPT 'Please enter de employee number: '

DECLARE
	num_emp emp.empno%TYPE := &v_empno;
	cond_sal emp.sal%TYPE;
BEGIN
	SELECT sal
		INTO cond_sal
		FROM emp
		WHERE num_emp = empno;
	
	IF cond_sal < 1000 THEN
		UPDATE emp
			SET comm = sal*0.10
			WHERE empno = &v_empno;
	ELSIF cond_sal > 1000 AND cond_sal < 1500 THEN
		UPDATE emp
			SET comm = sal*0.15
			WHERE empno = &v_empno;
	ELSIF cond_sal > 1500 THEN
		UPDATE emp
			SET comm = sal*0.20
			WHERE empno = &v_empno;
	ELSIF cond_sal = NULL THEN
		UPDATE emp
			SET comm = 0
			WHERE empno = &v_empno;
	END IF;
END;
/
