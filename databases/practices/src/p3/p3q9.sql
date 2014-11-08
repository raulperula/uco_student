/**
 * @file    p3q9.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT INITCAP(ename) "Name", LENGTH(ename) "Length"
FROM emp
WHERE SUBSTR(ename, 1, 1)='J' OR SUBSTR(ename, 1, 1)='A' OR SUBSTR(ename, 1, 1)='M';
