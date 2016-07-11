OBJECTS = limits.o readatomslinks.o temploop.o metropolis.o energy.o magnetization.o spin.o atoms.o links.o main.o
PROFILE = -O3

main: ${OBJECTS}
	g++ ${PROFILE} -o main ${OBJECTS}

limits.o: limits.cpp limits.h
	g++ -std=c++11 ${PROFILE} -c -Wall limits.cpp

readatomslinks.o: readatomslinks.cpp readatomslinks.h
	g++ -std=c++11 ${PROFILE} -c -Wall readatomslinks.cpp

temploop.o: temploop.cpp temploop.h
	g++ -std=c++11 ${PROFILE} -c -Wall temploop.cpp

metropolis.o: metropolis.cpp metropolis.h
	g++ -std=c++11 ${PROFILE} -c -Wall metropolis.cpp

energy.o: energy.cpp energy.h
	g++ -std=c++11 ${PROFILE} -c -Wall energy.cpp

magnetization.o: magnetization.cpp magnetization.h
	g++ -std=c++11 ${PROFILE} -c -Wall magnetization.cpp

spin.o: spin.cpp spin.h
	g++ -std=c++11 ${PROFILE} -c -Wall spin.cpp

atoms.o: atoms.cpp atoms.h
	g++ -std=c++11 ${PROFILE} -c -Wall atoms.cpp

links.o: links.cpp links.h
	g++ -std=c++11 ${PROFILE} -c -Wall links.cpp

main.o: main.cpp utilities.h
	g++ -std=c++11 ${PROFILE} -c -Wall main.cpp

clean:
	rm *.o
	rm main
.PHONY: clean
