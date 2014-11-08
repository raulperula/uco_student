(define (producto-escalar v w)
  (if (= (vector-length v) (vector-length w)) 
      (do
          ;;inicializaciones
          (
           (i 0 (+ i 1))
           (resultado 0 (+ resultado (* (vector-ref v i) (vector-ref w i))))
           )
        ;;condicion de salida
        ((= (vector-length v) i) resultado)
        ;;no hay cuerpo del bucle
        )
      #f
      )
  )