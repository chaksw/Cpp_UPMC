CXX = g++
CXXFLAGS = -Wall -Wextra -Werror

all : tp4
tp3: tp4.o CBasePile.o CPileFifo.o CPileLifo.o
		$(CXX) -o main main.o CBasePile.o CPileFifo.o CPileLifo.o
		
main.o: tp4.cpp 
		g++ $(CXXFLAGS) -c main.cpp

CBasePile.o: CBasePile.cpp
			g++ $(CXXFLAGS) -c CBasePile.cpp
			
CPileFifo.o: CPileFifo.cpp
			g++ $(CXXFLAGS) -c CPileFifo.cpp
			
CPileLifo.o: CPileLifo.cpp
			g++ $(CXXFLAGS) -c CPileLifo.cpp
			
clean:
		rm *.o
		rm tp4