#example 1
#main: calc.o mylib.o
#	g++ -o a.exe calc.o mylib.o
#
#calc.o: calc.cpp
#	g++ -c calc.cpp
#
#mylib.o: mylib.cpp
#	g++ -c mylib.cpp




#example 2
#main: calc.cpp mylib.o
#	g++ -o a.exe calc.cpp mylib.o
#
#mylib.o: mylib.cpp
#	g++ -c mylib.cpp



#example 3
main: calc.o mylib.o
	g++ -o a.exe calc.o mylib.o

mylib.o: mylib.cpp
	g++ -c mylib.cpp

calc.o: calc.cpp
	g++ -c calc.cpp


