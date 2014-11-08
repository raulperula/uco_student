/**
 * @file    resume.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
 -- Resumen BBDD:

/* Consulta con diferentes opciones */

SELECT ename, grade
FROM emp, salgrade
WHERE sal BETWEEN losal AND hisal
OR empno IN(7902, 7566, 7788)
AND ename LIKE '_A%'
AND comm IS NOT NULL
ORDER BY grade DESC;

/* Funciones para cadenas */

LOWER('SQL Course') 	-> sql course
UPPER('SQL Course') 	-> SQL COURSE
INITCAP('SQL Course') -> Sql Course

CONCAT('Good', 'String') 	-> GoodString
SUBSTR('String', 1, 3) 		-> Str
LENGTH('String') 					-> 6
INSTR('String', 'r') 			-> 3
RPAD/LPAD(sal, 10, '*') 	-> ******5000

/* Funciones para numeros */

ROUND(45.926, 2) 	-> 45.93
TRUNC(45.926, 2) 	-> 45.92
MOD(1600, 300) 		-> 100

/* Ver la fecha del sistema */

SELECT sysdate
FROM dual;

/* Funciones de conversion de tipos */

TO_CHAR(hiredate, 'DD/MM/YYYY')
TO_CHAR(sal, '$99,999')
TO_NUMBER('El numero 4')
TO_DATE('14-22-2009', 'DD-MM-YYYY')

/* Funciones de grupo */

SELECT AVG(sal), MAX(sal), MIN(sal), SUM(sal)
FROM emp;

SELECT COUNT(empno)
FROM emp
WHERE deptno=20;

SELECT COUNT(DISTINCT deptno)
FROM emp;

SELECT deptno "Esta columna no es necesaria", AVG(sal)
FROM emp
GROUP BY deptno
HAVING AVG(sal)>2000
ORDER BY AVG(sal);

/* Subconsultas simples y multituplas */

SELECT ename, hiredate, sal, deptno
FROM emp
WHERE ename = (SELECT ename
								FROM emp
								WHERE sal=5000)
OR sal IN (SELECT MIN(sal)
						FROM emp
						GROUP BY deptno)
AND sal < ANY (SELECT sal
								FROM emp
								WHERE job='CLERK')
AND job <> 'CLERK'
OR sal > ALL (SELECT AVG(sal)
							FROM emp
							GROUP BY deptno);

/* Subconsulta multiple */
							
SELECT ename, deptno, sal, comm
FROM emp
WHERE (sal, NVL(comm, -1)) IN (SELECT sal, NVL(comm, -1)
																FROM emp
																WHERE deptno=30);
																
/* Subconsulta en el FROM */

SELECT a.ename, a.sal, a.deptno, b.salavg
FROM emp a, (SELECT deptno, AVG(sal) salavg
							FROM emp
							GROUP BY deptno) b
WHERE a.deptno=b.deptno
AND a.sal>b.salavg;

/* DML */

/* Lo que hay despues de dept es opcional, sin ello tambien funciona.
	 si se quiere insertar un valor nulo se hace con NULL*/
INSERT INTO dept(deptno, dname, loc)
VALUES (50, 'DEVELOPMENT', 'DETROIT');

INSERT INTO managers(id, salary, hiredate)
	SELECT empno, sal, hiredate
	FROM emp
	WHERE job='MANAGER';

UPDATE emp
SET deptno=20
WHERE empno=7788;

UPDATE emp
SET (job, deptno) = (SELECT job, deptno
											FROM emp
											WHERE empno=7788)
WHERE empno = (SELECT empno
								FROM emp
								WHERE ename='KING');

/* El FROM es opcional, en la clausula WHERE puede haber subconsultas */
DELETE FROM department
WHERE name='DEVELOPMENT';

/* Confirmar */
COMMIT;

/* Deshacer y poner punto de salvado */
ROLLBACK;

-- operacion
SAVEPOINT update_done;
-- operacion
ROLLBACK TO update_done;

/* Creacion de tablas */

CREATE TABLE depto
	(deptno NUMBER(2) NOT NULL,
	 dname VARCHAR2(14),
	 loc VARCHAR2(13) DEFAULT 'Sin loc',
	 CONSTRAINT dept_deptno_pk PRIMARY KEY (deptno),
	 CONSTRAINT dept_dname_uk UNIQUE (dname),
	 CONSTRAINT dept_deptno_ck CHECK (deptno BETWEEN 10 AND 99));

CREATE TABLE dept30
AS SELECT empno, ename, sal*12 ANNSAL, hiredate
		FROM emp
		WHERE deptno=30;

/* Añadir o modificar columnas de una tabla */

ALTER TABLE dept30
ADD (job VARCHAR2(9));

ALTER TABLE emp
ADD CONSTRAINT emp_deptno_fk FOREIGN KEY (deptno) REFERENCES dept(deptno);

ALTER TABLE emp
DROP CONSTRAINT emp_mgr_fk;

ALTER TABLE dept30
MODIFY (job VARCHAR2(15));

/* Eliminar una tabla */
DROP TABLE dept30;

/* Renombrar una tabla */
RENAME depto TO departmento;

/* Crear una vista, cuando se quiere que la vista solo sea de lectura
	 se pone WITH READ ONLY al final */
CREATE VIEW empvu10
AS SELECT empno ID, ename NOMBRE, job TRABAJO
		FROM emp
		WHERE deptno=10;

/* Crear o modificar una vista */

