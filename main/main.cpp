#include "../headers/main.h"

static void takeInputs(int &inputCount, std::vector<bool> &inputs)
{
    bool inputCondition = true;
    do
    {
        printf("No of inputs(should be greater than 0) : ");
        std::cin >> inputCount;
        if(!inputCount || std::cin.fail() || inputCount < 0)
        {
            printf("Not a valid input, Input count should be greater than 0\n");
            std::cin.clear();
            std::cin.ignore();
            inputCondition = true;
        }
        else
            inputCondition = false;

    }
    while(inputCondition);
    
    inputCondition = true;
    int temp = inputCount;

    printf("Enter %d no of inputs seperated with space\n",inputCount);
    bool input;
    while(temp)
    {
        std::cin >> input;
        if(std::cin.fail())
        {
            printf("Not a valid input, Inputs should be either 1 or 0 \n");
            std::cin.clear();
            std::cin.ignore();
            temp = inputCount;
        }
        else
        {
            inputs.push_back(input);
            temp--;
        }
    }
}

int main()
{
    srand(time(0));

    // Inputs
    int inputCount;
    std::vector<bool> inputValues;
    takeInputs(inputCount, inputValues);

    // Generate circuit and connections
    Circuit c(inputCount);
    c.createCircuit();
    
    // Execute
    c.execute(inputValues);
    
    // Output
    c.printCircuit();
}
