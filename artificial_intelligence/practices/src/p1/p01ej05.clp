;file   p01ej05.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate coche
  (slot modelo (type STRING))
  (slot motor (type STRING))
  (slot cc (type INTEGER))
  (slot puertas (type INTEGER))
  (slot color (type STRING))
  (slot unidades (type INTEGER))
)

(deftemplate ventas
  (multislot vendedor (type STRING))
  (slot fechadeventa (type STRING))
  (multislot cliente (type STRING))
)

