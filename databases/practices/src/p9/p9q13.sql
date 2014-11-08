/**
 * @file    p9q13.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

DELETE FROM MY_EMPLOYEE
WHERE (first_name, last_name) = (SELECT first_name, last_name
																	FROM MY_EMPLOYEE
																	WHERE first_name='Betty' AND last_name='Dancs');
