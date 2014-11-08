;file   t05ej01.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defglobal ?*r* = 45)

(deffacts circulo
	(radio ?*r*)
	(diametro (* ?*r* 2))
	(circunferencia (* 2 3.14 ?*r*))
	(area (* 3.14 (* ?*r* ?*r*)))
)


;Este ejemplo muestra el uso de expresiones dinamicas a la hora de afirmar hechos
