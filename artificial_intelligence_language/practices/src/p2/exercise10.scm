;;Funcion que mira si 3 puntos estan alineados
;;devuelve true si estan alineados y false si no lo estan
(define (alineados? x1 y1 x2 y2 x3 y3)
  (if (= (* (- x2 x1) (- y3 y1)) (* (- x3 x1) (- y2 y1))) #t #f)
  )