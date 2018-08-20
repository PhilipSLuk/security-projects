#/*
#	Makefile for setdllcharacteristics
#	Source code put in public domain by Didier Stevens, no Copyright
#	https://DidierStevens.com
#	Use at your own risk
#
#	Developed with Borland's free C++ compiler: http://cc.codegear.com/Free.aspx?id=24778
#
#	Shortcomings, or todo's ;-)
#	
#	History:
#		2010/10/04: Start
#*/

BCC = $(MAKEDIR)\..
CFLAGS = -lGz -DINCLUDE_RESOURCE -I$(BCC)\include -L$(BCC)\lib
TARGETS_SIGN = setdllcharacteristics.exe
TARGETS = $(TARGETS_SIGN)

.autodepend

AllFiles: $(TARGETS) 

#TARGETS_SIGN

setdllcharacteristics.exe: setdllcharacteristics.c setdllcharacteristics.res

setdllcharacteristics.res: setdllcharacteristics.rc

clean-up:
	del *.bak *.obj *.tds *.res *.map
	
delete-targets:
	del $(TARGETS)

sign:
	$(MYDIRS)\bin\setdllcharacteristics +d +n $(TARGETS_SIGN)
	$(MYDIRS)\bin\signtool sign /sha1 3B07071E62D456D6F943A0E33B51B4C9631938DF /t http://timestamp.verisign.com/scripts/timstamp.dll $(TARGETS_SIGN)