CREATE OR REPLACE VIEW empvu10
	(id, nombre, trabajo)
AS SELECT empno, ename, job
		FROM emp
		WHERE deptno=10;

/* Eliminar una vista */
DROP VIEW empvu10;

/* Creacion, utilizacion, modificacion y eliminacion de una secuencia */

CREATE SEQUENCE dept_deptno
	INCREMENT BY 10
	START WITH 10
	MAXVALUE 100
	MINVALUE 10
	NOCACHE
	NOCYCLE;

INSERT INTO dept
VALUES (dept_deptno.NEXTVAL, 'MARKETING', 'SAN DIEGO');

INSERT INTO emp (empno, deptno)
VALUES (1000, dept_deptno.CURRVAL);

ALTER SEQUENCE dept_deptno
	INCREMENT BY 1
	MAXVALUE 99999
	NOCACHE
	NOCYCLE;

DROP SEQUENCE dept_deptno;

/* Creacion y eliminacion de sinonimos */

CREATE SYNONYM d_sum
FOR dept_sum_vu;

DROP SYNONYM d_sum;

/* Estructura PL/SQL */

SET serveroutput ON

ACCEPT aux PROMPT 'Escribe 100: '

VARIABLE externa NUMBER
VARIABLE c_rows VARCHAR2(15)

DECLARE
	v_hiredate DATE NOT NULL := '02/04/2009';
	v_deptno dept.deptno%TYPE := 10;
	v_location VARCHAR2(13) := 'Atlanta';
	c_comm NUMBER := 1400;
	v_valid BOOLEAN := TRUE;
	v_sal emp.sal%TYPE;
	v_count NUMBER := 1;
	
	exc EXCEPTION;
BEGIN
	:externa := c_comm; -- igualacion de variable de sustitucion
	
	/* esto es un comentario
		 multilinea */

	--muestra de bloque PL dentro de otro
	DECLARE
		y NUMBER;
	BEGIN
		SELECT hiredate
			INTO v_hiredate
		FROM emp
		WHERE empno=7788;
	END;
	
	-- ejemplo de consulta
	SELECT sal
		INTO v_sal
	FROM emp
	WHERE empno=7788;
	
	IF SQL%NOTFOUND THEN
		RAISE exc;
	END IF;
	
	DELETE FROM messages;
	:c_rows := SQL%ROWCOUNT; -- cuenta el numero de tuplas afectadas por ultima vez
	
	-- sentencia IF	
	IF v_sal = 3000 THEN
		v_valid := FALSE;
	ELSIF v_sal < 3000 THEN
		v_valid := TRUE;
	ELSE
		v_valid := FALSE;
	END IF;
	
	-- bucle basico
	LOOP
		v_count := v_count+1;
		EXIT WHEN v_count = 10;
	END LOOP;
	
	-- bucle for
	FOR i IN 1..10 LOOP
		v_count := i;
		dbms_output.put_line(v_count); -- muestra los numeros del 1 al 10
	END LOOP;
	
	-- bucle while
	v_count := 1;
	WHILE v_count < &aux LOOP -- utilizacion de una variable pedida por pantalla
		v_count := v_count*10;
	END LOOP;
	
	-- muestra la frase
	dbms_output.put_line(c_comm||' la lluvia en sevilla '||4);
EXCEPTION
	WHEN exc THEN -- excepcion con condicion
		INSERT INTO messages
		VALUES('ninguna fila encontrada');
	WHEN NO_DATA_FOUND THEN -- excepcion en consulta sin resultados
		INSERT INTO messages
		VALUES('ninguna fila encontrada');
	WHEN OTHERS THEN -- otras excepciones
		INSERT INTO messages
		VALUES('otro error');
END; -- esto es un comentario de linea
/

PRINT externa
PRINT c_rows

/* Cursores */

DECLARE
	CURSOR c1 IS
		SELECT empno, ename
		FROM emp;
	emp_record c1%ROWTYPE;
	v_empno emp.empno%TYPE;
	v_ename emp.ename%TYPE;
	v BOOLEAN;
BEGIN
	-- comprobacion de que el cursor esta cerrado
	IF c1%ISOPEN THEN
		CLOSE c1;
	END IF;
	
	OPEN c1;
	
	-- busqueda en el cursor con variables
	FOR i IN 1..10 LOOP
		FETCH c1 INTO v_empno, v_ename;
		
		EXIT WHEN c1%NOTFOUND;
	END LOOP;
	
	-- busqueda en el cursor con estructuras
	FOR i IN 1..10 LOOP
		FETCH c1 INTO emp_record;
		
		EXIT WHEN c1%NOTFOUND;
	END LOOP;
	
	CLOSE c1;
	
	-- busqueda con FOR especial, no hace falta ni abrir ni cerrar el cursor
	FOR emp_record IN c1 LOOP
		IF emp_record.empno = 7788 THEN
			v := TRUE;
		ELSIF emp_record.ename = 'KING' THEN
			v := FALSE;
		END IF;
	END LOOP;
END;
/

/* Subconsultas correladas */

SELECT ename, sal
FROM emp o
WHERE 3 > (SELECT COUNT(empno)
						FROM emp i
						WHERE i.sal > o.sal)
AND sal IS NOT NULL;

SELECT ename
FROM emp o
WHERE EXISTS (SELECT ename
							FROM emp i
							WHERE o.deptno=i.deptno
							AND o.hiredate<i.hiredate
							AND o.sal<i.sal);
