;;Funcion iterativa que determina si un numero es primo
(define (primo-iterativo? x)
  (do
      ;;inicializaciones
      (
       (i 2 (+ i 1))
       (marca 0 (if (= 0 (modulo x i)) 1 0))
       (resultado #t (if (= 0 (modulo x i)) #f #t))
       )
    ;;condicion de salida
    ((or (> i (sqrt x)) (= marca 1) ) resultado)
    ;;no hay cuerpo del bucle
    )
  )

;;Funcion recursiva que determina si un numero es primo
(define (primo-recursivo? x)
  (define (primo-aux? x i)
    (if (= (modulo x i) 0) #f (if (< (sqrt x) i) #t (primo-aux? x (+ i 1))))
    )
  (primo-aux? x 2)
  )