set xrange[0 : 1.1]
set yrange [4: 7]
plot "datos.dat" index 1 with points 1, "datos.dat" index 2 with lines,\
"datos.dat" index 0 with points 3