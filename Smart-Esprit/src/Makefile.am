## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = smartf

smartf_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	mahdi_fonction.c mahdi_fonction.h \
	mahdi_callbacks.c mahdi_callbacks.h \
	khaled_user.c khaled_user.h \
	khaled_callbacks.c khaled_callbacks.h \
	safa_fonction.c safa_fonction.h \
	safa_callbacks.c safa_callbacks.h \
	rania_fonction.c rania_fonction.h \
	rania_callbacks.c rania_callbacks.h \
	raies_callbacks.c raies_callbacks.h \
	raies_reclamation.c raies_reclamation.h \
	maysa_callbacks.c maysa_callbacks.h \
	maysa_fonction.c maysa_fonction.h

smartf_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)
AM_LDFLAGS = -L/usr/lib
smartf_LDADD += -lcurl

