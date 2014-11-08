;file   t04ej03.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate persona
(multislot nombre (type STRING)(allowed-strings "Pepe" "Juan" "Maria"))
(multislot apellidos (type STRING) (allowed-strings "Sanchez" "Gomez" "Herrera"))
(slot dni (type INTEGER)))

	
;(deffacts hechos1 (persona (nombre "Juan Carlos") (apellidos "Escudero Gomez") (dni 30008732)))
(deffacts hechos2 (persona (nombre "Juan") (apellidos "Gomez" "Herrera") (dni 30458219)))


;En este ejemplo se define una plantilla con resticciones de tipo y de valores para cada slot.
;Se puede observar como da error si se intenta insertar un hecho que no cumpla las restriciones impuestas.
