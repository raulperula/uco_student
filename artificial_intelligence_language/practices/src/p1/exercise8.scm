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
(define (area-rombo x1 y1 x2 y2 x3 y3 x4 y4)
  ;;calculo de las diagonales
  (define dmayor (dist-euclidea x1 y1 x3 y3))
  (define dmenor (dist-euclidea x2 y2 x4 y4))
  ;;
  (/
   (* dmayor dmenor)
   2
   )
  )

;; funcion que calcula el area de un triangulo mediante el uso de la formula de Heron y a partir de las coordenadas de los vertices.Los puntos se fijan en el sentido de las agujas del reloj.
(define (Heron x1 y1 x2 y2 x3 y3)
  ;;calculo de los lados
  (define a (dist-euclidea x1 y1 x2 y2))
  (define b (dist-euclidea x2 y2 x3 y3))
  (define c (dist-euclidea x1 y1 x3 y3))
  ;;calculo del semiperimetro
  (define s (/ (+ a b c) 2))
  ;;calculo del area
  (sqrt (*
         s
         (- s a)
         (- s b)
         (- s c)
         )
        )
  )

