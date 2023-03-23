# LogicSimulatorCircuit
Create logic gate simulator using C++ and OOP concepts. 
When given a series of logical inputs, randomly generate circuit, execute the circuit and finally give the output of the circuit.


**How to run**

**Linux**

1 - make
2 - ./app


**Windows**

1 - g++ -std==c++14 -c nodes.h nodes.cpp
2 - g++ -std==c++14 -c gates.h gates.cpp
3 - g++ -std==c++14 -c circuit.h circuit.cpp
4 - g++ -std==c++14 -c main.h main.cpp
5 - g++ -std==c++14 -o app nodes.o gates.o circuit.o
6 - ./app
