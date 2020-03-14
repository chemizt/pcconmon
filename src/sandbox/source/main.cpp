#include <iostream>
#include <functional>

#include "coreDataClasses.hpp"
#include "auxClasses.hpp"
#include "hardwareDataClasses.hpp"
#include "hardwareProviderClasses.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::hash;

int main()
{
    ProcessorProvider* prov = new ProcessorProvider();
    Processor* newCPU = prov->createManagedElement();

    cout << "ID: " << newCPU->getId() << "\nName: " 
    << newCPU->getName() << "\nBus Clock: " 
    << newCPU->getBusClock() << "\nMax Clock: " 
    << newCPU->getMaxClock() << "\nCurrent Clock: "
    << newCPU->getCurrentClock() << "\nFamily: "
    << newCPU->getFamily() << "\nSocket: "
    << newCPU->getSocket() << "\nAddress Width: "
    << newCPU->getWidth() << "\n";
}
