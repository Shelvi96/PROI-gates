CFLAGS=-std=c++11 -Wall -Wextra -Wshadow -fsanitize=address -D_GLIBCXX_DEBUG

main: main.o Gate.o NOT.o AND.o NAND.o OR.o NOR.o XOR.o True.o False.o
	g++ -o main Gate.o NOT.o AND.o NAND.o OR.o NOR.o XOR.o True.o False.o main.o $(CFLAGS)

Gate.o: Gate.cpp Gate.h
	g++ -c Gate.cpp $(CFLAGS)

NOT.o: NOT.cpp NOT.h
	g++ -c NOT.cpp $(CFLAGS)

AND.o: AND.cpp AND.h
	g++ -c AND.cpp $(CFLAGS)

NAND.o: NAND.cpp NAND.h
	g++ -c NAND.cpp $(CFLAGS)

OR.o: OR.cpp OR.h
	g++ -c OR.cpp $(CFLAGS)

NOR.o: NOR.cpp NOR.h
	g++ -c NOR.cpp $(CFLAGS)

XOR.o: XOR.cpp XOR.h
	g++ -c XOR.cpp $(CFLAGS)

True.o: True.cpp True.h
	g++ -c True.cpp $(CFLAGS)

False.o: False.cpp False.h
	g++ -c False.cpp $(CFLAGS)

main.o: main.cpp
	g++ -c main.cpp $(CFLAGS)

clean:
	@echo "Removing unnecessary files..."
	rm Gate.o
	rm NOT.o
	rm AND.o
	rm NAND.o
	rm OR.o
	rm NOR.o
	rm XOR.o
	rm True.o
	rm False.o
	rm main.o
	rm main
	@echo "Done."