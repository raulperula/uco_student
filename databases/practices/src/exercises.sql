/**
 * @file    exercises.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

-- EJEMPLOS DE LOS TEMAS

--TEMA 1.1--

1- Mostrar el nombre e id de los empleados y el nombre de sus jefes, si un empleado no tiene jefe 
mostrar el mensaje "No tiene jefe"

	select e.empno, e.ename, nvl(j.ename, 'No tiene jefe')
		from emp e, emp j
  	where e.mgr=j.empno(+);

--TEMA 5--

1- Mostrar la media salarial de managers y clerks de los departamentos cuyo salario maximo no supere los 2000$

	select deptno, avg(nvl(sal,0)) "Media salario"
		from emp
		where job in('MANAGER', 'CLERK')
		group by deptno
		having max(sal) <= 2000;
		
2- Mostrar el nombre de cada empleado y de su jefe siempre que el rango salarial del jefe sea uno mas que el
rango del empleado

	select e.ename EMPLEADO, se.grade, j.ename JEFE, sj.grade
		from emp e, emp j, salgrade se, salgrade sj
		where e.mgr=j.empno
		and e.sal between se.losal and se.hisal
		and j.sal between sj.losal and sj.hisal
		and sj.grade=se.grade+1;

3- Crear una consulta que muestre tabularmente para cada deptno el nº de empleados que entraron en los años
 80, 81, 82, 83, asi como el nivel salarial medio del deptno(Mostrar entre parentesis "nombre-dept(localizacion)")

	select d.dname || '(' || d.loc || ')' DEPARTAMENTO,
	 sum(decode(to_char(e.hiredate, 'YY'), '80', 1, 0)) "1980",
	 sum(decode(to_char(e.hiredate, 'YY'), '81', 1, 0)) "1981",
	 sum(decode(to_char(e.hiredate, 'YY'), '82', 1, 0)) "1982",
	 sum(decode(to_char(e.hiredate, 'YY'), '83', 1, 0)) "1983",
	 avg(s.grade) "NIVEL SALARIAL MEDIO"
		from dept d, salgrade s, emp e
		where d.deptno=e.deptno
		and e.sal between s.losal and s.hisal
		group by dname || '(' || loc || ')';
	
--TEMA 6--

1- Seleccionar el nombre de los empleados que tengan el mismo empleo que 7369 y cuyo manager este en los departamentos
10 o 20.

	select ename
		from emp
		where job = (select job
									from emp
									where empno=7369)
		and mgr in(select empno
								from emp
								where deptno in(10,20));
								
2- Seleccionar el nombre de empleado y el de su manager, si lo tuviera, de todos aquellos empleados que cobren
un salario mayor de la media de la empresa.

	select e.ename EMPLEADO, m.ename JEFE
		from emp e, emp m
		where e.mgr=m.empno(+)
		and e.sal > (select avg(nvl(sal, 0))
								from emp);

3- Mostrar el nombre e id de los empleados con subordinados (jefes), asi como el numero de empleados que
dirige y el grado salarial medio de sus subordinados, siempre que la media de lo que cobran estos subordinados
sea, al menos, la media de lo que cobran en el deptno de ventas (SALES).

	select j.ename NOMBRE, j.empno ID,
	 count(s.empno) "NUMERO EMPLEADOS", 
	 avg(nvl(se.grade, 0)) "GRADO SALARIAL MEDIO"
		from emp s, emp j, salgrade se
		where j.empno=s.mgr
		and nvl(s.sal,700) between se.losal and se.hisal
		group by j.ename, j.empno
		having avg(s.sal) >= (select avg(nvl(sal,0))
														from emp, dept
														where emp.deptno=dept.deptno
														and upper(dname)='SALES');

--TEMA 7--

1- Mostrar el nombre, id, y rango salarial de aquellos empleados que superen la media salarial de su departamento.

	select e.ename NOMBRE, e.empno ID, s.grade "RANGO SALARIAL"
		from emp e, salgrade s, (select deptno, avg(nvl(sal,0)) mediasal
															from emp
															group by deptno)deptavg
		where e.sal between s.losal and s.hisal
		and e.sal > deptavg.mediasal
		and e.deptno=deptavg.deptno;
		
--TEMA 2.2--

1- Cual es el cargo que mas se repite entre los empleados?

	select job, count(*)
		from emp
		group by job
		having count(*)>=ALL (select count(*)
														from emp
														group by job);

2- Mostrar empleados que cobran mas que su jefe.

	select e.ename
		from emp e
		where e.sal>(select j.sal
									from emp j
									where j.empno=e.mgr);

3- Mostrar los empleados que tengan manager.

	select e.ename
		from emp e
		where exists (select *
									from emp j
									where j.empno=e.mgr);

4- Mostrar el nombre, id, y rango salarial de aquellos empleados que superan la media salarial de su dept.

	select e.empno, e.ename, s.grade
		from emp e, salgrade s
		where e.sal between s.losal and s.hisal
		and e.sal>(select avg(nvl(j.sal,0))
									from emp j
									where e.deptno=j.deptno);

5- Seleccionar los empleados que tienen el minimo sueldo de su dept.

	/*CON FROM*/
	select e.ename
		from emp e, (select deptno, min(sal) minimo
									from emp
									group by deptno) minsueldo
		where e.deptno=minsueldo.deptno
		and e.sal=minsueldo.minimo;
		
	/*CON CORRELADA*/
	select e.ename
		from emp e
		where e.sal=(select min(sal)
									from emp j
									where e.deptno=j.deptno);

	/*MULTIPLE COLUMNAS*/
	select e.ename
		from emp e
		where (e.deptno, e.sal) IN (select j.deptno, min(j.sal)
																	from emp j
																	group by j.deptno);

