;file   t03ej03.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate coche (slot marca) (slot modelo))

(deffacts hechos-iniciales (coche (marca ford) (modelo focus)) (coche (marca nissan)(modelo almera)))

(defrule borrar-coches
?x <- (coche (marca ?a)(modelo ?b))
=>
(retract ?x)
(printout t "Borrando coche " ?a " " ?b crlf))

;En este ejemplo podemos ver como se eliminan hechos por su dirección, en este caso
;eliminamos todos los coches de la lista de hechos iniciales.
