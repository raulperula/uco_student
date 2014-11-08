;file   p02ej07.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defglobal ?*BADSENSOR* = 0)

(deftemplate sensor
	(slot numero (range 1 10)(default ?NONE))
	(slot estado (allowed-symbols correcto incorrecto)(default ?NONE))
)

(defrule control-estados
	(sensor (estado incorrecto))
	=>
	(bind ?*BADSENSOR* (+ ?*BADSENSOR* 1))
	(assert (sensores-defectuosos ?*BADSENSOR*))
)

(defrule advertencia
	(sensores-defectuosos ?x)
	(test (= ?x 3))
	=>
	(printout t "Advertencia. Fallan tres o mas sensores" crlf)
)
	
	
