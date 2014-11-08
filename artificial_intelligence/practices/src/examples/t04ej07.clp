;file   t04ej07.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

;Definimos una plantilla
(deftemplate plantilla-prueba
	(slot dato1 (type INTEGER) (default ?NONE))
	(multislot dato2 (type STRING) (default ?DERIVE))
	(slot dato3 (type INTEGER) (range 1 100))
	(slot dato4 (default (gensym*)))
)

;Aqui habria que hacer un reset

;Listamos las plantillas activas
;(list-deftemplates)

;Mostramos la plantilla que hemos creado
;(ppdeftemplate plantilla-prueba)

;Borramos todos los hechos que dependen de la plantilla plantilla-prueba
;(retract *)

;Borramos la plantilla plantilla-prueba
;(undeftemplate plantilla-prueba)

