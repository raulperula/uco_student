;file   p02ej08.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate fecha
	(slot dia (type NUMBER)(range 1 31)(default ?NONE))
	(slot mes (type NUMBER)(range 1 12)(default ?NONE))
	(slot anyo(type NUMBER)(default ?NONE))
)

(defrule comprobar-fecha
	(fecha (dia ?d)(mes ?m)(anyo ?a))
	(test (or
		(and (or (= ?m 4)(= ?m 6)(= ?m 9)(= ?m 11)) (> ?d 30))
		(and (= ?m 2) (> ?d 29) (= (mod ?a 4) 0))
		(and (= ?m 2) (> ?d 29) (= (mod ?a 400) 0))
		(and (= ?m 2) (> ?d 28) (and (not (= (mod ?a 4) 0)) (not (= (mod ?a 400) 0))))
		)
	)
	=>
	(printout t "La fecha " ?d"/"?m"/"?a" es incorrecta" crlf)
)
