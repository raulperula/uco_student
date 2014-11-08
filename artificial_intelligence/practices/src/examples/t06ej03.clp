;file   t06ej03.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule regla-refraccion
	(hecho)
=>
	(printout t "Regla activada" crlf)
)

(deffacts hechos-iniciales
	(hecho)
)

;Este ejemplo a diferencia del anterior no genera un bucle infinito, ya que 
;un mismo conjunto de hechos (en este caso el hecho "hecho") solo puede activar
;una regla una vez.
