/**
 * @file    p5q11.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT COUNT(ename) TOTAL,
	SUM(DECODE(TO_CHAR(hiredate, 'YY'), '80', 1, 0)) "1980",
	SUM(DECODE(TO_CHAR(hiredate, 'YY'), '81', 1, 0)) "1981",
	SUM(DECODE(TO_CHAR(hiredate, 'YY'), '82', 1, 0)) "1982",
	SUM(DECODE(TO_CHAR(hiredate, 'YY'), '83', 1, 0)) "1983"
FROM emp;
