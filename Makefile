SRCS = demo.o mcp23017.o
PROG := demo
LIBS = -lm -lpthread

CFLAGS += -O2 -g -Wall -DNV_IS_LDK=1 $(ARCH_CFLAGS) `$(PKG-CONFIG) --cflags libsoc` --sysroot=$(OECORE_TARGET_SYSROOT) -I$(OECORE_TARGET_SYSROOT)include
LDFLAGS += `$(PKG-CONFIG) --libs libsoc`

CC = gcc
LD = ld
STRIP = strip
RM = rm -f
PKG-CONFIG = pkg-config
ARCH_CFLAGS =

# Sets the output filename and object files
PROG := $(PROG)$(BIN_POSTFIX)
OBJS = $(SRCS:.c=$(BIN_POSTFIX).o)
DEPS = $(OBJS:.o=.o.d)

# pull in dependency info for *existing* .o files
-include $(DEPS)

.DEFAULT_GOAL := all

all: $(PROG)

$(PROG): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LDFLAGS) -o $@
	$(STRIP) $@

%$(BIN_POSTFIX).o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
	$(CC) -MM $(CFLAGS) $< > $@.d

clean:
	$(RM) $(OBJS) $(PROG) $(DEPS)

.PHONY: all clean

