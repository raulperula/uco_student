/**
 * @file    p9q11.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

UPDATE MY_EMPLOYEE
SET salary = 1000
WHERE salary = (SELECT salary
								FROM MY_EMPLOYEE
								WHERE sal < 1000);
