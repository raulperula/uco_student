/**
 * @file    p22q2.sql
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
	v_stars VARCHAR2(50) := '';
	
	CURSOR c1 IS
		SELECT sal
		FROM emp
		WHERE empno = &num_emp
		FOR UPDATE NOWAIT;
	aux c1%ROWTYPE;
BEGIN
	FOR aux IN c1 LOOP
		FOR i IN 1..aux.sal/100 LOOP
			v_stars := v_stars||'*';
		END LOOP;
		
		UPDATE emp
		SET stars = v_stars
		WHERE CURRENT OF c1;
	END LOOP;
END;
/

COMMIT;

SELECT empno, sal, stars
FROM emp
WHERE empno = 8000 OR empno = 7900 OR empno = 7844;
