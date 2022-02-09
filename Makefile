
all:Milestone.cpp main.cpp
	 g++ Milestone.cpp main.cpp -o preprocess
	 g++ Milesotne.cpp main2.cpp -o encode 


clean:
		rm -f *.o
		rm preprocess
