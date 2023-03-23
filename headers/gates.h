#pragma once
#include "nodes.h"
#include <iostream>
#include <vector>

class Gate
{
    protected:
        bool newFlag = true;
        std::string Name;
        short InputSize;
        std::vector<InputNode> input;
        OutputNode *output = nullptr;
        
    public:
        std::vector<InputNode> &getInputs();
        bool getOutput();
        bool connect(Node *otherInputNode);
        const std::string& getName() const;
        virtual const short getSelector() const;
        virtual void execute() = 0;
        void cleanUpGates();
        virtual ~Gate();
};

////////////// AND-GATE ////////////////////
class AND : public Gate
{
     public:
        AND();
        AND(short inputSize);
        void execute() override;
        ~AND();
};

///////////// OR-GATE //////////////
class OR : public Gate
{
     public:
        OR();
        OR(short inputSize);
        void execute() override;
        ~OR();
};

//////////// NAND-Gate ////////////////
class NAND : public Gate
{
    public:
        NAND();
        NAND(short inputSize);
        void execute() override;
        ~NAND();
};

///////////// NOR-GATE //////////////
class NOR : public Gate
{
     public:
        NOR();
        NOR(short inputSize);
        void execute() override;
        ~NOR();
};

///////////// XOR-GATE //////////////
class XOR : public Gate
{
     public:
        XOR();
        XOR(short inputSize);
        void execute() override;
        ~XOR();
};

///////////// XNOR-GATE //////////////
class XNOR : public Gate
{
     public:
        XNOR();
        XNOR(short inputSize);
        void execute() override;
        ~XNOR();
};

///////////// BUFFER //////////////
class BUFFER : public Gate
{
     public:
        BUFFER();
        void execute() override;
        ~BUFFER();
};

///////////// NOT-GATE //////////////
class NOT : public Gate
{
     public:
        NOT();
        void execute() override;
        ~NOT();
};


///////////// MUX //////////////
class MUX : public Gate
{
     private:
        short Selector;

    public:
        MUX(const short& selector);
        void execute() override;
        const short getSelector() const;
        ~MUX();
};
