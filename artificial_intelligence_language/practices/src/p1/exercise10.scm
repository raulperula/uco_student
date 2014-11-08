;; funcion que calcula la distancia de un punto a una recta
;; x0 y0 corresponde a las coordenadas del punto
;; a, b, c corresponde a los coeficientes de la recta.
(define (dist.punto-recta x0 y0 a b c)
  (/
   (abs (+
         (* a x0)
         (* b y0)
         c
         )
        )
   (sqrt (+
          (expt a 2)
          (expt b 2)
          )
         )
   )
  )

;; Funcion que calcula la distancia de un punto a una recta mediante las coordenadas de dos puntos que pasan por la recta
;; x0 y0 corresponde a las coordenadas del punto
;; x1 y1 x2 y2 corresponde a dos puntos de la recta
;; hacemos uso de una funcion auxiliar para calcular a b c
;; nos valemos de la funcion anterior para calcular la distancia una vez tenemos a b c.
(define (dist.punto-recta2 x0 y0 x1 y1 x2 y2)
    (define a (- y2 y1))
    (define b (- x1 x2))
    (define c (-
               (* y1 x2)
               (* x1 y2)
               )
      )
  (dist.punto-recta x0 y0 a b c)
  )

;;Funcion que calcula el area del trapecio mediante sus coordenadas
;;los puntos empiezan a numerarse desde el punto izq de la base mayor siguiendo en sentido horario.
;;Se ayuda de una funcion auxiliar para calcular la distancia entre dos puntos, definida dentro de la funcion, y de otra funcion para calcular la distancia de un punto a una recta, definida fuera de la funcion.

(define (area-trapecio x1 y1 x2 y2 x3 y3 x4 y4)
  ;;funcion auxiliar para calcular la distancia entre dos puntos
  (define (dist-euclidea x1 y1 x2 y2)
    (sqrt (+
           (expt (- c a) 2)
           (expt (- d b) 2)
           )
          )
    )
  ;;definicion de bases y altura
  (let 
      (
       (base-mayor (dist-euclidea x1 y1 x4 y4))
       (base-menor (dist-euclidea x2 y2 x3 y3))
       (altura (dist.punto-recta2 x2 y2 x1 y1 x4 y4))  
  )
  ;;cuerpo del let
  (/ (* base-mayor
        base-menor
        altura
        )
     2.0
     )
    )
  )