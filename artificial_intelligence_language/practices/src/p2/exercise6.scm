(define (bisiesto? año)
  (cond
    ((and
      (= (modulo año 4) 0)
      (> (modulo año 100) 0)
      ) #t)
    ((and
      (= (modulo año 100) 0)
      (= (modulo año 400) 0)
      ) #f)
    (else (display "no bisiesto"))
    )
  )