OBJECTS = limits.o types.o energy.o randSpin.o main.o

main: ${OBJECTS}
	g++ -o main ${OBJECTS}

limits.o: limits.cpp limits.h
	g++ -std=c++11 -c limits.cpp

types.o: types.cpp types.h
	g++ -std=c++11 -c types.cpp

energy.o: energy.cpp energy.h
	g++ -std=c++11 -c energy.cpp

randSpin.o: randSpin.cpp
	g++ -std=c++11 -c randSpin.cpp

main.o: main.cpp utilities.h
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o
	rm main
.PHONY: clean
