;file   p02ej01.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule es-perro
	(sonido guau)
	=>
	(printout t "Se trata de un perro" crlf)
)

(defrule es-pato
	(sonido cuac)
	=>
	(printout t "Se trata de un pato" crlf)
)

(defrule es-vaca
	(sonido muu)
	=>
	(printout t "Se trata de una vaca" crlf)
)

(defrule es-gato
	(sonido miau)
	=>
	(printout t "Se trata de un gato" crlf)
)

(defrule es-oveja
	(sonido bee)
	=>
	(printout t "Se trata de una oveja" crlf)
)

(defrule es-gallo
	(sonido kikiriki)
	=>
	(printout t "Se trata de un gallo" crlf)
)
