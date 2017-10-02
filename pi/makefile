.PHONY: run-parallel run-serial

run-parallel: parallel.out

parallel.out: parallel.c
	gcc -fopenmp $^ -o $@

run-serial: serial.out
	./serial.out

serial.out: serial.c
	gcc $^ -o $@

