CPP=g++

all: day1

clean_day1:
	rm day1/day1
	rm day1/*.o 

day1: day1.o
	${CPP} day1/day1.o -o day1/day1 

day1.o:
	${CPP} -c day1/day1.cpp -o day1/day1.o

clean: clean_day1
