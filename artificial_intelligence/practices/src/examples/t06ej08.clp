;file   t06ej08.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deffacts hechos
    (dato1 verde)
    (dato1 rojo)
    (dato1 azul)
    (dato1 amarillo)
    (dato1 verde rojo)
)

(defrule not
    ?x<-(dato1 ~rojo)
=>
    (printout t "Existe un dato con valor distinto de rojo: "?x crlf)
)

(defrule not2
    (dato1 ?x&~rojo)
=>
    (printout t "Existe un dato con valor distinto de rojo: "?x crlf)
)

(defrule and
    (dato1 ?x&~verde&~rojo)
=>
    (printout t "Existe un dato que no es ni verde ni rojo: "?x crlf)
)

(defrule and2
    ?z<-(dato1 ?x&verde ?y&rojo)
=>
    (printout t "Existe un dato que es verde y rojo: "?z": "?x" "?y crlf)
)

(defrule or
    ?x<-(dato1 verde|rojo)
=>
    (printout t "Existe un dato con valor verde o rojo: "?x crlf)
)

(defrule compuesta
    ?a<-(dato1 ?x & rojo|verde)
    ?b<-(dato1 ?y&~?x)
=>
    (printout t "El hecho "?a" es rojo o verde, y el hecho "?b" no es "?x", sino "?y crlf)
)


;En este ejemplo podemos ver varios ejemplo de restricciones conectivas,
;incluyendo la excepcion con AND y variables, que se ha utilizado para mostrar
;los colores que cumplen las reglas
