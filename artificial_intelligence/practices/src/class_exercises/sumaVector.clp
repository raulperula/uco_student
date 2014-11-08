;file   sumaVector.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate vector
(slot v0)
(slot v1)
(slot v2)
)

(deffacts vectorSuma
  (vector (v0 2) (v1 3) (v2 4))
)

(deffacts vectorProdEscalar1
  (vector (v0 3) (v1 4) (v2 5))
)

(deffacts vectorProdEscalar2
  (vector (v0 3) (v1 4) (v2 7))
)

(defrule sumaVector
    (vector (v0 ?a) (v1 ?b) (v2 ?c) ) 
=> 
    (printout t "SUMA "  (+ ?a ?b ?c) crlf  )  
)


(defrule prodEscalar
    (vector (v0 ?a1) (v1 ?b1) (v2 ?c1) )
    (vector (v0 ?a2) (v1 ?b2) (v2 ?c2) )
=>
    (printout t "PROD. ESCALAR " (+ (* ?a1 ?a2) (* ?b1 ?b2) (* ?c1 ?c2)) crlf)
)
