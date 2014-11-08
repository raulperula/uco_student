;;Funcion que da el termino n-esimo de la serie
(define (termino-Leibniz n)
  (define i (- (* 2 n) 1))
  (/ (expt -1 (+ n 1))
     i
     )
  )

;;Funcion que calcula la serie de Leibniz
(define (Leibniz-pi-1 n)
  (do
      ;;inicializaciones
      ( 
       (resultado 1.0 (+ resultado (termino-Leibniz i)))
       (i 2.0 (+ i 1))
       )
    ;;condiciones de salida
    ((< n i) resultado)
    ;;no hay cuerpo
     
    )
  )

;;Funcion que calcula la serie de leibniz 2
(define (Leibniz-pi-2 cota)
  (do
      ;;inicializaciones
      (
       (termino 1 (termino-Leibniz i))
       (ant 0 (termino-Leibniz (- i 1)))
       (resultado 1.0 (+ resultado termino))
       (i 2.0 (+ i 1))
       )
    ;;condicion de salida
    ((< (abs (- ant termino)) cota) resultado)
    ;;no hay cuerpo
    )
  )
  
;;Funcion que calcula el termino de Wallis
(define (Wallis n)
  (define numer n)
  (define denom n)
  (if (even? n) (/ (+ numer 2) (+ denom 1)) (/ (+ numer 1) (+ denom 2)))
  )

;;Funcion que calcula la serie de Wallis
(define (Wallis-iter n)
  (do
      ;;iniciliazaciones
      (
       (i 1 (+ i 1))
       (resultado 1 (* resultado (Wallis i)))
       )
    ;;condicion de salida
    ((> i n) resultado)
    ;;cuerpo del bucle
    
    )
  )

;;Funcion que calcula la serie de Wallis con una cota de error
(define (Wallis-recur cota)
  (define (wallis-aux resultado cota i)
    (if (< (- 1 cota) (Wallis i) (+ 1 cota)) (* resultado (Wallis i)) (wallis-aux (* resultado (Wallis i)) cota (+ i 1)))
    )
  (wallis-aux 1 cota 1)
  )