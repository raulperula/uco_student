;;Funcion que filtra los numeros primos de una lista de numeros
(define (filtrar-primos lista)
  (define (filtrar-aux lista resultado)
    (cond 
      ((null? lista) resultado)
      ((primo? (car lista)) (filtrar-aux (cdr lista) (cons (car lista) resultado)))
      (else                 (filtrar-aux (cdr lista) resultado)) 
      )
    )
  ;;
  (filtrar-aux lista ())
  )

;;Funcion que determina si un numero es primo
(define (primo? x)
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
