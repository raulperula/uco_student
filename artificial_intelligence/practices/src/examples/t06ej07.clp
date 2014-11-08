;file   t06ej07.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate persona
	(slot nombre (type SYMBOL))
	(multislot apellidos (type SYMBOL))
)

(defrule uso-de-variables
	(persona (nombre ?x) (apellidos $?y))
=>
	(printout t "Nombre completo: " ?x " " $?y crlf)
)

(deffacts lista-personas
	(persona (nombre Manuel) (apellidos Pedrero Luque))
	(persona (nombre Juan) (apellidos Perez Gutierrez))
	(persona (nombre Maria) (apellidos Valverde Espinosa))
)

;Este es un ejemplo de uso de variables en ECs
