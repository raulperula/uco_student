;file   ejemploClase2.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deffacts valores-a-sumar
	(dato 1) 
	(dato 2) 
	(dato 3) 
	(dato 4)  
	(dato 5) 
	(suma 0)
)



(defrule sumar-numero
	?s <- (suma ?total)
	?t <- (dato ?valor)
	
	=>

	(retract ?s ?t)
	(assert (suma (+ ?total ?valor)))
)



(defrule mostrar-suma
	(not (dato ?))
	?s <- (suma ?total)
	
	=>

	(retract ?s)
	(printout t "La suma es: " ?total crlf)
)


