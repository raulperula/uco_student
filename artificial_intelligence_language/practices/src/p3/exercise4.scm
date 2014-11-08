;;Funcion a integrar
(define (f x)
    (+ (* 2 x x) 3)
    )

;;Funcion que calcula el n-esimo termino de la sucesion de Simpson
(define (termino-Simpson a h k)
  (f (+ a (* h k)))
  )

;;Funcion iterativa que calcula la Serie de Simpson
(define (Simpson-iterativo a b n)
  (define h (/ (- b a) n) )
  ;;bucle iterativo
  (do
      ;;inicializaciones
      (
       (i 1 (+  i 1.0))
       (resultado (termino-Simpson a h 0) (+ resultado (cond
                                                         ((= i n) (termino-Simpson a h i))
                                                         ((even? i) (* 2 (termino-Simpson a h i)) )
                                                         ((odd? i) (* 4 (termino-Simpson a h i)))
                                                         )
                                             ))
       )
    ;;condicion de salida
    ((> i n) (* (/ h 3) resultado))
    ;;no hay cuerpo del bucle
    )
  )