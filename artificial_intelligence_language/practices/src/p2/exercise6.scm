(define (bisiesto? a�o)
  (cond
    ((and
      (= (modulo a�o 4) 0)
      (> (modulo a�o 100) 0)
      ) #t)
    ((and
      (= (modulo a�o 100) 0)
      (= (modulo a�o 400) 0)
      ) #f)
    (else (display "no bisiesto"))
    )
  )