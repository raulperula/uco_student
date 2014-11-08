;;funcion que determina si dos rectas definidas por dos puntos son perpendiculares

(define (perpendiculares? x1 y1 x2 y2 x3 y3 x4 y4)
  (= (* (- y2 y1) (- y4 y3)) (* (-1) (- x4 x3) (- x2 x1)) )
  )