;file   p03ej03.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deffunction subcadena
	(?cadena ?inicio ?fin)
	
	(if (> ?inicio ?fin) then
		(return (sub-string 1 ?inicio ?cadena))
	)else
		(return (sub-string ?inicio ?fin ?cadena))
)
