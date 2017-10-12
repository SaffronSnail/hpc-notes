FLAGS=-std=c++11 -Wall -Wextra -Werror

main.out: main.cpp serial.o timer.o parallel.o
	mkdir ${PREFIX}/bin
	g++ $^ ${FLAGS} -fopenmp -o ${PREFIX}/bin/$@

timer.o: timer.h timer.cpp
	g++ ${FLAGS} -c timer.cpp -o $@

parallel.o: parallel.cpp parallel.h
	g++ ${FLAGS} -fopenmp -c parallel.cpp -o $@

serial.o: serial.cpp serial.cpp
	g++ ${FLAGS} -c serial.cpp -o $@

