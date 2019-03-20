Lab10: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o Lab10

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp LeftistOrSkewInterface.h Leftist_Node.hpp Leftist_Node.h Leftist_Tree.hpp Leftist_Tree.h Skew_Node.hpp Skew_Node.h Skew_Tree.hpp Skew_Tree.h Queue.hpp Queue.h Node.hpp Node.h
	g++ -g -std=c++11 -c Executive.cpp
	
clean:
	rm *.o Lab10

