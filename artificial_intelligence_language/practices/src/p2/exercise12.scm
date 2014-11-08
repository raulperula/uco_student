(define (dist-euclidea x1 y1 x2 y2)
    (sqrt (+
           (expt (- x2 x1) 2)
           (expt (- y2 y1) 2)
           )
          )
    )
;;Funcion que determina la posicion relativa entre dos circunferencias.
;;Se ayuda de una funcion auxiliar que calcula la distancia entre los centros
(define (pos-rel-cicunf r1 r2 x1 y1 x2 y2)
  (define d (dist-euclidea x1 y1 x2 y2))
  (define R (+ r1 r2))
  (define Rp (abs (- r1 r2)))
  (cond
    ;;concentricas
    ((and (= x1 x2) (= y1 y2) (not(= r1 r2)) ) 6)
    ;;iguales
    ((and (= x1 x2) (= y1 y2) (= r1 r2) ) 0)
    ;;secantes
    ((and (< d R) (< Rp d)) 1)
    ;;interiores
    ((and (< d R) (< d Rp)) 4)
    ;;tangentes interiores
    ((and (< d R) (= Rp d)) 2)
    ;;tangentes por fuera
    ((and (= d R) (< Rp d)) 3)
    ;;exteriores
    ((and (< R d) 5))
    )
  )

;;Función que determina la posición relativa entre dos esferas.
;;Se ayuda de una función auxiliar para calcular la distancia entre dos puntos en el espacio.
(define (posición-relativa-esferas x1 y1 z1 r1 x2 y2 z2 r2)
  (define (dist-euclídea-esp x1 y1 z1 x2 y2 z2)
   (sqrt (+ 
   (expt (- x2 x1) 2)                    
   (expt (- y2 y1) 2)
   (expt (- z2 z1) 2)))
  )  
  (define distancia-centros (dist-euclídea-esp x1 y1 z1 x2 y2 z2) )
  (define suma-radios (+ r1 r2) )
  (define diferencia-radios (abs (- r1 r2)))
 
  (cond    
    ((or (< r1 0) (< r2 0)) (display "Error, has introducido un radio negativo"))
    ((and (= distancia-centros 0) (= r1 r2)) 0)
    ((< diferencia-radios distancia-centros suma-radios) 1)
    ((= distancia-centros diferencia-radios) 2)
    ((= distancia-centros suma-radios) 3)
    ((< 0 distancia-centros diferencia-radios) 4)
    ((> distancia-centros suma-radios) 5)   
    ((and (= distancia-centros 0) (not(= r1 r2))) 6)  
     )
    
  )