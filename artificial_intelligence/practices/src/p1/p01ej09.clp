;file   p01ej09.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate pelicula
  (multislot titulo (type STRING))
  (multislot director (type STRING))
  (multislot nacionalidad (type STRING))
  (multislot genero (type STRING))
  (multislot interpretes (type STRING))
  (slot duracion (type INTEGER))
  (slot anyo (type INTEGER) (range 1900 2100))
  (slot nota (type INTEGER) (range 0 10))
)
