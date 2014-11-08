;file   p01ej06.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule comerpisto
  (tengo pimientos verdes)
  (tengo pimientos rojos)
  (tengo berenjenas)
  (tengo calabacines)
  (tengo cebollas)
  (tengo tomate triturado)
  (tengo sal)
  (tengo aceite)
  =>
  (printout t "COMO PISTO" crlf)
)

(defrule comertortilla
  (tengo huevos)
  (tengo patatas)
  (tengo cebollas)
  (tengo aceite)
  (tengo sal)
  =>
  (printout t "COMO TORTILLA" crlf)
)


;ingredientes que tengo
(deffacts iniciales
 (tengo pimientos verdes)
 (tengo pimientos rojos)
 (tengo cebollas)
 (tengo aceite)
 (tengo berenjenas)
 (tengo calabacines)
 (tengo tomate triturado)
 (tengo huevos)
 (tengo patatas)
 (tengo sal)
)
