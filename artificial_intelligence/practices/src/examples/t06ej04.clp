;file   t06ej04.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule ec-constante
	(hecho1 dato1 dato2 dato3)
=>
	(printout t "Regla activada" crlf)
)

(deffacts hechos
	(hecho1 dato1 dato2)
	(hecho2 dato1 dato2 dato3)
	(hecho1 dato2 dato1 dato3)
	(hecho1 dato1 dato2 dato3)
)

;En este ejemplo solo se activa una vez la regla. Se utiliza un EC patron usando
;una restriccion de constante
