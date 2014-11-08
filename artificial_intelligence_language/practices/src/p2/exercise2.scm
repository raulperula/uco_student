(define (forman-triangulo? a b c)
  (and
   (< (abs(- a b)) c (+ a b))
   (< (abs(- a c)) b (+ a c))
   (< (abs(- b c)) a (+ b c))
   )
  )