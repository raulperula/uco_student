;;Predicado que determina si un numero variable de argumentos esta ordenada en orden creciente
(define orden-creciente?
  (lambda lista
    (do
        ;;inicializaciones
       (
        (i 1 (+ i 1))
        (result #t (if (< (list-ref lista i) (list-ref lista (- i 1)) ) #f #t) )
        )
      ;;condicion de salida
      ((or (eqv? #f result) (= (length lista) i)) result)
      )
    )
  )