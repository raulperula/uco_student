/**
 * @file    p21q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

DELETE top_dogs;
ACCEPT n PROMPT 'Please enter the number of top money makers: '

DECLARE
	CURSOR c1 IS
		SELECT ename, sal
		FROM emp e1
		WHERE &n >= (SELECT COUNT(*)
								FROM emp e2
								WHERE NVL(e2.sal,0) > NVL(e1.sal,0))
								ORDER BY e1.sal DESC;
	aux c1%ROWTYPE;
BEGIN
	OPEN c1;

	LOOP
		FETCH c1 INTO aux;
		EXIT WHEN c1%NOTFOUND OR &n = 0;
		INSERT INTO top_dogs
		VALUES (aux.ename, aux.sal);
	END LOOP;

	CLOSE c1;
END;
/

SELECT *
FROM top_dogs;
