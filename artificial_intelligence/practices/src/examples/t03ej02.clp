;file   t03ej02.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(clear)
(deftemplate coche (slot marca)(slot modelo))
(deffacts hechos (coche (marca audi)(modelo a8)))
(deffacts hechos2 (a)(b))
(reset)

;En este ejemplo se define una plantilla para mostrar el funcionamiento del constructor
;deffacts con hechos tanto ordenados como no ordenados. Es importante usar "hechos" y
;"hechos2" ya que si usamos el mismo nombre se sobreescribe la orden, por lo que sólo
;aparecerían los hechos (a) y (b). 
