CFLAGS=-std=c++11 -Wall -Wextra -Wshadow -g

main: main.o Gate.o AND.o OR.o True.o False.o
	g++ -o main Gate.o AND.o OR.o True.o False.o main.o $(CFLAGS)

Gate.o: Gate.cpp Gate.h
	g++ -c Gate.cpp $(CFLAGS)

AND.o: AND.cpp AND.h
	g++ -c AND.cpp $(CFLAGS)

OR.o: OR.cpp OR.h
	g++ -c OR.cpp $(CFLAGS)

True.o: True.cpp True.h
	g++ -c True.cpp $(CFLAGS)

False.o: False.cpp False.h
	g++ -c False.cpp $(CFLAGS)

main.o: main.cpp
	g++ -c main.cpp $(CFLAGS)

clean:
	@echo "Removing unnecessary files..."
	rm Gate.o
	rm AND.o
	rm OR.o
	rm True.o
	rm False.o
	rm main.o
	rm main
	@echo "Done."