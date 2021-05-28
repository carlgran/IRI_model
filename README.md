# IRI_model

Objective
Building a tool to extract an electron density profile at a given time and location using the IRI model Fortran source
code.


After downloading the source code and supporting data files from http://irimodel.org/, the following lines are written into a Makefile created
in the folder containing the downloaded files:

GF = gfortran
chain = iritest_sub.for irisub.for irifun.for iritec.for iridreg.for
igrf.for cira.for iriflip.for
iri2: c_wrap.o $(chain)
$(GF) -o iri2 c_wrap.o $(chain)

The variable ‘chain’ list the fortran files from the downloaded source code, except for ‘iritest_sub.for’. This file is
modified from the original ‘iritest.for’ which generates an interface to run the model interactively. Instead,
‘iritest_sub.for’ is a static version of ‘iritest.for’ made into a subroutine to be called by external programs.
The object file ‘c_wrap.o’ is built from the file ‘c_wrap.c’, which is an interface written in c that calls the
subroutine in ‘iritest_sub.for’ according to the user’s request that it reads from the file ‘request.txt’ .
Once the model is run the output of the simulation is printed in ‘output.txt’ which can then be used for plotting
and analysis of results.

User instructions
After downloading the source, index and data files from irimodel.org:
• Run Makefile. This will create the executable iri2.
• Open ‘request.txt’ and modify it according to the desired settings for the simulation.
• Run ./iri2. A table with the results will be printed in ‘output.txt’ . The first column (column 1) in this table
corresponds to the values generated for the chosen independent variable. Columns(2-20) corresponds to the
output set ‘outf’ which is described starting line 307 in file irisub.for and which includes results for electron and
other ions densities. Columns (21-100) correspond to the set of parameters ‘oarr’ also described in irisub.for
after line 331 and which includes peak values and shape factors.
• ‘iritest_sub.for’ generates the file fort.7, where it saves a standard output which also includes peak densities
and corresponding heights.
• For plotting use iri_plot_1.plt as a template. Modify it according to the requested settings a run it by typing :
gnuplot -p iri_plot_1.plt . A figure of the plot will be saved in a pdf or png file.