--TEMA 9--

1- 	describe salgrade
		
		insert into salgrade
		values (7,20000,50000);
		
		select *
			from salgrade;

2- 	describe emp

		insert into emp (empno, ename, hiredate, deptno)
		values (9050,'JUAN',sysdate,20);
		
		insert into emp (empno, ename, hiredate, deptno, comm)
		values (9051,'JUANJO',to_date('15-03-08','DD-MM-YY'),20,NULL);
		
		insert into emp (empno, ename, deptno)
		values (&id,&nombre,&departamento);
		
		accept nombre prompt 'Indique el nombre: '
		
		select *
			from emp;

3- 	update emp
			set sal = 1000
			where ename = 'DOE';

--TEMA 10--

1- create table empleado
		( nombre varchar2(50),
			id number(5),
			jefe varchar2(50),
			fecha date default sysdate);
			
2- select *
	from user_tables;
	/*devuelve las tablas creadas por el usuario*/
	
3- create table pringados (id, nombre, salario, jefe)
		as (select empno, ename, sal*12 SALARIO, mgr
					from emp
					where mgr is not null);
	
	describe pringados
	
4- alter table empleado
		modify (jefe number(5));

--TEMA 11--

1- create table member
		( member_id number(10),
			last_name varchar2(25) not null,
			first_name varchar2(25),
			address varchar2(100),
			city varchar2(30),
			phone varchar2(15),
			join_date date default sysdate not null,
			constraint member_member_id_pk primary key(member_id));
			
2- create table title
		( title_id number(10),
			title varchar2(60) not null,
			description varchar2(400) not null,
			rating varchar2(4),
			category varchar2(20),
			release_date date,
			constraint title_title_id_pk primary key(title_id),
			constraint title_rating_ck check(rating in('G','PG','R','NC17','NR')),
			constraint title_category_ck check(category in('DRAMA','COMEDY','ACTION','CHILD','SCIFI','DOCUMENTARY')));

3- create table title_copy
		( copy_id number(10),
			title_id number(10),
			status varchar2(15) not null,
			constraint title_copy_copy_id_title_id_pk primary key(copy_id,title_id),
			constraint title_copy_title_id_fk foreign key(title_id) references title(title_id),
			constraint title_copy_status_ck check(status in('AVAILABLE','DESTROYED','RENTED','RESERVED')));

