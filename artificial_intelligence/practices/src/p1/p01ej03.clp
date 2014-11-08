;file   p01ej03.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate familiar
  (slot nombre (type STRING))
  (slot apellido1 (type STRING))
  (slot apellido2 (type STRING))
  (slot parentesco (type STRING))
  (slot edad (type INTEGER))
)


;Representacion mediante hechos ordenados

(deffacts familia1
  (es-familiar Manuel Pedrero Paz Padre 48)
  (es-familiar Lola Luque Marquez Madre 48)
  (es-familiar Manuel Pedrero Luque Hijo 19)
  (es-familiar Alvaro Pedrero Luque Hermano 13)
  (es-familiar Manuel Pedrero Osuna AbueloPaterno 78)
  (es-familiar Enriqueta Paz Salido AbuelaPaterna 77)
  (es-familiar Felipe Luque Polonio AbueloMaterno 78)
  (es-familiar Francisca Marquez Ramirez AbuelaMaterna 76)
)


;Representacion mediante hechos no ordenados

(deffacts familia2
  (familiar (apellido1 "Medina") (apellido2 "Sanchez") (nombre "Ana") (parentesco "Hija") (edad 27))
  (familiar (apellido2 "Rodriguez") (apellido1 "Sanchez") (nombre "Ramon") (parentesco "AbueloMaterno") (edad 89))
  (familiar (nombre "Pilar") (apellido1 "Sanchez") (apellido2 "Benitez") (edad 50) (parentesco "Madre"))
  (familiar (nombre "Manuel") (edad 48) (apellido2 "Rovira") (apellido1 "Medina") (parentesco "Padre"))
  (familiar (edad 26) (apellido1 "Medina") (apellido2 "Sanchez") (parentesco "Hijo") (nombre "Marcos"))
)
