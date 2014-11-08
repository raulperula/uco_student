;;Funcion que determina el MCD de 630 y 198 iterativo
(define (mcd-iterativo x y)
  (do
      ;;inicializaciones
      (
       (a x b)
       (b y r)
       (r (modulo x y) (modulo a b))
       )
    ;;condicion de salida
    ((= r 0) b)
    ;;no hay cuerpo del bucle
    )
  )

;;Funcion que calcula el MCD de 630 y 198 recursivo
(define (mcd-recursivo a b)
  (if (= (modulo a b) 0) b (mcd-recursivo b (modulo a b)))
  )