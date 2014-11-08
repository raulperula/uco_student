;;Funcion que calcula si dos lados son paralelas dados dos puntos
(define (lados-paralelos? x1 y1 x2 y2 x3 y3 x4 y4)
  (define m1 (/ (- y2 y1) (- x2 x1)))
  (define m2 (/ (- y4 y3) (- x4 x3)))
  (and (= m1 m2) )
  )