do for [i=1:10] {set linestyle 2*i-1 lt 1 dt 4 lc i}
do for [i=1:10] {set linestyle 2*i lt 1 lw 3 lc i} 
set title "EDP for March 4, 2021 at 2300UTC"
set ylabel "Altitude(km)"
set xlabel "Plasma Frequency(MHz)"
#set terminal pdfcairo pdfcairo enhanced font "Helvetica,20"
#set terminal pdf size 11in,8in
set terminal qt
set output "iri_plot.pdf"
m="output.txt"
set grid

set key font ",32"
plot  m  using (sqrt($2/1.24e10)):1  with lines linestyle 2 notitle

#set terminal pdf size 11in,8in
#set output "iri_plot_1.pdf"
set terminal png
set output "iri_plot_1.png"
set key font ",24"
plot  m  using (sqrt($2/1.24e10)):1  with lines linestyle 2 notitle
