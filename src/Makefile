NFLAGS=-lncurses
TABFLAGS=-lreadline

default: superchat

debug : CXXFLAGS +=-g
debug : default

superchat: tab.o
	${CXX} ${CXXFLAGS} -o superchat tab.o $(TABFLAGS) $(NFLAGS)

tab.o: tab.cpp
	${CXX} ${CXXFLAGS} -c tab.cpp $(TABFLAGS)

clean:
	-rm -rf *.gch *.o a.out superchat

