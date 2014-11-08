/**
 * @file    p11q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

ALTER TABLE employee
ADD CONSTRAINT employee_dept_id_fk FOREIGN KEY (dept_id) REFERENCES department (id);
