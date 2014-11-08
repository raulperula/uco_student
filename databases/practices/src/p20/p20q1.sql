/**
 * @file    p20q1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

ACCEPT emp_no PROMPT 'Please enter the employee number: '

DECLARE
	TYPE ename_table_type IS TABLE OF emp.ename%TYPE
		INDEX BY BINARY_INTEGER;
	ename_table ename_table_type;
	
	TYPE sal_table_type IS TABLE OF emp.sal%TYPE
		INDEX BY BINARY_INTEGER;
	sal_table sal_table_type;
BEGIN
	SELECT ename, sal
		INTO ename_table(1), sal_table(1)
	FROM emp
	WHERE empno = &emp_no;
	
	INSERT INTO top_dogs (name, salary)
	VALUES (ename_table(1), sal_table(1));
END;
/

SELECT *
FROM top_dogs;

DELETE top_dogs;
