#pragma once
#include <map>
#include <iterator>
#include <iostream>
#include <time.h>
#include <vector>
#include "nodes.h"
#include "gates.h"

class Circuit
{
    private:
        int InputCount;
        int Level;
        std::vector<InputNode*> inputs = std::vector<InputNode*>();
        std::vector<Gate*> elements;
        std::map<int, std::vector<Gate*>*> levelMap;
        
        void append(Gate *gate);
        void addInputNodes(InputNode *Node);
        int selectGates(std::vector<Gate*> &gates);
        void generateCircuit();
        void cleanTheTable();

    public:
        Circuit(int inputCount);
        void createCircuit();
        void execute(std::vector<bool> inputVector);
        void printCircuit();
        ~Circuit();
};
