main: limits.o types.o main.o
	g++ -o main limits.o main.o types.o

limits.o: limits.cpp limits.h
	g++ -std=c++11 -c limits.cpp

types.o: types.cpp types.h
	g++ -std=c++11 -c types.cpp

main.o: main.cpp utilities.h
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o
	rm main
.PHONY: clean
