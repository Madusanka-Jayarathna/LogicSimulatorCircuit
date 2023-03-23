#include "../headers/circuit.h"
static int maxInputPortSize = 4;

Circuit::Circuit(int inputCount)
{
    InputCount = inputCount;
    Level = 1;
}

void Circuit::append(Gate *gate)
{
    this->elements.emplace_back(gate);    
}

void Circuit::addInputNodes(InputNode *Node)
{
    inputs.push_back(Node);    
}

void Circuit::execute(std::vector<bool> inputVector)
{
    for(int i = 0; i < inputs.size(); i++)
        inputs.at(i)->setValue(inputVector.at(i));    
    
    for(int i = 0; i < elements.size(); i++)
    {
        Gate *g = elements.at(i);
        g->execute();
    }
}

int Circuit::selectGates(std::vector<Gate*> &gates)
{
    int gateTypes = 9;
    int outputPorts = 0;
    while((this->InputCount)>0)
    {
        int randomGateSelector = rand() % gateTypes;
        short gateInputs = 2;
        short inputPortSize = 0;
        if((this->InputCount) > 1)
        {
            inputPortSize = ((this->InputCount) > maxInputPortSize) ? maxInputPortSize : this->InputCount;
            gateInputs = (rand() % (inputPortSize-1)) + 2;
        }
            
        Gate* selectedGate;
        switch(randomGateSelector)
        {
            case 0:
            {
                selectedGate = new AND(gateInputs);
                break;
            }
            case 1:
      {
                selectedGate = new OR(gateInputs);
                break;
            }
            case 2:
            {
                selectedGate = new NAND(gateInputs);
                break;
            }
            case 3:
            {
                selectedGate = new NOR(gateInputs);
                break;
            }
            case 4:
            {
                selectedGate = new XOR(gateInputs);
                break;
            }
            case 5:
            {
                selectedGate = new XNOR(gateInputs);
                break;
            }
            case 6:
            {
                selectedGate = new BUFFER();
                gateInputs = 1;
                break;
            }
            case 7:
            {
                selectedGate = new NOT();
                gateInputs = 1;
                break;
            }
            case 8:
            {
                const short sel = rand()%2;
                selectedGate = new MUX(sel);
                gateInputs = 2;
                break;
            }
            default:
            {
                gateInputs = 0;
                break;
            }
        }
            
        if(!gateInputs) 
            continue;
        else
        {
            if((gateInputs == 1 && ((this->InputCount) - 1 != 1)) || (gateInputs > 1 && ((this->InputCount) - gateInputs) >= 0))
            {
                this->append(selectedGate);
                gates.push_back(selectedGate);
                (this->InputCount) -= gateInputs;
                outputPorts++;
            }
            else
                delete selectedGate;    
        }
    }
    return outputPorts;
}

void Circuit::generateCircuit()
{   
    
    std::vector<Gate*>* gates = new std::vector<Gate*>;
    this->InputCount = selectGates(*gates);
    (this->levelMap).insert({this->Level, gates});
    if((this->InputCount) > 1)
    {
        (this->Level)++;
        generateCircuit();
    }
    return;
}

void Circuit::createCircuit()
{
    this->generateCircuit();
    for(int i=1; i<(this->Level);i++)
    {
        std::vector<Gate*>* currentLevelGates = this->levelMap[i];
        std::vector<Gate*>::iterator itr1 = currentLevelGates->begin();
        std::vector<Gate*>* nextLevelGates = this->levelMap[i+1];
        std::vector<Gate*>::iterator itr2 = nextLevelGates->begin();
        
        while(itr1 < currentLevelGates->end() && itr2 < nextLevelGates->end())
        {
            short inputSize = (*itr2)->getInputs().size();
            short k = 0;
            while(k < inputSize)
            {
                (*itr1)->connect(&((*itr2)->getInputs().at(k)));
                k++;
                itr1++;
            }
            itr2++;
        }

        if(i==1)
        {
            for(itr1=currentLevelGates->begin(); itr1<currentLevelGates->end();itr1++)
            {
                for(int i=0; i<((*itr1)->getInputs().size()); i++)
                    {
                        this->addInputNodes(&((*itr1)->getInputs().at(i)));    
                    }
            }
        }
    }       
}

void Circuit::printCircuit()
{
    printf("\n\n\n --------------- Logic Circuit --------------\n");
    printf  (" ==================== *** ===================\n");

    for(int i=1; i<(this->Level+1);i++)
    {
        printf("\n ---------------- Level %d -------------------\n",i);
        printf  (" --------------------------------------------\n",i);
        std::vector<Gate*>* currentLevelGates = this->levelMap[i];
        std::vector<Gate*>::iterator itr = currentLevelGates->begin();
        for(itr=currentLevelGates->begin(); itr<currentLevelGates->end(); itr++)
        {
            printf("Input(s) : ");
            int j = 0;
            for(j=0; j<((*itr)->getInputs().size()); j++)
                std::cout <<  (*itr)->getInputs().at(j).getValue() << " ";     
        
            std::cout << std::string(2*(maxInputPortSize-j),' ') << "output : " << (*itr)->getOutput() << "  ( " << (*itr)->getName() << " ) ";
            
            if((*itr)->getName() == "MUX")
                std::cout << " selector : " << (*itr)->getSelector();
        printf("\n");
    
        }
    }
    printf  ("\n ==================== *** ===================\n\n\n\n\n");
}

void Circuit::cleanTheTable()
{
    std::map<int, std::vector<Gate*>*>::iterator map_itr;
    for(map_itr = this->levelMap.begin(); map_itr != this->levelMap.end(); map_itr++)
    {
        std::vector<Gate*>* gates = map_itr->second;
        std::vector<Gate*>::iterator itr;
        for(itr = gates->begin(); itr < gates->end(); itr++)
        {
            (*itr)->cleanUpGates();
            delete (*itr);
             
        }
        delete gates;
    }
}

Circuit::~Circuit()
{
    this->cleanTheTable();    
}
