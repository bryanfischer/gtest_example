
all:
	@echo "No default: see make build and make test"

run:
	./prog_main

build:
	g++ -o prog_main main.cpp


test:
	g++ -o prog_test LinkedList_unittest.cpp -lgtest -lpthread && ./prog_test

deps:
	apt install libgtest-dev googletest

