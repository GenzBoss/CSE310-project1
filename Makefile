
all:Milestone.cpp main.cpp main2.cpp
	 g++ -g Milestone.cpp main.cpp -o preprocess
	 g++ -g Milestone.cpp main2.cpp -o encode


clean:
	rm -f *.o
	rm preprocess
	rm encode