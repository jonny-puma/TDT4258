#
# Simple development makefile
#

#
# add more flags here,
# but don't remove the "+="
#
CFLAGS += -O2 -g -Wall -std=c99#-Wsign-compare -Wfloat-equal -Wformat-security #-Werror
LDFLAGS += -lm
CC = arm-cortexm3-uclinuxeabi-gcc

deps = game.h graphics.h
obj = game.o graphics.o

game : $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c $(deps)
	$(CC) -c -o $@ $< $(CLAGS)


all: game

clean:
	-rm -f game

install:


.PHONY: all install clean

# end of development makefile
