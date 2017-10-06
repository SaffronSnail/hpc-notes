.PHONY: run-parallel run-serial both

both: parallel.out serial.out

run-parallel: parallel.out
run-serial: serial.out

parallel.out: parallel.c
	gcc -fopenmp $^ -o $@

run-serial: serial.out
	./serial.out

serial.out: serial.c
	gcc $^ -o $@

