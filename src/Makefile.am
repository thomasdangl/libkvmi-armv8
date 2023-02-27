AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/include/linux/arm64

lib_LTLIBRARIES = libkvmi.la

libkvmi_la_SOURCES = kvmi.c
libkvmi_la_LDFLAGS = -luuid -pthread -version-number 1:0 \
	-Wl,--version-script,$(srcdir)/version.ld
