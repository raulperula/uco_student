;file   p02ej14.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate producto
	(slot nombre)
	(slot pvp)
)

(deftemplate compra 
	(slot producto) 
	(slot unidades)
)

(defrule tres-por-dos
	(compra (producto ?x)(unidades ?y))
	(producto (nombre ?x)(pvp ?z))
	=>
	(assert (precio-total (- (* ?z ?y) (*(/ ?y 3) ?z))))
)
