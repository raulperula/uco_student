;;Funcion Incremento Funcional
(define (incremento-funcional f)
  (lambda (x)
  (/ (+ (f (+ x 1)) (* -2 (f x)) (f (- x 1)) )
     4)
    )
  )

;;funcion auxiliar de prueba
(define (g x)
  (* x x)
  )