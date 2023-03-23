MAIN_DIR = ./main
HEADER_DIR = ./headers
CC = -std=c++14

all: app clean

app: nodes.o gates.o circuit.o main.o 
	g++ -o app main.o nodes.o gates.o circuit.o

main.o: $(MAIN_DIR)/main.cpp $(HEADER_DIR)/main.h
	g++ $(CC) -c $(MAIN_DIR)/main.cpp  

circuit.o: $(MAIN_DIR)/circuit.cpp $(HEADER_DIR)/circuit.h
	g++ $(CC) -c $(MAIN_DIR)/circuit.cpp

gates.o: $(MAIN_DIR)/gates.cpp $(HEADER_DIR)/gates.h
	g++ $(CC) -c $(MAIN_DIR)/gates.cpp

nodes.o: $(MAIN_DIR)/nodes.cpp $(HEADER_DIR)/nodes.h  
	g++ $(CC) -c $(MAIN_DIR)/nodes.cpp

clean:
	rm -rf *.o

.PHONY:clean
