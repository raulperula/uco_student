;file   p02ej05.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defglobal ?*F* = 0)
(defglobal ?*X* = 1)

(defrule es-factorial
	(factorial ?x)
	=>
	(bind ?*F* ?x)
	(assert (factor ?x))
)

(defrule calcular-factorial
	?a<-(factor ?x)
	(test (> ?x 1))
	=>
	(retract ?a)
	(assert (factor (- ?x 1)))
	(bind ?*X* (* ?*X* ?x))
)

(defrule mostrar-factorial
	(factor 1)
	=>
	(printout t "El factorial de "?*F*" es " ?*X* crlf)
)