4- create table reservation
		( res_date date,
			member_id number(10),
			title_id number(10),
			constraint reservation_id_pk primary key(res_date,member_id,title_id),
			constraint reservation_member_id_fk foreign key(member_id) references member(member_id),
			constraint reservation_title_id_fk foreign key(title_id) references title(title_id));
			
--TEMA 12--

1- Indicar el nombre del mejor cliente (el que mas alquileres ha realizado)

	select first_name||' '||last_name "El mejor cliente"
		from member m, rental r
		where m.member_id = r.member_id
		group by first_name, last_name
		having count(*) = (select max(count(*))
												from rental
												group by(member_id));

--EXAMEN JUNIO--

1- Mostrar para cada depto (nombre) la cantidad de empleados para los que el nº de años
	 completos de permanencia en la empresa hasta la fecha actual es inferior a la media
	 del depto. Deben existir, al menos 2 empleados que cumplan este requisito para mostrar el depto.
	 
	 /*MAL*/
	 SELECT d.dname, COUNT(e.empno) NUM_EMP
	 	FROM emp e, dept d, (SELECT ename, (TO_NUMBER(TO_CHAR(sysdate, 'YYYY')))-(TO_NUMBER(TO_CHAR(hiredate, 'YYYY'))) NUM_AN
													FROM emp) tabla_an
		WHERE e.deptno = d.deptno
		AND tabla_an.num_an < (SELECT AVG((TO_NUMBER(TO_CHAR(sysdate, 'YYYY')))-(TO_NUMBER(TO_CHAR(e.hiredate, 'YYYY'))))
														FROM emp e, dept d
														WHERE e.deptno = d.deptno
														GROUP BY e.deptno)
		GROUP BY d.dname;
		
		/*SOLUCION*/
		SELECT d.dname, COUNT(e.empno)
			FROM dept d, emp e
			WHERE d.deptno = e.deptno
				AND TRUNC((SYSDATE-e.hiredate)/365) < (SELECT AVG(TRUNC((SYSDATE-i.hiredate)/365))
																								FROM emp i
																								WHERE i.deptno = e.deptno)
			GROUP BY d.dname
			HAVING COUNT(e.empno) >= 2;
	 	
2- Mostrar el nombre de los empleados que tengan mas subordinados que su jefe.

	/*MAL*/
	SELECT e.ename
		FROM emp e, emp j
		WHERE e.mgr = j.empno
		AND  >ALL (SELECT count(em.ename)
								FROM emp em, emp je
								WHERE em.mgr = je.empno
								AND je.empno = j.empno);

	/*SOLUCION*/
	SELECT e.ename
		FROM emp e, emp j, (SELECT j.empno, COUNT(s.empno) nsub
													FROM emp s, emp j
													WHERE s.mgr = j.empno
													GROUP BY j.empno) sube,
												(SELECT j.empno, COUNT(s.empno) nsub
													FROM emp s, emp j
													WHERE s.mgr = j.empno
													GROUP BY j.empno) subj
		WHERE e.mgr = j.empno
			AND e.empno = sube.empno
			AND j.empno = subj.empno
			AND sube.nsub > subj.nsub;
			
--TEMA 16--

1- Crear una variable
	/*'v_' para las variables*/
	/*'c_' para las constantes*/
	/*'g_' para variables globales*/

VARIABLE g_nombre VARCHAR2(20); /*variable que no es de plSQL sino de SQL-PLUS*/

DECLARE
	
	v_sal NUMBER(7,2) NOT_NULL DEFAULT 7000; /*tambien se puede poner v_sal NUMBER(7,2) := 7000*/
	v_nombre VARCHAR2(20) DEFAULT "Pepe";
	v_fecha DATE := TO_DATE('08-05-08', 'DD-MM-YY'); 
	
	c_inc CONSTANT NUMBER(4,2) DEFAULT 0.3;
	
	v_sal emp.sal%TYPE
	
