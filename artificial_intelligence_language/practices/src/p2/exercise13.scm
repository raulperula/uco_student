(define (dist-punto-recta x y a b c)
  (/ (+ (* a x)
        (* b y)
        c)
     (sqrt (+ (* a a)
              (* b b)
              )
           )
     )
  )

;;Funcion distancia que calcula la distancia de una circunferencia a una  recta

(define (dist-circunf-recta r x y a b c)
  (- (dist-punto-recta x y a b c)
     r)
  )