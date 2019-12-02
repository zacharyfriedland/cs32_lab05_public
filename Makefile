#Makefile

#CXX=clang++
CXX=g++
#CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

#at end change to: -std=c++11 -Wall -Wextra -Werror
BINARIES=lab05Test

all: ${BINARIES}

lab05Test: lab05Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

WordCount: WordCount.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o

