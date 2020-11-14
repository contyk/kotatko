# kotatko - a fluffy window manager
# See LICENSE file for copyright and license details.

app = kotatko

cflags = -std=c99 -D_DEFAULT_SOURCE -Wall
ldflags = -lX11 -lXft -lfontconfig -lX11-xcb -lxcb -lxcb-res

CC ?= cc
CFLAGS ?= -march=native -Ofast -fgraphite-identity -floop-nest-optimize -fdevirtualize-at-ltrans -fipa-pta -fno-semantic-interposition -falign-functions=32 -flto=auto -fuse-linker-plugin -pipe
LDFLAGS ?= $(CFLAGS) -Wl,-O1 -Wl,--as-needed -Wl,--sort-common -Wl,--hash-style=gnu -z combreloc

ifdef DEBUG
	cflags += -g
else
	ldflags += -s
endif

prefix ?= /usr
exec_prefix ?= $(prefix)
includedir ?= $(prefix)/include
datarootdir ?= $(prefix)/share
bindir ?= $(exec_prefix)/bin
mandir ?= $(datarootdir)/man

includedirs = $(includedir) $(includedir)/freetype2
incs = $(foreach d,$(includedirs),-I$d)

src = $(wildcard *.c)
obj = $(src:.c=.o)

all: $(app)

$(app): $(obj)
	$(CC) -o $@ $^ $(ldflags) $(LDFLAGS)

config.h:
	cp config.def.h $@

%.o: %.c config.h
	$(CC) $(cflags) $(incs) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(obj) $(app)

install: $(app)
	mkdir -p \
		$(DESTDIR)$(bindir) \
		$(DESTDIR)$(mandir)/man1
	install -p -m0755 $(app) $(DESTDIR)$(bindir)/$(app)
	install -p -m0644 $(app).1 $(DESTDIR)$(mandir)/man1/$(app).1

uninstall:
	rm -f \
		$(DESTDIR)$(bindir)/$(app) \
		$(DESTDIR)$(mandir)/man1/$(app).1

check:
	@echo No test suite currently available.

.PHONY: all clean install uninstall
