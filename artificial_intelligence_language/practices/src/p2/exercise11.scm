(define (dist-euclidea x1 y1 x2 y2)
    (sqrt (+
           (expt (- x2 x1) 2)
           (expt (- y2 y1) 2)
           )
          )
    )

(define (alineados? x1 y1 x2 y2 x3 y3)
  (if (= (* (- x2 x1) (- y3 y1)) (* (- x3 x1) (- y2 y1))) #t #f)
  )

;;Funcion que calcula el area de un triangulo por la formula de Heron
(define (area-triangulo x1 y1 x2 y2 x3 y3)
  (define (Heron x1 y1 x2 y2 x3 y3)
    (define a (dist-euclidea x1 y1 x2 y2))
    (define b (dist-euclidea x2 y2 x3 y3))
    (define c (dist-euclidea x3 y3 x1 y1))
    (let 
         (s (/ (+ a b c)
               2.0
               ))
      ;;cuerpo del let
      (sqrt (* s
               (- s a)
               (- s b)
               (- s c)
               )
            )
      )
    )
  (if (alineados? x1 y1 x2 y2 x3 y3) 0
      (Heron x1 y1 x2 y2 x3 y3))
    )