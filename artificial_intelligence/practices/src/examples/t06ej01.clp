;file   t06ej01.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deffacts hechos-iniciales
	(hecho 1)
	(hecho 2)
	(hecho 3)
	(hecho 4)
)

(defrule regla1
	(hecho ?x)
=>
	(printout t "regla1 activada por el hecho " ?x crlf)
)

(defrule regla2
	(hecho ?x)
	(hecho ?y)
=>
	(printout t "regla2 activada por los hechos " ?x " y " ?y crlf)
)

;Aqui se puede observar como trabaja el motor de inferencia de CLIPS. Podemos
;ver como una regla puede ser activada por diferentes conjuntos de hechos, y 
;como un mismo conjunto de hechos puede activar mas de una regla
