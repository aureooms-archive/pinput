

all: test-parse test-helper

test-parse: test-parse.cpp
	g++ -std=c++11 -o test-parse test-parse.cpp

test-helper: test-helper.cpp
	g++ -std=c++11 -o test-helper test-helper.cpp

clean:
	rm test-parse test-helper