st singlethreaded:
	# Linux on M1, Intel
	gcc -g -O1 -DSINGLETHREADED -Wall --pedantic -fsanitize=address -fno-omit-frame-pointer main.c actors.c sdf.c fifo.c -o singlethreaded
	@# may need to add -lpthread on some platforms

mt multithreaded:
	# Linux on M1, Intel
	gcc -g -O1 -DMULTITHREADED -Wall --pedantic -fsanitize=thread -fno-omit-frame-pointer main.c actors.c sdf.c fifo.c -o multithreaded
	@# may need to add -lpthread on some platforms; can also -fsanitize=thread

singlethreaded-pynq:
	# Linux on Arm on PYNQ - without ASAN
	gcc -g -O1 -DSINGLETHREADED -Wall --pedantic main.c actors.c sdf.c fifo_singlethreaded64bit.c -o singlethreaded

multithreaded-pynq:
	# Linux on Arm on PYNQ - without ASAN
	gcc -g -O1 -DMULTITHREADED -Wall --pedantic main.c actors.c sdf.c fifo_multithreaded.c -o multithreaded -lpthread

singlethreaded-compsoc multithreaded-compsoc:
	# use the CompSOC makefile/flow

clean:
	rm -rf *.o a.out a.out.dSYM singlethreaded singlethreaded.dSYM multithreaded multithreaded.dSYM
