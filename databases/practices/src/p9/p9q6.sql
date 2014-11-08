/**
 * @file    p9q6.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

/* loademp.sql */

ACCEPT	first PROMPT 'Please enter the first name:'
ACCEPT	last PROMPT 'Please enter the last name:'
ACCEPT	sal PROMPT 'Please enter the salary:'

INSERT INTO MY_EMPLOYEE
VALUES ('&first', '&last', SUBSTR('&first',1,1)||'&last', sal);
