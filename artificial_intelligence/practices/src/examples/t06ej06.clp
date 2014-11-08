;file   t06ej06.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule doble-activacion
	(hecho $? dato $?)
=>
	(printout t "Regla activada" crlf)
)

(deffacts hechos-iniciales
	(hecho dato dato)
)


;Este es un ejemplo de como un mismo hecho puede activar dos veces una regla.
;Esto ocurre porque existen dos formas de interpretar el EC patron: La primera
;es que el primer "dato" sea el primer comodin, y el segundo sea el literal. La
;Segunda es que el primer "dato" sea el literal, y el segundo sea el segundo
;comodin. CLIPS activa la regla dos veces, una por cada forma posible.
