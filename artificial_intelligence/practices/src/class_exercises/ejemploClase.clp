;file   ejemploClase.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deffacts sumar
	(datos 2 3 4)
	(objetivo sumar)
)


(defrule multiplicar
	?ob <- (objetivo multiplicar)
	(datos ?a ?b ?c)

	=>

	(retract ?ob)
	(assert (producto (* ?a ?b ?c)))
	(assert (objetivos cumplidos))
)


(defrule sumar
	?ob <- (objetivo sumar)  ;EC patron para controlar la linea de razonamiento
	(datos ?a ?b ?c)

	=>

	(retract ?ob)
	(assert (suma (+ ?a ?b ?c)))
	(assert (objetivo multiplicar))
)


(defrule presentarMultiplicar
	(declare (salience 10))
	(producto ?p)

	=>

	(printout t "Producto = " ?p crlf)
) 


(defrule presentarSumar
	(declare (salience 10))
	(suma ?s)

	=>
	
	(printout t "Suma = " ?s crlf)
) 
