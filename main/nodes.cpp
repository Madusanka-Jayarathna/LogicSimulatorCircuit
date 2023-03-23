#include "../headers/nodes.h"

bool Node::getValue()
{
    if(this->value != nullptr)
        return *(this->value);
    return false;       
}

void Node::setValue(bool value)
{
    if(this->value == nullptr)
        this->value = new bool();
    *(this->value) = value;     
}

void Node::cleanUpNodes()
{
    if(this->value)
        delete this->value;
}

Node::~Node(){}

InputNode::InputNode(){}
InputNode::~InputNode()
{
    // Empty
}

OutputNode::OutputNode(){}
OutputNode::~OutputNode()
{
    // Empty  
}
