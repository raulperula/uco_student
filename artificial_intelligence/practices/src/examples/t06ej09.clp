;file   t06ej09.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule predicado
    ?y<-(dato1 ?x&:(numberp ?x))
=>
    (printout t "El hecho "?y" tiene un campo numerico: "?x crlf)
)

(deffacts hechos-iniciales
    (dato1 3)
    (dato1 2.3432)
    (dato1 casa)
    (dato1 "arbol")
    (dato1 (+ 34.53 3.8))
)

;Este ejemplo muestra el uso de una restriccion predicado. La funcion numberp
;devuelve TRUE si su argumento es un numero, o false si no lo es, esto es
;recogido por la restriccion predicado, por lo que si existe un hecho que tenga
;dato1 + numero, se activara la regla para ese hecho.
