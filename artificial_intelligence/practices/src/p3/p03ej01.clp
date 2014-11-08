;file   p03ej01.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate planta
	(slot nombre)
	(multislot caracteristicas)
)

(deffacts inicio
	(entrada)
)

(deffacts plantas
	(planta (nombre Hortensia) (caracteristicas sombra ciudad maceta crece-rapido))
	(planta (nombre Adelfa) (caracteristicas ciudad maceta cuidado-facil crece-rapido))
	(planta (nombre Laurel) (caracteristicas frio sombra sequedad suelo-humedo ciudad maceta cuidado-facil crece-rapido))
	(planta (nombre Madreselva) (caracteristicas ciudad maceta cuidado-facil crece-rapido))
	(planta (nombre Gardenia) (caracteristicas sombra suelo-acido maceta))
	(planta (nombre Enebro) (caracteristicas frio sequedad suelo-acido ciudad cuidado-facil))
	(planta (nombre Pimentero) (caracteristicas frio sombra suelo-humedo suelo-acido cuidado-facil))
	(planta (nombre Escaramujo) (caracteristicas frio sombra suelo-humedo ciudad cuidado-facil))
	(planta (nombre Aucuba) (caracteristicas sombra sequedad maceta cuidado-facil))
	(planta (nombre Azalea) (caracteristicas sombra suelo-humedo suelo-acido maceta))
)




(defrule entrada
	?a<-(entrada)
	=>
	(retract ?a)
	(printout t "Introduzca caracteristica: " crlf)
	(assert (deseada (read)))
	(assert (mas))
)

(defrule mas
	?a<-(mas)
	=>
	(retract ?a)
	(printout t "Quiere introducir mas caracteristicas? (S/N)" crlf)
	(assert (otra (read)))
)

(defrule otra-incorrecta
	?a<-(otra ~N&~S)
	=>
	(retract ?a)
	(printout t "Respuesta incorrecta, use solo S/N (mayusculas)" crlf)
	(assert (mas))
)

(defrule otra-si
	?a<-(otra S)
	=>
	(retract ?a)
	(assert (entrada))
)

(defrule otra-no
	?a<-(otra N)
	=>
	(retract ?a)
	(assert (analizar))
)

(defrule analizar
	(analizar)
	(planta (nombre ?x))
	(forall (deseada ?y) (planta (nombre ?x)(caracteristicas $? ?y $?)))
	=>
	(printout t "posible planta: " ?x crlf)
)
