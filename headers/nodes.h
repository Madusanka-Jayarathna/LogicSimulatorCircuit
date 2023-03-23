#pragma once

class Node
{
    protected:
        bool *value = nullptr;

    public:
        bool getValue();
        void setValue(bool value);
        void cleanUpNodes();
        virtual ~Node();
};

class InputNode : public Node
{
    public:
        InputNode();
        ~InputNode();
};

class OutputNode : public Node
{
    public:
        OutputNode();
        ~OutputNode();
};
