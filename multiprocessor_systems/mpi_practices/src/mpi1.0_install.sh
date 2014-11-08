#!/bin/bash

#preguntar si maestro o esclavo
echo "maestro? (y/n)"
read RES
while [[ $RES != y && $RES != n ]]; do
	echo "maestro? (y/n)"
	read RES
done

# desinstalar lam-runtime y lsh-server
echo "Desinstalacion de paquetes incompatibles..."
sudo apt-get remove lam-runtime lsh-server
echo "Realizado"
echo

# instalar openssh-server
echo "Instalacion de paquetes necesarios..."
sudo apt-get install openssh-server
sudo apt-get install mpich-bin mpi-doc
echo "Realizado"
echo

# actualizar /etc/hosts con las ips y los nombres de los esclavos
echo "Actualizar hosts con IPs y nombres de esclavos..."
echo "/etc/hosts (poner al final):"
echo "192.168.112.xxx master"
echo "192.168.112.xxx esclavo1"
echo "192.168.112.xxx esclavo2"
sudo gedit /etc/hosts
echo "Realizado"
echo

# crear /etc/mpich/machines.LINUX con los equipos (indicando si hay más de un procesador)
echo "Crear fichero machines.LINUX..."
echo "/etc/mpich/machines.LINUX:"
echo "master"
echo "esclavo1"
echo "esclavo2:2"
echo "(el esclavo 2 tendria 2 procesadores)"
sudo gedit /etc/mpich/machines.LINUX
echo "Realizado"
echo

# preparar los equipos (tanto local como esclavos) para no pedir la clave
# crear la clave público/privada
echo "Creacion de clave publica..."
ssh-keygen -t rsa -f ~/.ssh/id_rsa
echo "Realizado"
echo

# pasar la clave pública al equipo dentro del fichero authorized_keys
if [ $RES = y ]; then
	echo "Pasar la clave publica a los equipos esclavos..."
	echo "Abrir otra terminal y hacer la siguiente instruccion"
	echo "scp ~/.ssh/id_rsa.pub atc@esclavoN:~/.ssh/id_rsa.pub.master"
	echo
	echo "Pulsa enter para continuar"
	read

	# ssh al esclavo para conectar la primera vez
	echo "Hacer ssh a los esclavos..."
	echo "Hacer la siguiente instruccion para cada esclavo"
	echo "ssh atc@esclavoN"
	echo
	echo "Pulsa enter para continuar"
	read
fi

# en el esclavo
if [ $RES = n ]; then
	echo "Salida de las claves de autorizacion..."
	cat ~/.ssh/id_rsa.pub.master >> ~/.ssh/authorized_keys
	echo "Realizado"
	echo
fi

# para probarlo ejecutar ssh al otro equipo
echo "ssh atc@esclavo1"
echo

echo "Pulsar para finalizar..."
read