BEGIN
	/*aqui se utilizan las variables*/
	
EXCEPTION

END;
/ 			/*esto es para ejecutar*/

2- Declarar una variable, asignarle valor inicial 1000 y despues hacer que valga la mitad. Mostrarla por pantalla

SET serveroutput on /*Activa la opcion para que se pueda ver por pantalla, esto no es PLSQL, es lenguaje de SQLPLUS*/

DECLARE
		
	v_variable NUMBER(20) := 1000;
		
BEGIN
		
	v_variable := v_variable / 2;
	dbms_output.put_line(v_variable); /*Muestra por pantalla el valor de la variable*/
		
END;
/

SET serveroutput on;

VAR varSQLP NUMBER /*Creamos una variable en SQLPLUS*/

DECLARE
		
	v_variable NUMBER(20) := 1000;
		
BEGIN
		
	v_variable := v_variable / 2;
	:varSQLP := v_variable; /*Igualamos las variables*/
		
END;
/

PRINT varSQLP /*Imprimimos la variable por pantalla*/

--TEMA 17--

1- 

DECLARE
	v_sal			NUMBER(7,2) := 60000;
	v_comm		NUMBER(7,2) := v_sal / 20;
	v_message	VARCHAR2(255) := ' elegible for commission';
BEGIN
	DECLARE
		v_sal					NUMBER(7,2) := 50000;
		v_comm				NUMBER(7,2) := 0;
		v_total_comp	NUMBER(7,2) := v_sal + v_comm;
	BEGIN
		v_message := 'CLERK not'||v_message;
		dbms_output.put_line(v_sal);
		dbms_output.put_line(v_message);
	END;
	v_message := 'SALESMAN'||v_message;
	dbms_output.put_line(v_sal);
	dbms_output.put_line(v_message);
END;
/

--TEMA 18--

1- Media salarial de los empleados, numero de empleados, multiplicamos las variables para
obtener el dinero que gasta la empresa y que muestre por pantalla 'La empresa gasta...'

DECLARE
	v_media		NUMBER;
	v_cont		NUMBER;
BEGIN
	SELECT AVG(sal)
		INTO v_media
		FROM emp;
	SELECT COUNT(empno)
		INTO v_cont
		FROM emp;
	dbms_output.put_line('La empresa gasta '||v_media*v_cont);
END;
/

--EJERCICIO--

1- Mostrar el departamento con mayor salario medio

	SELECT deptno
		FROM emp
		GROUP BY deptno
		HAVING AVG(sal) = (SELECT MAX(AVG(sal))
												FROM emp
												GROUP BY deptno);

--TEMA 19--

1- Dado el nombre de un socio, mostrar el identificador y el numero de peliculas que ha alquilado (si existe).

set verify off;
set serveroutput on;

ACCEPT s_name PROMPT 'Introduzca el nombre de un socio: '

DECLARE
	s_id		member.member_id%TYPE;
	s_num		NUMBER;
BEGIN
	SELECT COUNT(*)
		INTO s_num
		FROM member
		WHERE LOWER(first_name||' '||last_name) LIKE ('%'||LOWER('&s_name')||'%');
		
		IF (s_num = 0) THEN
			dbms_output.put_line('No hay usuarios de nombre &s_name');
		ELSIF (s_num = 1) THEN
			SELECT COUNT(*), rental.member_id
				INTO s_num, s_id
				FROM rental, member
				WHERE rental.member_id = member.member_id
				AND LOWER(member.first_name||' '||member.last_name) LIKE ('%'||LOWER('&s_name')||'%')
				GROUP BY rental.member_id;
			
			dbms_output.put_line('El socio &s_name tiene el id '||s_id||' y ha alquilado '||s_num||' peliculas');
		ELSE
			dbms_output.put_line('Mas de un socio cumple con el nombre &s_name');
		END IF;
END;
/

