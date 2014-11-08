;file   p01ej04.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate libro
  (multislot autores (type STRING))
  (slot titulo (type STRING))
  (slot editorial (type STRING))
  (slot edicion (type INTEGER))
  (slot anyo (type INTEGER))
)


;insertamos algun hecho

(deffacts librosIA
  (libro
    (autores "Mira Delgado" "Boticario Diez")
    (titulo "Aspectos_Basicos_de_la_Inteligencia_Artificial")
    (editorial "Sanz_Y_Torres")
    (anyo 1995)
  )

  (libro
    (autores "Rich E_Knight")
    (titulo "Inteligencia_Artificial.")  
    (edicion 2)
    (editorial "McGraw-Hill_Interamericana.") 
    (anyo 1994)
  )
)
