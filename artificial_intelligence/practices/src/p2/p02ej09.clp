;file   p02ej09.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(defrule Hortensia
	(caracteristica-deseada frio)
	(not(caracteristica-deseada sombra))
	(caracteristica-deseada sequedad)
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada suelo-acido)
	(not(caracteristica-deseada ciudad))
	(not(caracteristica-deseada maceta))
	(caracteristica-deseada cuidado-facil)
	(not(caracteristica-deseada crece-rapido))
	=>
	(printout t "Planta hortensia" crlf)
)

(defrule Adelfa
	(not(caracteristica-deseada frio))
	(not(caracteristica-deseada sombra))
	(not(caracteristica-deseada sequedad))
	(not(caracteristica-deseada suelo-humedo))
	(not(caracteristica-deseada suelo-acido))
	(caracteristica-deseada ciudad)
	(caracteristica-deseada maceta)
	(caracteristica-deseada cuidado-facil)
	(caracteristica-deseada crece-rapido)
	=>
	(printout t "Planta adelfa" crlf)
)

(defrule Laurel
	(caracteristica-deseada frio)
	(caracteristica-deseada sombra)
	(caracteristica-deseada sequedad)
	(caracteristica-deseada suelo-humedo)
	(not(caracteristica-deseada suelo-acido))
	(caracteristica-deseada ciudad)
	(not(caracteristica-deseada maceta))
	(caracteristica-deseada cuidado-facil)
	(caracteristica-deseada crece-rapido)
	=>
	(printout t "Planta laurel" crlf)
)

(defrule Madreselva
	(not(caracteristica-deseada frio))
	(not(caracteristica-deseada sombra))
	(not(caracteristica-deseada sequedad))
	(not(caracteristica-deseada suelo-humedo))
	(not(caracteristica-deseada suelo-acido))
	(caracteristica-deseada ciudad)
	(caracteristica-deseada maceta)
	(caracteristica-deseada cuidado-facil)
	(caracteristica-deseada crece-rapido)
	=>
	(printout t "Planta madreselva" crlf)
)

(defrule Gardenia
	(not(caracteristica-deseada frio))
	(caracteristica-deseada sombra)
	(not(caracteristica-deseada sequedad))
	(not(caracteristica-deseada suelo-humedo))
	(caracteristica-deseada suelo-acido)
	(not(caracteristica-deseada ciudad))
	(caracteristica-deseada maceta)
	(not(caracteristica-deseada cuidado-facil))
	(not(caracteristica-deseada crece-rapido))
	=>
	(printout t "Planta gardenia" crlf)
)

(defrule Enebro
	(caracteristica-deseada frio)
	(not(caracteristica-deseada sombra))
	(caracteristica-deseada sequedad)
	(not(caracteristica-deseada suelo-humedo))
	(caracteristica-deseada suelo-acido)
	(caracteristica-deseada ciudad)
	(not(caracteristica-deseada maceta))
	(caracteristica-deseada cuidado-facil)
	(not(caracteristica-deseada crece-rapido))
	=>
	(printout t "Planta enebro" crlf)
)

(defrule Pimentero
	(caracteristica-deseada frio)
	(caracteristica-deseada sombra)
	(not(caracteristica-deseada sequedad))
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada suelo-acido)
	(not(caracteristica-deseada ciudad))
	(not(caracteristica-deseada maceta))
	(caracteristica-deseada cuidado-facil)
	(not(caracteristica-deseada crece-rapido))
	=>
	(printout t "Planta pimentero" crlf)
)

(defrule Escaramujo
	(caracteristica-deseada frio)
	(caracteristica-deseada sombra)
	(not(caracteristica-deseada sequedad))
	(caracteristica-deseada suelo-humedo)
	(not(caracteristica-deseada suelo-acido))
	(caracteristica-deseada ciudad)
	(not(caracteristica-deseada maceta))
	(caracteristica-deseada cuidado-facil)
	(not(caracteristica-deseada crece-rapido))
	=>
	(printout t "Planta escaramujo" crlf)
)

(defrule Aucuba
	(not(caracteristica-deseada frio))
	(caracteristica-deseada sombra)
	(caracteristica-deseada sequedad)
	(not(caracteristica-deseada suelo-humedo))
	(not(caracteristica-deseada suelo-acido))
	(not(caracteristica-deseada ciudad))
	(caracteristica-deseada maceta)
	(caracteristica-deseada cuidado-facil)
	(not(caracteristica-deseada crece-rapido))
	=>
	(printout t "Planta aucuba" crlf)
)

(defrule Azalea
	(not(caracteristica-deseada frio))
	(caracteristica-deseada sombra)
	(not(caracteristica-deseada sequedad))
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada suelo-acido)
	(not(caracteristica-deseada ciudad))
	(caracteristica-deseada maceta)
	(not(caracteristica-deseada cuidado-facil))
	(not(caracteristica-deseada crece-rapido))
	=>
	(printout t "Planta azalea" crlf)
)

(deffacts plantas 
	(caracteristica-deseada sombra)
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada suelo-acido)
	(caracteristica-deseada maceta)
)

