;file   p03ej07.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate simbolo
	(slot codigo)
	(slot letra)
)

(deftemplate nuevo-codigo
	(multislot cod)
)

(deftemplate codigo-trad
	(multislot cod)
)

(deffacts codigo-morse
	(simbolo (codigo "*-") (letra A))
	(simbolo (codigo "-***") (letra B))
	(simbolo (codigo "-*-*") (letra C))
	(simbolo (codigo "-**") (letra D))
	(simbolo (codigo "*") (letra E))
	(simbolo (codigo "**-*") (letra F))
	(simbolo (codigo "--*") (letra G))
	(simbolo (codigo "****") (letra H))
	(simbolo (codigo "**") (letra I))
	(simbolo (codigo "*---") (letra J))
	(simbolo (codigo "-*-") (letra K))
	(simbolo (codigo "*-**") (letra L))
	(simbolo (codigo "--") (letra M))
	(simbolo (codigo "-*") (letra N))
	(simbolo (codigo "---") (letra O))
	(simbolo (codigo "*--*") (letra P))
	(simbolo (codigo "--*-") (letra Q))
	(simbolo (codigo "*-*") (letra R))
	(simbolo (codigo "***") (letra S))
	(simbolo (codigo "-") (letra T))
	(simbolo (codigo "**-") (letra U))
	(simbolo (codigo "***-") (letra V))
	(simbolo (codigo "*--") (letra W))
	(simbolo (codigo "-**-") (letra X))
	(simbolo (codigo "-*--") (letra Y))
	(simbolo (codigo "--**") (letra Z))
)

(defrule inicio
	
	=>
	(assert(introducir-codigo))
)

(defrule introducir-codigo
	?a<-(introducir-codigo)
	=>
	(retract ?a)
	(printout t "Introduce codigo morse:" crlf)
	(assert (codigo (readline)))
	(assert (nuevo-codigo(cod)))
	(assert (separar))
)

(defrule separar
	?a<-(separar)
	?b<-(nuevo-codigo (cod $?x))
	?c<-(codigo ?y&:(and (stringp ?y) (str-index "/" ?y)))
	=>
	(retract ?c)
	(modify ?b (cod $?x (sub-string 1 (- (str-index "/" ?y) 1) ?y)))
	(assert (codigo (sub-string (+ (str-index "/" ?y) 1) (str-length ?y) ?y)))
)

(defrule separar2
	?a<-(codigo ?x&:(not(str-index "/" ?x))) ;el ultimo simbolo
	?b<-(nuevo-codigo (cod $?y))
	=>
	(modify ?b (cod ?x $?y))
	(retract ?a)
	(assert (codigo-trad (cod )))
	(assert (traducir))
)

(defrule traducir
	?a<-(traducir)
	?b<-(nuevo-codigo (cod $?x ?codigo))
	?c<-(codigo-trad (cod $?y))
	(simbolo (codigo ?z&:(= (str-compare ?z ?codigo) 0))(letra ?l))
	=>
	(modify ?c (cod $?y ?l))
	(modify ?b (cod $?x))
)

(defrule imprimir
	(nuevo-codigo(cod $?x&:(= (str-compare (nth$ 1 $?x) nil) 0)))
	(codigo-trad (cod $?y))
	=>
	(printout t "El mensaje morse es: " $?y crlf)
)
