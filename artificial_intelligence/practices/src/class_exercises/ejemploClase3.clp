;file   ejemploClase3.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

;La cabeza de la pila queda a la izquierda

(deffacts inicio-pila
	(pila)
)


(defrule meter-valor-pila
	?v <- (meter ?valor)
	?p <- (pila $?resto)
	
	=>

	(retract ?v ?p)
	(assert (pila ?valor $?resto))
	(printout t "Metiendo valor: " ?valor crlf)
)


(defrule sacar-valor-pila
	?s <- (sacar)
	?p <- (pila ?valor $?resto)

	=>

	(retract ?s ?p)
	(assert (pila $?resto))
	(printout t " Sacado valor: " ?valor crlf)
)
