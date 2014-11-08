#!/usr/bin/env python
# -*- coding: utf-8 -*-

__author__ = "Raul Perula-Martinez"
__email__ = "raul.perula@uc3m.es"
__date__ = "2014-11"
__license__ = "GPL v3"
__version__ = "1.0.0"

# Lee del puerto 9000

import socket

miSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
miSocket.connect((socket.gethostname(), 9000))

data, server = miSocket.recvfrom(100)
print data
miSocket.close()

