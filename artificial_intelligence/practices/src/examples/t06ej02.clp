;file   t06ej02.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule bucle-infinito
	?x <- (hecho)
=>
	(retract ?x)
	(assert (hecho))
	(printout t "Regla activada" crlf)
)

(deffacts hechos-iniciales
	(hecho)
)

;Este ejemplo genera un bucle infinito, en el se retracta el hecho que activa
;la regla "bucle-infinito" y en el consecuente de dicha regla se vuelve a afirmar, 
;por lo que ya no es el mismo hecho, y por tanto la regla se dispara sin fin.
