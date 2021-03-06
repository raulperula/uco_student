(define pi (/ 355.0 113.0))
(define (cuadrado x)
  (* x x)
  )
(define (cubo x)
  (* x x x)
  )
(define (celsius->fahrenheit grados)
  (+ 32.0 (* (/ 9.0 5.0) grados))
  )
(define (fahrenheit->celsius grados)
  (* (- grados 32.0) (/ 5 9))
  )
(define (area-rombo d1 d2)
  (/ (* D d) 2)
  )
(define (volumen-esfera r)
  (* (/ 4 3) pi (cubo r))
  )
(define (sup-esfera r)
  (* 4 pi (cuadrado r))
  )
(define (vol-cilindro h r)
  (* (sup-esfera r) h)
  )