;file   p01ej02.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate persona
  (multislot nombre (type STRING))
  (multislot apellido (type STRING))
  (slot color-ojos (type STRING))
  (slot altura (type FLOAT))
)
