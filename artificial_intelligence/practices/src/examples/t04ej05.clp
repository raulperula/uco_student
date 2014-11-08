;file   t04ej05.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate persona
	(multislot nombre (type STRING) (cardinality 1 2))
	(multislot apellidos (type STRING) (cardinality 2 2))
	(slot dni (type INTEGER))
	(slot edad (type INTEGER) (range 1 130)))

	
(deffacts hechos1 (persona (nombre "Juan") (apellidos "Gomez" "Herrera") (dni 30458219) (edad 34)))
;(deffacts incorrecto (persona (nombre "Carmen") (apellidos "Sanchez") (dni 98342569) (edad 31)))

;En este ejemplo se define una plantilla con resticciones de tipo y de cardinalidad para cada multislot.
;Se puede observar como da error si se intenta insertar un hecho que no cumpla las restriciones impuestas.
