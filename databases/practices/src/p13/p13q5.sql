/**
 * @file    p13q5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT index_name, table_name, uniqueness
FROM user_indexes
WHERE index_name LIKE 'EMPLOYEE%';
