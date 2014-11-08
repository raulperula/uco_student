;;Distancia euclidea
(define (dist-euclidea x1 y1 x2 y2)
    (sqrt (+
           (expt (- x2 x1) 2)
           (expt (- y2 y1) 2)
           )
          )
    )
;;Distancia ajedrez
(define (dist-ajedrez x1 y1 x2 y2)
  (+ (abs (- x2 x1))
     (abs (- y2 y1))
     )
  )
;;Distancia Manhattan
(define (dist-manhattan x1 y1 x2 y2)
  (max (abs (- x2 x1))
       (abs (- y2 y1))
       )
  )

;;Funcion que calcula donde esta ubicado un punto
;;devuelve el valor del cuadrante o 0 si esta en los ejes
(define (cuadrante x y)
  (cond
    ((and (< 0 x) (< 0 y)) 1)
    ((< x 0 y) 2)
    ((and (< x 0) (< y 0)) 3)
    ((< y 0 x) 4)
    (else 0)
    )
  )
;;Funcion que calcula la ubicacion de un punto en el plano
;;utiliza una funcion auxiliar que calcula el cuadrante en el que se encuentra un punto
(define (ubicacion x y)
  (cond
    ((and (= (cuadrante x y) 1) (< y x)) 2)
    ((and (= (cuadrante x y) 1) (< x y)) 1)
    ((and (= (cuadrante x y) 2) (< (abs x) (abs y))) 8)
    ((and (= (cuadrante x y) 2) (< (abs y) (abs x))) 7)
    ((and (= (cuadrante x y) 3) (< (abs y) (abs x))) 6)
    ((and (= (cuadrante x y) 3) (< (abs x) (abs y))) 5)
    ((and (= (cuadrante x y) 4) (< (abs x) (abs y))) 4)
    ((and (= (cuadrante x y) 4) (< (abs y) (abs x))) 3)
    (else 0)
    )
  )

;;Funfion f3
;;Se ayuda de la funcion auxiliar dist-euclidea definida fuera
(define (f3 x y)
  
  (define dist1 (dist-euclidea 0 2 0 1))
  (define dist2 (dist-euclidea 0 2 3 2))
  (define dist3 (dist-euclidea 0 2 x y))
  (cond
    ((< dist3 dist1) (+ (* 2 x) (/ y 2)))
    ((and (< dist1 dist3) (< dist3 dist2)) (+ (/ x 2) (* y 2)))
    ((< dist2 dist3) (+ x y))
    ((or (= dist1 dist3) (= dist2 dist3)) 1)
    )
)

;;Funcion F4.Devuelve un valor dependiendo de la posicion del punto
;;Se ayuda de unas funciones auxiliares definidas fuera de ella

(define (f4 x y)
  (define dist-circunf (dist-euclidea 2 2 4 2))
  (define dist-rombo (dist-ajedrez 4 4 4 2))
  (define dist-cuadrado (dist-manhattan 6 2 4 2))
  
  (cond
    ((or (and (= x 0) (= y 0)) (= dist-circunf (dist-euclidea 2 2 x y)) (= dist-rombo (dist-ajedrez 4 4 x y)) (= dist-cuadrado (dist-manhattan 6 2 x y))) 0)
    ((and (> dist-circunf (dist-euclidea 2 2 x y)) (> dist-rombo (dist-ajedrez 4 4 x y))) 1)
    ((and (> dist-rombo (dist-ajedrez 4 4 x y)) (> dist-cuadrado (dist-manhattan 6 2))) 2)
    ((and (> dist-rombo (dist-ajedrez 4 4 x y)) (< dist-circunf (dist-euclidea 2 2 x y)) (< dist-cuadrado (dist-manhattan 6 2 x y))) 3)
    ((and (> dist-circunf (dist-euclidea 2 2 x y)) (< dist-rombo (dist-ajedrez 4 4 x y))) 4)
    ((and (< dist-rombo (dist-ajedrez 4 4 x y)) (> dist-cuadrado (dist-manhattan 6 2 x y))) 5)
    (else 6)
    )
  )
  
;;Funcion F5
(define (f x y)
  (define dist-circunf (dist-euclidea 2 2 2 1))
  (define dist-rombo (dist-ajedrez 2 1 2 0))
  (define dist-cuadrado (dist-manhattan 2 2 2 1))
  (define dist1 (dist-euclidea 2 2 x y))
  (define dist2 (dist-ajedrez 2 1 x y))
  (define dist3 (dist-manhattan 2 2 x y))
  (cond
    ;;Punto en los lados de las figuras
    ((or (= dist-circunf (dist-euclidea 2 2 x y))
         (= dist-rombo (dist-ajedrez 2 1 x y))
         (= dist-cuadrado (dist-manhattan 2 2 x y))
         )
     0)
    ;;Punto dentro del circulo y fuera del rombo
    ((and (> dist2 dist-rombo)
          (< dist1 dist-circunf))
     1)
    ;;Punto dentro del circulo y del rombo
    ((and (< dist2 dist-rombo)
          (< dist1 dist-circunf))
     2)
    ;;Punto dentr del cuadrado y del rombo y fuera del circulo
    ((and (< dist2 dist-rombo)
          (< dist3 dist-cuadrado)
          (> dist1 dist-circunf))
          
     3)
    ;;Punto dentrod el cuadrado y fuera del rombo y del circulo
    ((and (< dist3 dist-cuadrado)
          (> dist2 dist-rombo)
          (> dist1 dist-circunf))
     4)
    ((and (< dist2 dist-rombo)
          (< dist-cuadrado dist3))
     5)
    (else 6)
    )
  )