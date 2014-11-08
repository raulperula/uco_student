;;;Tipo abstracto DOnante
;;Vectores
;Funcion de Creacion
(define (hacer-donante nombre n_don grupo factor_h)
  (vector nombre n_don grupo factor_h)
  )
;Funciones de lectura
(define (nombre donante)
  (vector-ref donante 0)
  )
(define (n_don donante)
  (vector-ref donante 1)
  )
(define (grupo donante)
  (vector-ref donante 2)
  )
(define (factor donante)
  (vector-ref donante 3)
  )
;Funciones de modificacion
(define (cambiar-nombre! donante nuevo_nombre)
  (vector-set! donante 0 nuevo-nombre)
  )
(define (cambiar-n_don! donante nuevo_n_don)
  (vector-set! donante 1 nuevo-n_don)
  )
(define (cambiar-grupo! donante nuevo_grupo)
  (vector-set! donante 2 nuevo_grupo)
  )
(define (cambiar-factor_h! donante nuevo_factor_h)
  (vector-set! donante 3 nuevo_factor_h)
  )
;;Listas
;Funciond de creacion
(define (hacer-donante nombre n_don grupo factor_h)
  (list nombre n_don grupo factor_h)
  )
;Funciones de Acceso
(define (nombre donante)
  (car donante)
  )
(define (n_don donante)
  (cadr donante)
  )
(define (grupo donante)
  (caddr donante)
  )
(define (factor_h donante)
  (cdddr donante)
  )
;Funciones de Modificacion
(define (cambiar-nombre donante nuevo)
  (cons nuevo (cdr donante))
  )
(define (cambiar-n_don donante nuevo)
  (cons (car donante)
        (cons nuevo (cddr donante))
        )
  )
(define (cambiar-grupo donante nuevo)
  (cons
   (cons (car donante)
         (cadr donante))
   (cons nuevo (cdddr donante))
   )
  )
 (define (cambiar-factor_h donante nuevo)
   (reverse
    (cons nuevo (cdr (reverse donante)))
    )
   )
;;Listas de asociacion
;Funcion de creacion
(define (crear-donante nombre n_don grupo factor_h)
  (list 'nombre nombre)
  (list 'n_don n_don)
  (list 'grupo grupo)
  (list 'factor_h factor_h)
  )
;Funciones de acceso
(define (nombre donante)
  (cadr (assoc 'nombre donante))
  )
(define (n_don donante)
  (cadr (assoc 'n_don donante))
  )
(define (grupo donante)
  (cadr (assoc 'grupo donante))
  )
(define (factor_h donante)
  (cadr (assoc 'factor_h donante))
  )
;Funciones de modificacion
(define (cambiar-nombre donante nuevo)
  (set-cdr! (assoc 'nombre donante) (list nuevo))
  )
(define (cambiar-n_don donante nuevo)
  (set-cdr! (assoc 'n_don donante) (list nuevo))
  )
(define (cambiar-grupo don-�.�-.p�ante nuevo)
  (set-cdr! (assoc 'grupo donante) (list nuevo))
  )
(define (cambiar- donante nuevo)
  (set-cdr! (assoc 'factor_h donante) (list nuevo))
  )