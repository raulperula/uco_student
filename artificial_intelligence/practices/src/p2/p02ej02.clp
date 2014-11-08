;file   p02ej02.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate animal
	(slot tipo)
	(slot sonido)
)

(defrule es-animal
	(sonido ?x)
	(animal (tipo ?y) (sonido ?x))
	=>
	(printout t ?x" -> "?y crlf)
)

(deffacts animales
	(animal (tipo perro) (sonido guau))
	(animal (tipo gato) (sonido miau))
	(animal (tipo vaca) (sonido muu))
	(animal (tipo oveja) (sonido bee))
	(animal (tipo pato) (sonido cuac))
	(animal (tipo gallo) (sonido kikiriki))
)
