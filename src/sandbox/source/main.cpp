#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>

#include "coreProviderClasses.hpp"
#include "hardwareDataClasses.hpp"
#include "hardwareProviderClasses.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    #ifndef _WIN32
    CommandExecutor* cmdExec = new CommandExecutor;

    cout << cmdExec->executeCommand("dmidecode -t 4");
    cout << cmdExec->executeCommand("lscpu");
    #else
    ProcessorProvider* pprov = new ProcessorProvider();
    VideoControllerProvider* gprov = new VideoControllerProvider();
    pprov->scanForManagedElements();
    gprov->scanForManagedElements();
    vector<ManagedElement*> cpuRslt, gpuRslt;
    cpuRslt = pprov->getAllManagedElements();
    gpuRslt = gprov->getAllManagedElements();
    Processor* myProc = (Processor*)cpuRslt.at(0);
    VideoController* myGPU = (VideoController*)gpuRslt.at(0);
    #endif
    return 0;
}
