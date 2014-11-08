;;Funcion que determina el maximo de un vector
(define (max-vector v)
  (do
      ;;inicializaciones
      (
       (i 0 (+ i 1))
       (max -10000 (if (> (vector-ref v i) max) (vector-ref v i) max))
       )
    ;;condicion de salida
    ((= i (vector-length v)) max)
    )
  )
;;Funcion que determina el maximo de una matriz no necesariamente cuadrada
(define (max-matriz m)
  (define fil (vector-length m))
  (define col (vector-length (vector-ref m 0)))
  (do
      ;;inicializaciones
      (
       (i 0 (+ i 1))
       (max -10000 (if (> (max-vector (vector-ref m i)) max) (max-vector (vector-ref m i)) max))
       )
    ;;condicion de salida
    ((= i fil) max)
    )
  )