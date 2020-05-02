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
    VideoControllerProvider* gprov = new VideoControllerProvider();
    VideoController* newGPU = gprov->createManagedElement();

    cout << "ID: " << newCPU->getId() << "\nName: " 
    << newCPU->getName() << "\nBus Clock: " 
    << newCPU->getBusClock() << "MHz\nMax Clock: " 
    << newCPU->getMaxClock() << "MHz\nCurrent Clock: "
    << newCPU->getCurrentClock() << "MHz\nFamily: "
    << newCPU->getFamily() << "\nSocket: "
    << newCPU->getSocket() << "\nAddress Width: "
    << newCPU->getWidth() << "bit\nCore Count: "
    << newCPU->getCoreCount() << "\nThread Count: "
    << newCPU->getThreadCount() << "\n";

    cout << "\nName: " 
    << newGPU->getName() << "\nMax Refresh Rate: " 
    << newGPU->getMaxRefreshRate() << "Hz\nMin Refresh Rate: "
    << newGPU->getMinRefreshRate() << "Hz\n";
}
