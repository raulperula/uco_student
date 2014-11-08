;file   p02ej10.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate puede-plantarse
	(slot planta))

(defrule Hortensia
	(caracteristica-deseada frio)
	(caracteristica-deseada sequedad)
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada suelo-acido)
	(caracteristica-deseada cuidado-facil)
	=>
	(assert (puede-plantarse (planta Hortensia)))
)

(defrule Adelfa
	(caracteristica-deseada ciudad)
	(caracteristica-deseada maceta)
	(caracteristica-deseada cuidado-facil)
	(caracteristica-deseada crece-rapido)
	=>
	(assert (puede-plantarse (planta Adelfa)))
)

(defrule Laurel
	(caracteristica-deseada frio)
	(caracteristica-deseada sombra)
	(caracteristica-deseada sequedad)
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada ciudad)
	(caracteristica-deseada cuidado-facil)
	(caracteristica-deseada crece-rapido)
	=>
	(assert (puede-plantarse (planta Laurel)))
)

(defrule Madreselva
	(caracteristica-deseada ciudad)
	(caracteristica-deseada maceta)
	(caracteristica-deseada cuidado-facil)
	(caracteristica-deseada crece-rapido)
	=>
	(assert (puede-plantarse (planta Madreselva)))
)

(defrule Gardenia
	(caracteristica-deseada sombra)
	(caracteristica-deseada suelo-acido)
	(caracteristica-deseada maceta)
	=>
	(assert (puede-plantarse (planta Gardenia)))
)

(defrule Enebro
	(caracteristica-deseada frio)
	(caracteristica-deseada sequedad)
	(caracteristica-deseada suelo-acido)
	(caracteristica-deseada ciudad)
	(caracteristica-deseada cuidado-facil)
	=>
	(assert (puede-plantarse (planta Enebro)))
)

(defrule Pimentero
	(caracteristica-deseada frio)
	(caracteristica-deseada sombra)
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada suelo-acido)
	(caracteristica-deseada cuidado-facil)
	=>
	(assert (puede-plantarse (planta Pimentero)))
)

(defrule Escaramujo
	(caracteristica-deseada frio)
	(caracteristica-deseada sombra)
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada ciudad)
	(caracteristica-deseada cuidado-facil)
	=>
	(assert (puede-plantarse (planta Escaramujo)))
)

(defrule Aucuba
	(caracteristica-deseada sombra)
	(caracteristica-deseada sequedad)
	(caracteristica-deseada maceta)
	(caracteristica-deseada cuidado-facil)
	=>
	(assert (puede-plantarse (planta Aucuba)))
)

(defrule Azalea
	(caracteristica-deseada sombra)
	(caracteristica-deseada suelo-humedo)
	(caracteristica-deseada suelo-acido)
	(caracteristica-deseada maceta)
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
