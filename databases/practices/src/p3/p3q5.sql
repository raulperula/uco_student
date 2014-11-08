/**
 * @file    p3q5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT ename, hiredate, TO_CHAR(NEXT_DAY(ADD_MONTHS(hiredate, 6), 'Lunes'), 'fmDay", the "Ddspth" of "Month", "YYYY') REVIEW
FROM emp;
