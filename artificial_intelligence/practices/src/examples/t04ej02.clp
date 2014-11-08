;file   t04ej02.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate persona
(multislot nombre (type STRING))
(multislot apellidos (type STRING))
(slot dni (type INTEGER)))

	
(deffacts hechos1 (persona (nombre "Juan Carlos") (apellidos "Escudero Gomez") (dni 30008732)))
(deffacts hechos2 (persona))

;En este ejemplo se define una plantilla con resticciones de tipo para cada slot.
;Se puede observar como al insertar un hecho sin dar valores a los slots, CLIPS le asigna sus valores por defecto.
