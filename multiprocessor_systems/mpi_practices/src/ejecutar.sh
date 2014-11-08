#ejecutar

clear

make clean
make

scp ~/Escritorio/practicasMPI/$1 slave1:~/Escritorio/practicasMPI/$1
scp ~/Escritorio/practicasMPI/$1 slave2:~/Escritorio/practicasMPI/$1

mpirun -np 6 $1
