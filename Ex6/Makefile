
CXX=clang++-5.0
CXXFLAGS=-std=c++14 -Wall -Werror -Wvla

all: Board.o ObjBoard.o main.o
	$(CXX) Board.o ObjBoard.o main.o -o a.out
	echo compiled to file a.out
	make clean
	./a.out

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

ObjBoard.o: ObjBoard.cpp ObjBoard.hpp
	$(CXX) $(CXXFLAGS) -c ObjBoard.cpp -o ObjBoard.o

clean:
	rm *.o
	echo Clean done