--TEMA 21--

1- Desarrollar un procedimiento para alquilar una pelicula dado el id del socio y el id de titulo. Debe ser un socio activo
	 y debe existir copia disponible.

set verify off;
set serveroutput on;

ACCEPT s_id PROMPT 'Inserte el id de un socio: ';
ACCEPT s_titulo PROMPT 'Inserte el titulo de una pelicula: ';

DECLARE

BEGIN

END;
/

dbms_output.put_line();

--TEMA 22--

1- 

DECLARE
CURSOR c (v_nombre VARCHAR2, --No hace falta especificar la cardinalidad
					v_sal NUMBER) IS
		SELECT *
			FROM emp
			WHERE sal > v_sal
			AND	ename <> v_nombre;
BEGIN

END
/

2-

CURSOR c (v_grade NUMBER, v_sal NUMBER) IS
	SELECT ename, sal
		FROM emp, salgrade
		WHERE sal > v_sal
		AND grade = v_grade
		AND sal BETWEEN hisal AND losal
	FOR UPDATE OF ename NOWAIT;

3-

FOR rec IN c(2, 2000) LOOP
	UPDATE emp
		SET sal = sal*1.05;
		WHERE CURRECT OF c; --Con esto solo actualizamos la tupla que tenemos en el momento
END_LOOP;

--TEMA 23--

1- 

DECLARE
	mi_excepcion EXCEPTION;
BEGIN

EXCEPTION
	WHEN TO_MANY_ROWS THEN
		dbms_output.put_line('Demasiados registros');
	WHEN NOT_DATA_FOUND THEN
		CLOSE c;
		ROLLBACK;
	WHEN OTHERS THEN --Solo puede aparecer una vez
		... error ...
END;
/

2-

ACCEPT titulo_id PROMPT 'Deme un titulo: ';

DECLARE
	e_copia_disponible EXCEPTION;
	v_aux NUMBER;
BEGIN
	SELECT COUNT(*)
		INTO v_aux
		FROM title_copy
		WHERE title_id = titulo_id
		AND status = 'AVAILABLE';
	IF (v_aux = 0) THEN
		RAISE e_copia_disponible;
	END_IF;
EXCEPTION
	WHEN e_copia_disponible THEN
	...;
END;
/

3- Utilizando al menos 1 cursor parametrizado y 1 implicito desarrollar un bloque
PL-SQL que muestre para el deptno con la media de antigüedad de sus empleados
mas elevada de la empresa el listado de aquellos empleados que cobran mas que su jefe.

set verify off;
set serveroutput on;

DECLARE
	CURSOR c1 (v_dept NUMBER) IS
		SELECT *
			FROM emp
			WHERE deptno = v_dept;
	
	CURSOR c2 IS
		SELECT deptno
			FROM emp
			GROUP BY deptno
			HAVING AVG(SYSDATE-hiredate) = (SELECT MAX(AVG(SYSDATE-hiredate))
																				FROM emp
																				GROUP BY deptno);
	
	v_d emp.deptno%TYPE; --El tipo es el mismo del que se va a recoger el valor
	v_saljefe emp.sal%TYPE;
BEGIN
	--Averiguar el depto D con mayor media (cursor explicito no parametrizado)
	OPEN c2;
	FETCH c2 INTO v_d;
	CLOSE c2;
	--Listar empleados del depto D (cursor implicito parametrizado)
	--Para cada empleado B de D, hacer:
	FOR rec IN c1(v_d) LOOP
	--Calcular el salario S' de jefe de B (cursor implicito)
		SELECT j.sal
			INTO v_saljefe
			FROM emp e, emp j
			WHERE e.mgr = j.empno
			AND e.empno = rec.empno;
	--Si S' < salario S entonces
		IF (rec.sal > v_saljefe) THEN
		--Decir que hay mas de un empleado que cobra mas
			dbms_output.put_line(rec.ename||' cobra mas que su jefe ');
		END IF;
	END LOOP;
END;
/

