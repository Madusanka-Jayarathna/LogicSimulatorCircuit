#include "../headers/gates.h"

std::vector<InputNode> & Gate::getInputs()
{
    return this->input;    
}

bool Gate::getOutput()
{
    return this->output->getValue();
}

bool Gate::connect(Node *otherInputNode)
{
    if(otherInputNode != nullptr)
    {
        delete output;
        this->newFlag = false;
        output = (OutputNode*)otherInputNode;
        return true;
    }
    return false;
}

const std::string& Gate::getName() const
{
    return this->Name;
}

const short Gate::getSelector() const
{
    return -1;
}

void Gate::cleanUpGates()
{
    for(int i=0; i<InputSize; i++)
        this->input[i].cleanUpNodes();
    
    this->output->cleanUpNodes();
    
    if(this->newFlag)
        delete output;
}

Gate::~Gate(){};

////////////// AND-GATE ////////////////////
AND::AND()
{
    InputSize = 2;
    Name = "AND";
    input = std::vector<InputNode>(2);
    output = new OutputNode();
}

AND::AND(short inputSize)
{
    Name = "AND";
    InputSize = inputSize;
    input = std::vector<InputNode>(inputSize);
    output = new OutputNode();
}

void AND::execute()
{
    bool out = input.at(0).getValue();
    if(this->InputSize > 1)
    {
        for(int i=1 ; i < this->InputSize; i++)
            out = out && input.at(i).getValue();
    }
    
    output->setValue(out);
}

AND::~AND()
{
    // Empty    
}

///////////// OR-GATE //////////////
OR::OR()
{
    Name = "OR";
    InputSize = 2;
    input = std::vector<InputNode>(2);
    output = new OutputNode();      
}

OR::OR(short inputSize)
{
    Name = "OR";
    InputSize = inputSize;
    input = std::vector<InputNode>(inputSize);
    output = new OutputNode();
}

void OR::execute()
{
    bool out = input.at(0).getValue();
    if(this->InputSize > 1)
    {
        for(int i=1 ; i < this->InputSize; i++)
            out = out || input.at(i).getValue();
    }
    
    output->setValue(out);
}

OR::~OR()
{
    // Empty
}

//////////// NAND-Gate ////////////////
NAND::NAND()
{
    Name = "NAND";
    InputSize = 2;
    input = std::vector<InputNode>(2);
    output = new OutputNode();      
}

NAND::NAND(short inputSize)
{
    Name = "NAND";
    InputSize = inputSize;
    input = std::vector<InputNode>(inputSize);
    output = new OutputNode();
}

void NAND::execute()
{
    bool out = input.at(0).getValue();
    if(this->InputSize > 1)
    {
        for(int i=1 ; i < this->InputSize; i++)
            out = out && input.at(i).getValue();
    }
    
    output->setValue(!out);
}

NAND::~NAND()
{
    // Empty
}

///////////// NOR-GATE //////////////
NOR::NOR()
{
    Name = "NOR";
    InputSize = 2;
    input = std::vector<InputNode>(2);
    output = new OutputNode();      
}

NOR::NOR(short inputSize)
{
    Name = "NOR";
    InputSize = inputSize;
    input = std::vector<InputNode>(inputSize);
    output = new OutputNode();
}

void NOR::execute()
{
    bool out = input.at(0).getValue();
    if(this->InputSize > 1)
    {
        for(int i=1 ; i < this->InputSize; i++)
            out = out || input.at(i).getValue();
    }
    
    output->setValue(!out);
}

NOR::~NOR()
{
    // Empty     
}

///////////// XOR-GATE //////////////
XOR::XOR()
{
    Name = "XOR";
    InputSize = 2;
    input = std::vector<InputNode>(2);
    output = new OutputNode();      
}

XOR::XOR(short inputSize)
{
    Name = "XOR";
    InputSize = inputSize;
    input = std::vector<InputNode>(inputSize);
    output = new OutputNode();
}

void XOR::execute()
{
    bool out = input.at(0).getValue();
    if(this->InputSize > 1)
    {
        for(int i=1 ; i < this->InputSize; i++)
            out = out ^ input.at(i).getValue();       
    }
    
    output->setValue(out);
}

XOR::~XOR()
{
    // Empty
}

///////////// XNOR-GATE //////////////
XNOR::XNOR()
{
    Name = "XNOR";
    InputSize = 2;
    input = std::vector<InputNode>(2);
    output = new OutputNode();      
}

XNOR::XNOR(short inputSize)
{
    Name = "XNOR";
    InputSize = inputSize;
    input = std::vector<InputNode>(inputSize);
    output = new OutputNode();
}

void XNOR::execute()
{
    bool out = input.at(0).getValue();
    if(this->InputSize > 1)
    {
        for(int i=1 ; i < this->InputSize; i++)
            out = out ^ input.at(i).getValue();       
    }
    
    output->setValue(!out);
}

XNOR::~XNOR()
{
    // Empty
}

///////////// BUFFER //////////////
BUFFER::BUFFER()
{
    Name = "BUFFER";
    input = std::vector<InputNode>(1);
    InputSize = 1;
    output = new OutputNode();      
}

void BUFFER::execute()
{
    output->setValue(input.at(0).getValue());
}

BUFFER::~BUFFER()
{
    // Empty
}

///////////// NOT-GATE //////////////
NOT::NOT()
{
    Name = "NOT";
    InputSize = 1;
    input = std::vector<InputNode>(1);
    output = new OutputNode(); 
}

void NOT::execute()
{
    output->setValue(!(input.at(0).getValue()));
}

NOT::~NOT()
{
    // Empty
}

///////////// MUX //////////////
MUX::MUX(const short& selector)
{
    Name = "MUX";
    Selector = selector;
    InputSize = 2;
    input = std::vector<InputNode>(2);
    output = new OutputNode();   
}
    
void MUX::execute()
{
    bool out = input.at(0).getValue();
    if(InputSize==2)
        out = this->Selector ? input.at(1).getValue():input.at(0).getValue();
    
    output->setValue(out);
}

const short MUX::getSelector() const
{
    return this->Selector;
}

MUX::~MUX()
{
    // Empty
}
