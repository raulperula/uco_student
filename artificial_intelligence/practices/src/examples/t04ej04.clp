;file   t04ej04.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate persona
	(multislot nombre (type STRING)(allowed-strings "Pepe" "Juan" "Maria"))
	(multislot apellidos (type STRING) (allowed-strings "Sanchez" "Gomez" "Herrera" "Escudero"))
	(slot dni (type INTEGER))
	(slot edad (range 1 130))

	
;(deffacts hechos1 (persona (nombre "Juan") (apellidos "Escudero Gomez") (dni 30008732) (edad 140)))
(deffacts hechos2 (persona (nombre "Juan") (apellidos "Gomez" "Herrera") (dni 30458219) (edad 34)))


;En este ejemplo se define una plantilla con resticciones de tipo y de valores para cada slot.
;Se puede observar como da error si se intenta insertar un hecho que no cumpla las restriciones impuestas.
