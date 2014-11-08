;file   p02ej13.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate habitacion
	(slot num-personas)
	(slot ocupadas)
	(slot sexo-habitacion)
	(slot fumador)
)

(deftemplate estudiante
	(multislot nombre)
	(slot sexo (allowed-symbols M F))
	(slot fumador (allowed-numbers 0 1))
)

(defrule no-habitaciones
	(estudiante (nombre $?n) (sexo ?s) (fumador ?f))
	(or
		(not(habitacion))
		(forall(habitacion (num-personas ?x)(ocupadas ?y))
			(test (= ?x ?y))
		)
		(forall(habitacion (sexo-habitacion ?a))
			(test (not(str-compare ?a ?s)))
		)
		(forall(habitacion (fumador ?b))
			(test (not(= ?b ?f)))
		)
	)
	=>
	(printout t "No hay habitaciones disponibles" crlf)
)

(deffacts habitaciones
	(habitacion(num-personas 3)(ocupadas 3)(sexo-habitacion M)(fumador 0))
	(habitacion(num-personas 4)(ocupadas 0)(sexo-habitacion F)(fumador 1))
	(habitacion(num-personas 2)(ocupadas 0)(sexo-habitacion F)(fumador 0))
	(habitacion(num-personas 2)(ocupadas 0)(sexo-habitacion M)(fumador 1))
)

(deffacts estudiantes
	(estudiante (nombre Pepe) (sexo M) (fumador 0))
	(estudiante (nombre Pepa) (sexo F) (fumador 1))
	(estudiante (nombre Juan) (sexo M) (fumador 1))
	(estudiante (nombre Paula) (sexo F) (fumador 0))
)
