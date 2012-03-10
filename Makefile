# Makefile for WSnake
# Andreas Bülling, 2012

#Settings

# Objects
OBJS := main.o aux.o

# C++-compiler
CXX = g++

# Compiler options
CPPFLAGS = -O2

# Libraries
LIBS = -lm -lSDLmain -lSDL

#misc for osx
OSX = -framework cocoa

a.out: $(OBJS)
	$(CXX) -o $@ $(CPPFLAGS) $(OBJS) $(LIBS) $(OSX)

clean:
	rm -f a.out *.o