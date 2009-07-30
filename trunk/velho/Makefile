# "Velho" Makefile for Linux/Unix

# SDL
SDLFLAGS = `sdl-config --cflags`
SDLLIBS =`sdl-config --libs`

# LibLO (OSC)
LIBLOFLAGS = `pkg-config liblo --cflags`
LIBLOLIBS = `pkg-config liblo --libs`

# General build opts
BUILDOPTS = -O2 -Wall -Isrc

# ---- stuff ----

objects = main.o draw.o oscstuff.o

VPATH = src

# ---- program ----
.PHONY: clean all

all: velho

velho: $(objects)
	gcc -o $@ $^ $(SDLLIBS) $(LIBLOLIBS)

main.o: main.c oscstuff.h
	gcc -o $@ -c $< $(BUILDOPTS) $(SDLFLAGS) $(LIBLOFLAGS)

oscstuff.o: oscstuff.c main.h draw.h structs.h
	gcc -o $@ -c $< $(BUILDOPTS) $(SDLFLAGS) $(LIBLOFLAGS)

draw.o: draw.c
	gcc -o $@ -c $< $(BUILDOPTS) $(SDLFLAGS)

clean:
	rm -rf velho velho.exe stdout.txt stderr.txt *.o


