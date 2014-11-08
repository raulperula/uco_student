;file   t04ej06.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate dato
	(slot nombre (default ?NONE))
	(multislot apellidos (default ?NONE))
	(slot dni (default ?NONE))
	(multislot direccion (default ?DERIVE))
	(slot identificacion (default-dynamic (gensym*)))
)

(deffacts hechos
	(dato (nombre "Manuel") (apellidos "Pedrero Luque") (dni 30995147))
	(dato (nombre "Carlos") (apellidos "Fernandez Valle") (dni 30875543))
	(dato (nombre "Andres") (apellidos "Montes") (dni 30226591) (direccion "Calle la Haya 7"))
)

;En este ejemplo hemos definido una plantilla con valores por defecto. El nombre
;los apellidos y el dni llevan el atributo (default ?NONE) que indica que tienen que
;tener asignado un valor obligatoriamente. El campo direccion sin embargo es opcional.
;Por ultimo, CLIPS asigna un valor unico a cada hecho mediante la funcion (gensym*)
;que sirve como identificacion. Como lo hemos asignado dinamicamente, cada vez que se
;introduzca un nuevo hecho utilizando esta plantilla, asignara un valor nuevo en el
;campo identificacion
