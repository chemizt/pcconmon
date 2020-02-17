#include <iostream>
#include <functional>

#include "coreClasses.hpp"
#include "auxClasses.hpp"
#include "hardwareClasses.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::hash;

int main()
{
    ProcessorFactory* newFactory = new ProcessorFactory();
    Processor* newCPU = (Processor*)(newFactory->create());
    hash<string> hasher;
    string in;

    newCPU->setId("1");
    newCPU->setName("i3-8100");

    cout << hasher("HDD") << "\n";

    cin >> in;
    cout << hasher(in) << "\n";

    cout << newCPU->getId() << "\n" << newCPU->getName() << "\n" << newCPU->getType() << "\n" << newCPU->getDescription();
}