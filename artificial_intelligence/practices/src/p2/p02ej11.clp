;file   p02ej11.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate puede-plantarse
	(slot planta))

(defrule Hortensia
	(logical
		(caracteristica-deseada frio)
		(caracteristica-deseada sequedad)
		(caracteristica-deseada suelo-humedo)
		(caracteristica-deseada suelo-acido)
		(caracteristica-deseada cuidado-facil))
	=>
	(assert (puede-plantarse (planta Hortensia)))
)

(defrule Adelfa
	(logical
		(caracteristica-deseada ciudad)
		(caracteristica-deseada maceta)
		(caracteristica-deseada cuidado-facil)
		(caracteristica-deseada crece-rapido))
	=>
	(assert (puede-plantarse (planta Adelfa)))
)

(defrule Laurel
	(logical
		(caracteristica-deseada frio)
		(caracteristica-deseada sombra)
		(caracteristica-deseada sequedad)
		(caracteristica-deseada suelo-humedo)
		(caracteristica-deseada ciudad)
		(caracteristica-deseada cuidado-facil)
		(caracteristica-deseada crece-rapido))
	=>
	(assert (puede-plantarse (planta Laurel)))
)

(defrule Madreselva
	(logical
		(caracteristica-deseada ciudad)
		(caracteristica-deseada maceta)
		(caracteristica-deseada cuidado-facil)
		(caracteristica-deseada crece-rapido))
	=>
	(assert (puede-plantarse (planta Madreselva)))
)

(defrule Gardenia
	(logical
		(caracteristica-deseada sombra)
		(caracteristica-deseada suelo-acido)
		(caracteristica-deseada maceta))
	=>
	(assert (puede-plantarse (planta Gardenia)))
)

(defrule Enebro
	(logical
		(caracteristica-deseada frio)
		(caracteristica-deseada sequedad)
		(caracteristica-deseada suelo-acido)
		(caracteristica-deseada ciudad)
		(caracteristica-deseada cuidado-facil))
	=>
	(assert (puede-plantarse (planta Enebro)))
)

(defrule Pimentero
	(logical
		(caracteristica-deseada frio)
		(caracteristica-deseada sombra)
		(caracteristica-deseada suelo-humedo)
		(caracteristica-deseada suelo-acido)
		(caracteristica-deseada cuidado-facil))
	=>
	(assert (puede-plantarse (planta Pimentero)))
)

(defrule Escaramujo
	(logical
		(caracteristica-deseada frio)
		(caracteristica-deseada sombra)
		(caracteristica-deseada suelo-humedo)
		(caracteristica-deseada ciudad)
		(caracteristica-deseada cuidado-facil))
	=>
	(assert (puede-plantarse (planta Escaramujo)))
)

(defrule Aucuba
	(logical
		(caracteristica-deseada sombra)
		(caracteristica-deseada sequedad)
		(caracteristica-deseada maceta)
		(caracteristica-deseada cuidado-facil))
	=>
	(assert (puede-plantarse (planta Aucuba)))
)

(defrule Azalea
	(logical
		(caracteristica-deseada sombra)
		(caracteristica-deseada suelo-humedo)
		(caracteristica-deseada suelo-acido)
		(caracteristica-deseada maceta))
	=>
	(assert (puede-plantarse (planta Azalea)))
)

(deffacts plantas
	(caracteristica-deseada frio)
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada suelo-acido)
	(caracteristica-deseada sequedad)
	(caracteristica-deseada cuidado-facil)
	(caracteristica-deseada crece-rapido)
)
