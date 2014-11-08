./ej.exe -i imgsegm1.pgm -o new.pgm -t 128
#./ej.exe -i imgsegm2.pgm -o n2.pgm -t 128

./ej.exe -i new.pgm -o new1.pgm -E 3
./ej.exe -i new.pgm -o new2.pgm -D 3
./ej.exe -i new.pgm -o new3.pgm -C 3
./ej.exe -i new.pgm -o new4.pgm -O 3
./ej.exe -i new4.pgm -o new5.pgm -c 3

#./ej.exe -i n2.pgm -o new1.pgm -E 3
#./ej.exe -i n2.pgm -o new2.pgm -D 3
#./ej.exe -i n2.pgm -o new3.pgm -C 3
#./ej.exe -i n2.pgm -o new4.pgm -O 3
#./ej.exe -i new.pgm -o new5.pgm -c 3
