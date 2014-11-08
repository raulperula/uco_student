;file   p02ej06.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defglobal ?*F* = 0)
(defglobal ?*X* = 1)
(defglobal ?*OCUPADO* = 0)


(defrule es-factorial
	(factorial ?x)
	(test (= ?*OCUPADO* 0))
	=>
	(bind ?*OCUPADO* 1)
	(bind ?*X* 1)
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
	?a<-(factor ?x)
	=>
	(printout t "El factorial de "?*F*" es " ?*X* crlf)
	(retract ?a)
	(bind ?*OCUPADO* 0)
)
