_VERSION = 0.4
VERSION  = `git describe --tags --dirty 2>/dev/null || echo $(_VERSION)`

PKG_CONFIG = pkg-config

# paths
PREFIX = /usr
MANDIR = $(PREFIX)/share/man

XWAYLAND =
XLIBS =
