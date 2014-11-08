/**
 * @file    p23q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
ACCEPT e_sal PROMPT 'Please insert the salary: '

DECLARE
	CURSOR c1 IS
		SELECT sal
		FROM emp
		WHERE sal BETWEEN &e_sal-100 AND &e_sal+100;
	no_emps EXCEPTION;
	emps EXCEPTION;
	v_sal emp.sal%TYPE;
	v_cont NUMBER(6) := 0;
BEGIN
	OPEN c1;

	LOOP
		FETCH c1 INTO v_sal;
		EXIT WHEN c1%NOTFOUND;
		v_cont := v_cont + 1;
	END LOOP;

	CLOSE c1;

	IF v_cont = 0 THEN
		RAISE no_emps;
	ELSE
		RAISE emps;
	END IF;
EXCEPTION
	WHEN emps THEN
		dbms_output.put_line ('There are ' || v_cont ||
		' employes with a salary between ' || (&e_sal-100) ||
		' and ' || (&e_sal+100) );
	WHEN no_emps THEN
		dbms_output.put_line('There are not employes with a salary between '
		|| (&e_sal-100) || ' and ' || (&e_sal+100) );
	WHEN OTHERS THEN
		dbms_output.put_line ('Some other error occurred');
END;
/
