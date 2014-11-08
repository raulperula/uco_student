;; funcion que calcula la distancia euclidea entre dos puntos a traves de las coordenadas
(define (dist-euclidea x1 y1 x2 y2)
  (sqrt (+
         (expt (- x2 x1) 2)
         (expt (- y2 y1) 2)
         )
        )
  )

;; funcion que calcula el area de un rombo a partir de sus coordenadas.
;;Las coordenadas de indice impar corresponden a la diagonal mayor, y las de indice par a las de la diagonal menor
(define (area-rombo-aux x1 y1 x2 y2 x3 y3 x4 y4)
  ;;calculo de las diagonales
  (define dmayor (dist-euclidea x1 y1 x3 y3))
  (define dmenor (dist-euclidea x2 y2 x4 y4))
  ;;
  (/
   (* dmayor dmenor)
   2
   )
  )
;;funcion que determina si dos rectas definidas por dos puntos son perpendiculares

(define (perpendiculares? x1 y1 x2 y2 x3 y3 x4 y4)
  (= (* (- y2 y1) (- y4 y3)) (* (-1) (- x4 x3) (- x2 x1)) )
  )

;;Funcion que calcula el area del rombo
(define (area-rombo x1 y1 x2 y2 x3 y3 x4 y4)
  (cond
    ((perpendiculares? x1 y1 x2 y2 x3 y3 x4 y4) (area-rombo-aux x1 y1 x3 y3 x2 y2 x4 y4))
    ((perpendiculares? x1 y1 x3 y3 x2 y2 x4 y4) (area-rombo-aux x1 y1 x2 y2 x3 y3 x4 y4))
    ((perpendiculares? x1 y1 x4 y4 x2 y2 x3 y3) (area-rombo-aux x1 y1 x2 y2 x4 y4 x3 y3))
    (else 0)
    )
  )