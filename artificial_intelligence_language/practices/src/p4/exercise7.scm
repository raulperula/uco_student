;; FUncion que determina el numero de veces que aparece un objeto en una lista
(define (veces x lista)
  (cond
    ((not (list? lista)) 0)
    ((null? lista) 0)
    ((list? (car lista)) (+ (veces x (car lista))
                            (veces x (cdr lista))
                            )
                         )
    ((equal? x (car lista)) (+ 1 (veces x (cdr lista))))
    (else (veces x (cdr lista)))
    )
  )
