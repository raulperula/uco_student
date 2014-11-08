/**
 * @file    p19q1.sql
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

DECLARE
	v_aux messages.results%TYPE;
	v_count NUMBER(2) := 1;
BEGIN
	LOOP
		IF v_count <> 6 AND v_count <> 8 THEN
			INSERT INTO messages(results)
				VALUES(v_count);
		END IF;
		v_count := v_count+1;
		EXIT WHEN v_count > 10;
	END LOOP;
END;
/

SELECT *
FROM messages;

COMMIT;
