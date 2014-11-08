;file   p03ej04.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deffunction cabeza
	(?cadena ?primeros)
	(if (> ?primeros (str-length ?cadena)) then
		(printout t "La cadena es demasiado corta" crlf)
	)else
		(return (sub-string 1 ?primeros ?cadena))
)

(deffunction cola
	(?cadena ?ultimos)
	(if (> ?ultimos (str-length ?cadena)) then
		(printout t "La cadena es demasiado corta" crlf)
	)else
		(return (sub-string (+(- (str-length ?cadena) ?ultimos) 1) (str-length ?cadena) ?cadena))
)
