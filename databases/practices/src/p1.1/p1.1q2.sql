/**
 * @file    p1.1q2.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT job
FROM emp
WHERE hiredate >= TO_DATE('01-07-1981','DD-MM-YYYY')
	AND hiredate <= TO_DATE('31-12-1981','DD-MM-YYYY')
INTERSECT
SELECT job
FROM emp
WHERE hiredate >= TO_DATE('01-07-1982','DD-MM-YYYY')
	AND hiredate <= TO_DATE('31-12-1982','DD-MM-YYYY');
