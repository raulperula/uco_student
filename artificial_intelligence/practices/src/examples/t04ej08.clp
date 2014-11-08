;file   t04ej08.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

;Definimos una plantilla
(deftemplate prueba
	(slot dato1 (type INTEGER) (default ?NONE))
	(multislot dato2 (type STRING) (default ?DERIVE))
	(slot dato3 (type INTEGER) (range 1 100))
	(slot dato4 (default (gensym*)))
)

;Afirmamos un hecho basado en la plantilla anterior
(deffacts hecho (prueba (dato1 1) (dato2 "dato") (dato3 1)))

;Aquí habria que hacer un reset

;Modificamos el primer hecho
;(modify 1 (dato1 34))
;Duplicamos el segundo hecho cambiando el dato 2
;(duplicate 2 (dato2 "prueba correcta"))

;Podemos ver que al usar modify/duplicate, el dato4 que es dinamico y llama a una
;funcion para generar valores distintos no cambia, ya que ambas ordenes copian
;literalmente los campos sin importar lo que estos contengan
