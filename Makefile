GF = gfortran
chain = iritest_sub.for irisub.for irifun.for iritec.for iridreg.for igrf.for cira.for iriflip.for
iri2:   c_wrap.o $(chain)
	$(GF) -o iri2 c_wrap.o  $(chain)

