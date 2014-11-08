;;Funcion que determina la suma de los divisores de un numero
(define (suma-divisores a)
  (define (suma-aux a suma i)
    (if (= a i) suma 
                (if (= 0 (modulo a i)) (suma-aux a (+ suma i) (+ i 1)) 
                                       (suma-aux a suma (+ i 1))
                                       )
         )
    )
  (suma-aux a 0 1)
  )
;;Funcion que determina  si dos numeros son amigos
(define (amigos? a b)
  (define sumadiv-a (suma-divisores a))
  (define sumadiv-b (suma-divisores b))
  (if (and (= sumadiv-a b) (= sumadiv-b a) ) #t #f)
  )
;;Funcion que determina si un numero es perfecto
(define (perfecto? a)
  (amigos? a a)
  )