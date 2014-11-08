;;Funcion que calcula si dos lados son paralelas dados dos puntos
(define (lados-paralelos? x1 y1 x2 y2 x3 y3 x4 y4)
  (define m1 (/ (- y2 y1) (- x2 x1)))
  (define m2 (/ (- y4 y3) (- x4 x3)))
  (and (= m1 m2) )
  )
;;Distancia euclidea
(define (dist-euclidea x1 y1 x2 y2)
    (sqrt (+
           (expt (- x2 x1) 2)
           (expt (- y2 y1) 2)
           )
          )
    )
;;distacia punto a recta
(define (dist-punto-recta x y a b c)
  (/ (abs (+ (* a x)
        (* b y)
        c))
     (sqrt (+ (* a a)
              (* b b)
              )
           )
     )
  )
(define (dist.punto-recta2 x0 y0 x1 y1 x2 y2)
    (define a (- y2 y1))
    (define b (- x1 x2))
    (define c (-
               (* y1 x2)
               (* x1 y2)
               )
      )
  (dist-punto-recta x0 y0 a b c)
  )
;;Area trapecio auxiliar
(define (area-trapecio-aux x1 y1 x2 y2 x3 y3 x4 y4)
  ;;funcion auxiliar para calcular la distancia entre dos puntos
  (define (dist-euclidea x1 y1 x2 y2)
    (sqrt (+
           (expt (- x2 x1) 2)
           (expt (- y2 y1) 2)
           )
          )
    )
  ;;definicion de bases
  (define base-mayor (dist-euclidea x1 y1 x4 y4))
  (define base-menor (dist-euclidea x2 y2 x3 y3))

  ;;definicion de altura
  (define altura (dist.punto-recta2 x2 y2 x1 y1 x4 y4))
  
  ;;calculo del area
  (/ (*(+
        base-mayor
        base-menor
        )
       altura
       )
     2.0
     )
  )
;;Funcion que calcula el area de un trapecio
;;Se ayuda de una funcion auxiliar que calcula el area de un trapecio dandole las coordenadas de los vertices en sentido horario
;;Las coordenadas de los puntos se establecen en sentido horario
(define (area-trapecio x1 y1 x2 y2 x3 y3 x4 y4)
  (cond
    ((lados-paralelos? x1 y1 x2 y2 x3 y3 x4 y4) (area-trapecio-aux x1 y1 x2 y2 x3 y3 x4 y4))
    ((lados-paralelos? x1 y1 x4 y4 x3 y3 x2 y2) (area-trapecio-aux x1 y1 x2 y2 x3 y3 x4 y4))
    ;;((lados-paralelos? x1 y1 x4 y4 x3 y3 x2 y2) (area-trapecio-aux x1 y1 x2 y2 x3 y3 x4 y4))
    (else 0)
    )
  )
