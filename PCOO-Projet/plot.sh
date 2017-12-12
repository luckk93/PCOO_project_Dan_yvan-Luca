set multiplot layout 2,1
set title "Chamber"
set xlabel "Time/15 [min]"
set ylabel "Temperature [°C]"
set grid
plot "waveforms.dat" using 2 with lines title 'ValPhen', "waveforms.dat" using 3 with lines title 'ValEtat', "waveforms.dat" using 4 with lines title 'ValCtrl'
set title "Aquarium"
set xlabel "Time/15 [min]"
set ylabel "pH"
plot "waveforms.dat" using 5 with lines title 'ValPhen', "waveforms.dat" using 6 with lines title 'ValEtat', "waveforms.dat" using 7 with lines title 'ValCtrl'
pause -1
