CC=g++
CXX=g++

CFLAGS=-g -Wall
CXXFLAGS=-g -Wall


chicken: chicken.o

chicken.o: chicken.cpp

.PHONY: clean
clean:
	rm -rf *.o chicken

.PHONY: all
all: clean chicken