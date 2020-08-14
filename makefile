#
#
all: Rolo

Rolo: Rolodex.o main.o Card.o RolodexConsole.o Console.o
	g++ -std=c++11 -lrt -pthread -g Rolodex.o main.o Card.o RolodexConsole.o Console.o

Rolodex.o: Rolodex.cpp Rolodex.h
	g++ -Wall -std=c++11 -lrt -pthread -g -c Rolodex.cpp

main.o: main.cpp
	g++ -std=c++11 -lrt -pthread -g -c main.cpp

Card.o: Card.cpp Card.h
	g++ -Wall -std=c++11 -lrt -pthread -g -c Card.cpp

RolodexConsole.o: RolodexConsole.cpp RolodexConsole.h
	g++ -std=c++11 -lrt -pthread -g -c RolodexConsole.cpp

Console.o: Console.cpp Console.h
	g++ -std=c++11 -lrt -pthread -g -c Console.cpp

clean:
	rm -rf *.o Rolodex
