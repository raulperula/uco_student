;file   p01ej07.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

(deftemplate infoAlumno
  (multislot apellidos (type STRING) (default ?NONE))
  (multislot nombre (type STRING) (default ?NONE))
  (multislot integrantesGrupo (type STRING))
  (slot numIntegGrupo (type INTEGER) (range 1 4))
  (slot notaExamen1 (type NUMBER) (range 0 10))
  (slot notaExamen2 (type NUMBER)(range 0 10))
  (slot notaMediaExamenes (type NUMBER) (range 0 10))
  (slot notaTrabajo (type NUMBER) (range 0 10))
)
