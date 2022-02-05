
all:Milestone.cpp main.cpp
	 g++ Milestone.cpp main.cpp -o preprocess


clean:
		rm -f *.o
		rm preprocess