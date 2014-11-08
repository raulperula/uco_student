/**
 * @file    p11q4.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT constraint_name, constraint_type
FROM user_constraints
WHERE table_name='DEPARTMENT' OR table_name='EMPLOYEE';
