;file   p02ej12.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule ordenar
	?m <- (numero ?x)
	?n <- (numeros $?y)
	(not (numero ?z&:(> ?x ?z)))
	=>
	(retract ?m ?n)
	(assert (numeros $?y ?x))
)

(deffacts prueba
	(numero 5)
	(numero 9)
	(numero 2)
	(numero 3) 
	(numero 8)
	(numero 1)
	(numeros )
)
