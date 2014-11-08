;file   t04ej01.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate persona-slot
(slot nombre)
(slot apellido1)
(slot apellido2)
(slot dni))

(deftemplate persona-multislot
(multislot nombre)
(multislot apellidos)
(slot dni))
	
(deffacts hechos1 (persona-slot (nombre Juan) (apellido1 Perez) (apellido2 Garcia) (dni 39436099E)))
(deffacts hechos2 (persona-multislot (nombre Juan Carlos) (apellidos Escudero Gomez) (dni 30008732Q)))


;En este ejemplo se definen dos plantillas, una usando solo campos simples, y otra usando multicampos.
;A la hora de declarar hechos podemos observar que en el caso de la plantilla multislot podemos usar nombres compuestos
;y solo necesitamos un campo para los apellidos.
