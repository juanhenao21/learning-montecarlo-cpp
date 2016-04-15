OBJECTS = limits.o readatomslinks.o energy.o spin.o atoms.o links.o main.o

main: ${OBJECTS}
	g++ -o main ${OBJECTS}

limits.o: limits.cpp limits.h
	g++ -std=c++11 -c limits.cpp

readatomslinks.o: readatomslinks.cpp readatomslinks.h
	g++ -std=c++11 -c readatomslinks.cpp

energy.o: energy.cpp energy.h
	g++ -std=c++11 -c energy.cpp

spin.o: spin.cpp spin.h
	g++ -std=c++11 -c spin.cpp

atoms.o: atoms.cpp atoms.h
	g++ -std=c++11 -c atoms.cpp

links.o: links.cpp links.h
	g++ -std=c++11 -c links.cpp

main.o: main.cpp utilities.h
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o
	rm main
.PHONY: clean
