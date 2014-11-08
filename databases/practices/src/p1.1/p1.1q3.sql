/**
 * @file    p1.1q3.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

SELECT '10% off' AS DISCOUNT, prodid, stdprice, stdprice*0.9 AS ACTPRICE
FROM price
WHERE stdprice < 10
UNION
SELECT '15% off' AS DISCOUNT, prodid, stdprice, stdprice*0.75 AS ACTPRICE
FROM price
WHERE stdprice >10 AND stdprice < 30
UNION
SELECT '20% off' AS DISCOUNT, prodid, stdprice, stdprice*0.8 AS ACTPRICE
FROM price
WHERE stdprice > 30 AND stdprice < 40
UNION
SELECT 'no disc' AS DISCOUNT, prodid, stdprice, stdprice AS ACTPRICE
FROM price
WHERE stdprice > 40;
