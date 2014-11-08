;file   t03ej01.clp
;brief
;author Raul Perula-Martinez
;date   2014-11

﻿(deftemplate cliente (slot nombre))

(defrule cambia-nombre-cliente
?f1<-(cliente (nombre juan))
=>
(modify ?f1 (nombre pedro)))

(assert (cliente (nombre juan)))
