/**
 * @file    p11q5.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT object_name, object_type
FROM user_objects
WHERE object_name LIKE 'DEPAR%' OR object_name LIKE 'EMPLO%';
