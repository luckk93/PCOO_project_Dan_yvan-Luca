set multiplot layout 1,2
plot "waveforms.dat" using 2 with lines title 'ValPhen', "waveforms.dat" using 3 with lines title 'ValEtat', "waveforms.dat" using 4 with lines title 'ValCtrl'
plot "waveforms.dat" using 5 with lines title 'ValPhen', "waveforms.dat" using 6 with lines title 'ValEtat', "waveforms.dat" using 7 with lines title 'ValCtrl'
pause -1
