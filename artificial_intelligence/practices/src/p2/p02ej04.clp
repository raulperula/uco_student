;file   p02ej04.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate animal
	(slot nombre)
	(slot tipo)
	(slot sonido)
)

(defrule mascota
	?a<-(animal (nombre ?x&~nil) (tipo ?y&~nil) (sonido nil))
	(animal (tipo ?y&~nil) (sonido ?z&~nil))
	=>
	(modify ?a (sonido ?z))
	(printout t ?x " dice "?z crlf)
)

;He puesto la primera condicion con la restriccion (sonido nil) para evitar
;que al afirmar un hecho como (animal (tipo gato)(nombre felix)(sonido guau))
;se dispare 2 veces la regla

(deffacts animales
	(animal (tipo perro) (sonido guau))
	(animal (tipo gato) (sonido miau))
	(animal (tipo vaca) (sonido muu))
	(animal (tipo oveja) (sonido bee))
	(animal (tipo pato) (sonido cuac))
	(animal (tipo gallo) (sonido kikiriki))
)
