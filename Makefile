# kotatko - a fluffy window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c kotatko.c util.c
OBJ = ${SRC:.c=.o}

all: options kotatko

options:
	@echo kotatko build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	@echo creating $@ from config.def.h
	@cp config.def.h $@

kotatko: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f kotatko ${OBJ} kotatko-${VERSION}.tar.gz

dist: clean
	@echo creating dist tarball
	@mkdir -p kotatko-${VERSION}
	@cp -R LICENSE Makefile README config.def.h config.mk \
		kotatko.1 drw.h util.h ${SRC} transient.c kotatko-${VERSION}
	@tar -cf kotatko-${VERSION}.tar kotatko-${VERSION}
	@gzip kotatko-${VERSION}.tar
	@rm -rf kotatko-${VERSION}

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f kotatko ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/kotatko
	@echo installing manual page to ${DESTDIR}${MANPREFIX}/man1
	@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	@sed "s/VERSION/${VERSION}/g" < kotatko.1 > ${DESTDIR}${MANPREFIX}/man1/kotatko.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/kotatko.1

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/kotatko
	@echo removing manual page from ${DESTDIR}${MANPREFIX}/man1
	@rm -f ${DESTDIR}${MANPREFIX}/man1/kotatko.1

.PHONY: all options clean dist install uninstall
