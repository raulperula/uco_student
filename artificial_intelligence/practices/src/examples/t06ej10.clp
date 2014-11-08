;file   t06ej10.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deffacts triangulos
    (es-triangulo 3.54 7.8 13.806)
    (es-triangulo 3.0 4.0 6.0)
    (es-triangulo 54.2 23.123 3213.55)
)

(defrule hacer-cuentas
    ?a<-(es-triangulo ?x ?y ?z)
=>
    (printout t ?a" area correcta: " (* ?x ?y 0.5) crlf)
)


(defrule comprobar-area-triangulo
    ?a<-(es-triangulo ?x ?y ?z&=(* ?x ?y 0.5))
=>
    (printout t ?a" es un triangulo con base: "?x", altura: "?y" y area: "?z crlf)
)


;En este ejemplo usamos una restriccion de valor devuelto para comprobar si el
;area del triangulo es la correcta. Al poner el & podemos asignar el valor a ?z
;para despues poder mostrar el area el el consecuente. Si no quisieramos asignar
;ninguna variable bastaría con hacer (es-triangulo ?x ?y =(/ (* ?x ?y) 2))
