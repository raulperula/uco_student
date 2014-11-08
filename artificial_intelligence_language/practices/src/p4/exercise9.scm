;;Funcion que elimina las sublistas de una lista
(define (eliminar-sublistas lista)
  (define (eliminar-aux lista result)
    (cond
      ((null? lista) (reverse result))
      ((list? (car lista)) (eliminar-aux (cdr lista) result))
      (else (eliminar-aux (cdr lista) (cons (car lista) result) ) )
      )
    )
  ;;
  (eliminar-aux lista () )
  )