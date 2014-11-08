;file   p03ej06.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deffunction es-potencia
	(?numero ?base)
	
	(if (and (integerp ?numero) (integerp ?base) (>= ?numero 0) (>= ?base 0)) then
		(bind ?res (/ (log ?numero) (log ?base)))
			(if (= (round ?res) ?res)
		then 
			TRUE
		)else
			FALSE
	else
		FALSE
	)
)

(deftemplate lista
	(multislot elementos)
)

(defrule inicio
	(inicio)
	=>
	(assert(buscar-minimo))
)

(defrule buscar-minimo
	?a<-(buscar-minimo)
	(numero ?x)
	=>
	(retract ?a)
	(assert (minimo ?x))
)

(defrule minimo
	?a<-(minimo ?x)
	(numero ?y&:(< ?y ?x))
	=>
	(retract ?a)
	(assert (minimo ?y))
)

(defrule detener-busqueda
	(minimo ?x)
	(not(numero ?y&:(< ?y ?x)))
	=>
	(assert (potencias))
)

(defrule potencias
	(potencias)
	(minimo ?x)
	(numero ?y&:(es-potencia ?y ?x))
	=>
	(assert (sumando ?y))
)

(defrule sumar
	?a<-(sumando ?x)
	?b<-(suma ?y)
	?c<-(lista(elementos $?lis))
	=>
	(retract ?a ?b)
	(assert (suma (+ ?x ?y)))
	(modify ?c (elementos ?x $?lis))
)

(defrule mostrar-sumandos
	(suma ?x&:(not(= ?x 0)))
	(lista(elementos $?y))
	(minimo ?w)
	(not(numero ?z&:(and (es-potencia ?z ?w) (not(member$ ?z $?y)))))
	=>
	(printout t "La suma de "$?y" es "?x crlf)
)

(deffacts numeros
	(numero 2)
	(numero 3)
	(numero 4)
	(numero 5)
	(numero 6)
	(numero 7)
	(numero 8)
	(numero 9)
	(numero 10)
	(inicio)
	(suma 0)
	(lista (elementos))
)
