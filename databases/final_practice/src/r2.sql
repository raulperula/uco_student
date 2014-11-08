/**
 * @file    r2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
CREATE TABLE manager
	(mgrno NUMBER,
	deptno NUMBER NOT NULL,
	numEmp NUMBER,
	cuota NUMBER,
	CONSTRAINT manager_mgrno_pk PRIMARY KEY(mgrno),
	CONSTRAINT manager_mgrno_fk FORAIGN KEY(empno) REFERENCES emp(empno),
	CONSTRAINT manger_deptno_fk FORAIGN KEY(deptno) REFERENCES dept(deptno),
	CONSTRAINT manager_cuota_ck CHECK(cuota BETWEEN 10 AND 100));
