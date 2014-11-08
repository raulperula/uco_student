/**
 * @file    p19q5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

ACCEPT num_emp PROMPT 'Please enter the employee number: '

DECLARE
	v_stars VARCHAR2(50) := ' ';
	v_sal		NUMBER := 0;
BEGIN
	SELECT sal
		INTO v_sal
	FROM emp
	WHERE empno = &num_emp;
	
	FOR i IN 1..v_sal/100 LOOP
		v_stars := v_stars||'*';
	END LOOP;
	
	UPDATE emp
		SET stars = v_stars
		WHERE empno = &num_emp;
END;
/

COMMIT;

SELECT empno, sal, stars
FROM emp
WHERE empno = 8000 OR empno = 7934;
