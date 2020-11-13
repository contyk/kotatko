# kotatko version
VERSION = 0.1

# Customize below to fit your system

# paths
PREFIX = /usr
MANPREFIX = ${PREFIX}/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# freetype
FREETYPELIBS = -lfontconfig -lXft
FREETYPEINC = /usr/include/freetype2
# OpenBSD (uncomment)
#FREETYPEINC = ${X11INC}/freetype2

# includes and libs
INCS = -I${X11INC} -I${FREETYPEINC}
LIBS = -L${X11LIB} -lX11 ${FREETYPELIBS} -lX11-xcb -lxcb -lxcb-res

# flags
CPPFLAGS = -D_DEFAULT_SOURCE -DVERSION=\"${VERSION}\"
CFLAGS   = -std=c99 -march=native -Ofast -fgraphite-identity -floop-nest-optimize -fdevirtualize-at-ltrans -fipa-pta -fno-semantic-interposition -falign-functions=32 -flto=8 -fuse-linker-plugin -pipe ${INCS} ${CPPFLAGS}
LDFLAGS  = ${CFLAGS} -s -Wl,-O1 -Wl,--as-needed -Wl,--sort-common -Wl,--hash-style=gnu -z combreloc ${LIBS}

# compiler and linker
CC = cc
