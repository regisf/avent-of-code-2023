CPP=g++ --std=c++20

all: day1 day2

clean_day1:
	rm day1/day1
	rm day1/*.o 

load_input.o:
	${CPP} -c common/load_input.cpp -o common/load_input.o

day1: day1.o load_input.o
	${CPP} common/load_input.o day1/day1.o -o day1/day1

day1.o:
	${CPP} -c day1/day1.cpp -o day1/day1.o

clean_day2:
	rm day2/day2
	rm day2/*.o

day2: day2.o load_input.o
	${CPP} common/load_input.o day2/day2.o -o day2/day2

day2.o:
	${CPP} -c day2/day2.cpp -o day2/day2.o

clean: clean_day1 clean_day2
