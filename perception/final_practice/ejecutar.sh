
#### Histogramas imagenes iniciales ####

#./canny.exe -i cafe.pgm -o cafeH.hist -H -n
#./canny.exe -i kid.pgm -o kidH.hist -H -n
#./canny.exe -i lena.pgm -o lenaH.hist -H -n
#./canny.exe -i leopard.pgm -o leopardH.hist -H -n
#./canny.exe -i milka.pgm -o milkaH.hist -H -n
#./canny.exe -i photo.pgm -o photoH.hist -H -n
#./canny.exe -i tools.pgm -o toolsH.hist -H -n
#./canny.exe -i tower.pgm -o towerH.hist -H -n
#./canny.exe -i w.pgm -o wH.hist -H -n

#### Histogramas de imagenes con sobel aplicado ####

#./canny.exe -i cafeS.pgm -o cafeSH.hist -H -n
#./canny.exe -i kidS.pgm -o kidSH.hist -H -n
#./canny.exe -i lenaS.pgm -o lenaSH.hist -H -n
#./canny.exe -i leopardS.pgm -o leopardSH.hist -H -n
#./canny.exe -i milkaS.pgm -o milkaSH.hist -H -n
#./canny.exe -i photoS.pgm -o photoSH.hist -H -n
#./canny.exe -i toolsS.pgm -o toolsSH.hist -H -n
#./canny.exe -i towerS.pgm -o towerSH.hist -H -n
#./canny.exe -i wS.pgm -o wSH.hist -H -n

#### Histogramas de imagenes con canny aplicado ####

./canny.exe -i cafeC75-95.pgm -o cafe75-95H.hist -H -n
./canny.exe -i kidC75-95.pgm -o kidC75-95H.hist -H -n
./canny.exe -i lenaC45-85.pgm -o lenaC45-85H.hist -H -n
./canny.exe -i leopardC45-75.pgm -o leopardC45-75H.hist -H -n
./canny.exe -i milkaC55-95.pgm -o milkaC55-95H.hist -H -n
./canny.exe -i photoC45-85.pgm -o photoC45-85H.hist -H -n
./canny.exe -i toolsC85-95.pgm -o toolsC85-95H.hist -H -n
./canny.exe -i towerC55-65.pgm -o towerC55-65H.hist -H -n
./canny.exe -i wC85-95.pgm -o wC85-95H.hist -H -n

#### Creacion de imagenes aplicando canny y sobel ####

#./canny.exe -i cafe.pgm -o cafeC65-75.pgm -c 65 75
#./canny.exe -i cafe.pgm -o cafeC75-95.pgm -c 75 95
#./canny.exe -i cafe.pgm -o cafeC65-95.pgm -c 65 95
#./canny.exe -i cafe.pgm -o cafeS.pgm -s

#./canny.exe -i kid.pgm -o kidC5-65.pgm -c 5 65
#./canny.exe -i kid.pgm -o kidC5-95.pgm -c 5 95
#./canny.exe -i kid.pgm -o kidC75-95.pgm -c 75 95
#./canny.exe -i kid.pgm -o kidS.pgm -s

#./canny.exe -i lena.pgm -o lenaC5-65.pgm -c 5 65
#./canny.exe -i lena.pgm -o lenaC45-85.pgm -c 45 85
#./canny.exe -i lena.pgm -o lenaC55-95.pgm -c 55 95
#./canny.exe -i lena.pgm -o lenaS.pgm -s

#./canny.exe -i leopard.pgm -o leopardC5-65.pgm -c 5 65
#./canny.exe -i leopard.pgm -o leopardC45-75.pgm -c 45 75
#./canny.exe -i leopard.pgm -o leopardC55-95.pgm -c 55 95
#./canny.exe -i leopard.pgm -o leopardS.pgm -s

#./canny.exe -i milka.pgm -o milkaC5-65.pgm -c 5 65
#./canny.exe -i milka.pgm -o milkaC45-85.pgm -c 45 85
#./canny.exe -i milka.pgm -o milkaC55-95.pgm -c 55 95
#./canny.exe -i milka.pgm -o milkaS.pgm -s

#./canny.exe -i photo.pgm -o photoC5-65.pgm -c 5 65
#./canny.exe -i photo.pgm -o photoC45-85.pgm -c 45 85
#./canny.exe -i photo.pgm -o photoC55-95.pgm -c 55 95
#./canny.exe -i photo.pgm -o photoS.pgm -s

#./canny.exe -i tools.pgm -o toolsC5-65.pgm -c 5 65
#./canny.exe -i tools.pgm -o toolsC85-95.pgm -c 85 95
#./canny.exe -i tools.pgm -o toolsC55-95.pgm -c 55 95
#./canny.exe -i tools.pgm -o toolsS.pgm -s

#./canny.exe -i tower.pgm -o towerC5-65.pgm -c 5 65
#./canny.exe -i tower.pgm -o towerC55-65.pgm -c 55 65
#./canny.exe -i tower.pgm -o towerC55-95.pgm -c 55 95
#./canny.exe -i tower.pgm -o towerS.pgm -s

#./canny.exe -i w.pgm -o wC5-65.pgm -c 5 65
#./canny.exe -i w.pgm -o wC5-95.pgm -c 5 95
#./canny.exe -i w.pgm -o wC85-95.pgm -c 85 95
#./canny.exe -i w.pgm -o wS.pgm -s

