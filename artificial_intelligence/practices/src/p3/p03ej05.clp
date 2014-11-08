;file   p03ej05.clp
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
