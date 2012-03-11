# Makefile for WSnake
# Andreas Bülling, 2012

#Settings

# Objects
OBJS := main.o \
	aux.o \
	menu.o \
	button.o \
	gameplan.o \
	game.o

# C++-compiler
CXX = g++

# Compiler options
CPPFLAGS = -O2

# Libraries
LIBS = -lm -lSDLmain -lSDL -lSDL_ttf

#misc for osx
OSX = -framework cocoa

a.out: $(OBJS)
	$(CXX) -o $@ $(CPPFLAGS) $(OBJS) $(LIBS) $(OSX)

clean:
	rm -f a.out *.o