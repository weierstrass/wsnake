# Makefile for WSnake
# Andreas Bülling, 2012

#Paths
TOPDIR = ..
SRCDIR = $(TOPDIR)/src
TESTDIR = $(SRCDIR)/tests

vpath %.cc $(SRCDIR)

# Objects
OBJS := main.o \
	aux.o \
	menu.o \
	button.o \
	gameplan.o \
	game.o \
	abstractview.o \
	about.o

# C++-compiler
CXX = g++

# Compiler options
CPPFLAGS = -O2

# Libraries
LIBS = -lm -lSDLmain -lSDL -lSDL_ttf

#misc for osx
OSX = -framework cocoa

#temp fix..

a.out: $(OBJS)
	$(CXX) -o $@ $(CPPFLAGS) $(OBJS) $(LIBS)

clean:
	rm -f a.out *.o