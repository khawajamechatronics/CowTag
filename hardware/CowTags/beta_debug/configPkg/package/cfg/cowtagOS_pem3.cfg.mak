# invoke SourceDir generated makefile for cowtagOS.pem3
cowtagOS.pem3: .libraries,cowtagOS.pem3
.libraries,cowtagOS.pem3: package/cfg/cowtagOS_pem3.xdl
	$(MAKE) -f C:\Users\Ivan\Documents\GitHub\72point5\hardware\CowTags/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\Ivan\Documents\GitHub\72point5\hardware\CowTags/src/makefile.libs clean
