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

    cout << newCPU->getId() << "\n" << newCPU->getName() << "\n" << newCPU->getMaxClock() << "\n";
}
