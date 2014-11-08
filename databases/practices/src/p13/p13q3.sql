/**
 * @file    p13q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

ACCEPT department_id PROMP 'Please enter the department number: '
ACCEPT department_name PROMP 'Please enter the department name: '

INSERT INTO department (id, name)
VALUES (&department_id, &department_name);
