;file   t06ej05.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule ec-comodin
	(hecho1 dato1 ? dato2 $?)
=>
	(printout t "Regla activada" crlf)
)

(deffacts hechos
	(hecho1 dato1 dato2)
	(hecho1 dato1 dato4 dato2 dato3)
	(hecho1 dato1 dato1 dato2)
	(hecho1 dato1 34.5 dato2 43.2 dato4 dato5 dato3)
)

;En este ejemplo se activa 3 veces la regla, la primera no se activa porque no
;cumple las condiciones del primer comodin.
