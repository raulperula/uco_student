(define (pertenece? l x)
  (cond
    ((null? l) #f)
    ((eq? x (car l)) #t)
    (else (pertenece? (cdr l) x))
    )
  
  )

;;Diferencia Simetrica
(define (dif-simetricas l1 l2)
  (define (dif-aux l1 l2 result)
    (cond
      ((null? l1) result)
      ((not(pertenece? l2 (car l1))) (dif-aux (cdr l1) l2 (append result (list (car l1)) )) )
      (else (dif-aux (cdr l1) l2 result))
      )
    
    
    )
  (append (dif-aux l1 l2 ()) (dif-aux l2 l1 ()) )
  
  )