;file   p03ej02.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deffacts inicio
	(inicio)
	(minimo 9999)
)

(deftemplate registro
	(multislot nombre)
	(slot edad (type INTEGER))
)

;Iniciamos
(defrule regla-inicial
	(inicio)
	=>
	(printout t "Introduce el nombre del fichero de entrada" crlf)
	(assert (abrir-fichero(read)))
)

;Abrimos los ficheros de entrada y salida
(defrule abrir-fichero
	?a<-(abrir-fichero ?x)
	=>
	(retract ?a)
	(open ?x fich-ent "r")
	(assert (datos(explode$(readline fich-ent))))
	(assert (leer-fichero))
)

;Leemos el fichero de entrada
(defrule leer-fichero
	?a<-(leer-fichero)
	=>
	(retract ?a)
	(assert (datos(explode$(str-cat(readline fich-ent)))))
	(assert (seguir-leyendo))
)

;Si no hemos llegado a EOF seguimos leyendo
(defrule seguir-leyendo
	(seguir-leyendo)
	(datos ?x&~EOF $?)
	(not(datos EOF))
	=>
	(assert (datos(explode$(str-cat(readline fich-ent)))))
)
	

;Si hemos llegado a EOF continua el programa
(defrule fin-fichero
	?a<-(seguir-leyendo)
	?b<-(datos ?x&EOF $?)
	=>
	(retract ?a ?b)
	(close fich-ent)
	(assert (fin-fichero))
)

;Pedimos el fichero de salida
(defrule pedir-salida
	?a<-(fin-fichero)
	=>
	(retract ?a)
	(printout t "Introduce el nombre del fichero de salida: " crlf)
	(assert (abrir-salida (read)))
)

;Abrimos el fichero de salida
(defrule abrir-salida
	?a<-(abrir-salida ?x)
	=>
	(retract ?a)
	(open ?x fich-sal "w")
	(assert (meter-datos))
)

;Transformamos los datos en registros
(defrule datos-ordenados
	?a<-(meter-datos)
	?b<-(datos $?nombre ?edad&:(integerp ?edad))
	=>
	(retract ?b)
	(assert (registro(nombre $?nombre)(edad ?edad)))
)

;Metemos los registros ordenados
(defrule ordenar-registros
	(not(datos $?))
	?a<-(minimo ?min)
	?b<-(registro(nombre $?nom) (edad ?eda))
	(not (exists (registro(edad ?ed&:(and (< ?ed ?eda) (not (= ?ed ?eda)))))))
	=>
	(retract ?b)
	(printout fich-sal (str-cat (implode$ $?nom) " " ?eda) crlf)
)

;FIN
(defrule fin
	(not(registro))
	(meter-datos)
	=>
	(close)
)
