(define (dist-euclidea x1 y1 x2 y2)
    (sqrt (+
           (expt (- x2 x1) 2)
           (expt (- y2 y1) 2)
           )
          )
    )

;;Funcion que calcula la distancia entre dos circunferencias
;;Se ayuda de una funcion auxiliar que calcula la distancia entre 2 puntos
(define (dist-circunferencias r1 r2 x1 y1 x2 y2)
  (define d (dist-euclidea x1 y1 x2 y2))
  (if (< (+ r1 r2) d) (- d (+ r1 r2)) 0)
  )