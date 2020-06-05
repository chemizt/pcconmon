#include <iostream>

#include "coreProviderClasses.hpp"
#include "hardwareDataClasses.hpp"
#include "hardwareProviderClasses.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    ComputerSystemProvider* csprov = new ComputerSystemProvider();
    ComputerSystem* cs = (ComputerSystem*)csprov->createManagedElement();
    vector<ManagedElement*> processors = cs->getProcessors();
    vector<ManagedElement*> gpus = cs->getVideoControllers();
    vector<ManagedElement*> drives = cs->getDiskDrives();
    vector<ManagedElement*> motherboards = cs->getBaseBoards();
    vector<ManagedElement*> ram = cs->getSystemMemory();

    json j;

    ((Processor*)processors.at(0))->setVoltage("1.2");
    ((Processor*)processors.at(0))->serialize(j);

    cout << j << endl;

    Processor* np = new Processor();
    np->deSerialize(j);

    processors.push_back(np);

    cout << "Central Processing Units:\n\n";

    for(ManagedElement* cpu : processors)
    {
        Processor* castCpu = (Processor*)cpu;
        
        cout << "\t\tID: " << castCpu->getId() << "\n\t\tName: " 
        << castCpu->getName() << "\n\t\tBus Clock: " 
        << castCpu->getBusClock() << "MHz\n\t\tMax Clock: " 
        << castCpu->getMaxClock() << "MHz\n\t\tCurrent Clock: "
        << castCpu->getCurrentClock() << "MHz\n\t\tFamily: "
        << castCpu->getFamily() << "\n\t\tSocket: "
        << castCpu->getSocket() << "\n\t\tVoltage: "
        << castCpu->getVoltage() << "V\n\t\tAddress Width: "
        << castCpu->getWidth() << " bits\n\t\tCore Count: "
        << castCpu->getCoreCount() << "\n\t\tThread Count: "
        << castCpu->getThreadCount() << "\n\n";
    }

    cout << "Display Controllers:\n\n";

    for(ManagedElement* gpu : gpus)
    {
        VideoController* castGpu = (VideoController*)gpu;
        
        cout << "\t\tName: " 
        << castGpu->getName() << "\n\t\tVideo Processor: " 
        << castGpu->getVideoProcessor() << "\n\t\tModel: " 
        << castGpu->getModel() << "\n\t\tCurrent Refresh Rate: "
        << castGpu->getCurrentRefreshRate() << "Hz\n\t\tMinimum Refresh Rate: "
        << castGpu->getMinRefreshRate() << "Hz\n\t\tMaximum Refresh Rate: "
        << castGpu->getMaxRefreshRate() << "Hz\n\t\tHorizontal Resolution: "
        << castGpu->getCurrentHorizontalResolution() << "\n\t\tVertical Resolution: "
        << castGpu->getCurrentVerticalResolution() << "\n\n";
    }
    
    cout << "Physical Drives:\n\n";

    for (ManagedElement* drive : drives)
    {
        DiskDrive* castDrive = (DiskDrive*)drive;

        cout << "\t\tName: " << castDrive->getName()
        << "\n\t\tManufacturer: " << castDrive->getManufacturer()
        << "\n\t\tModel: " << castDrive->getModel()
        << "\n\t\tSerial Number: " << castDrive->getSerialNumber()
        << "\n\t\tLogical Name: " << castDrive->getLogicalName()
        << "\n\t\tBytes per Sector: " << castDrive->getBytesPerSector()
        << "\n\t\tCapacity: " << uint64_t(castDrive->getSize() / 1024 / 1024)
        << "MB\n\t\tFirmware Revision: " << castDrive->getFirmwareRevision()
        << "\n\t\tVersion: " << castDrive->getVersion()
        << "\n\t\tInterface Type: " << castDrive->getInterfaceType()
        << "\n\t\tType: " << castDrive->getType()
        << "\n\t\tDescription: " << castDrive->getDescription()
        << "\n\n";
    }

    cout << "Motherboards:\n\n";

    for (ManagedElement* motherboard : motherboards)
    {
        BaseBoard* castMB = (BaseBoard*)motherboard;

        cout << "\n\t\tManufacturer: " << castMB->getManufacturer()
        << "\n\t\tModel: " << castMB->getModel()
        << "\n\t\tSerial Number: " << castMB->getSerialNumber()
        << "\n\t\tVersion: " << castMB->getVersion()
        << "\n\t\tHosting: " << (castMB->isHosting() ? "Yes" : "No")
        << "\n\t\tHotswappable: " << (castMB->isHotswappable() ? "Yes" : "No")
        << "\n\t\tRemovable: " << (castMB->isRemovable() ? "Yes" : "No")
        << "\n\t\tReplaceable: " << (castMB->isReplaceable() ? "Yes" : "No")
        << "\n\n";
    }

    cout << "RAM Devices:\n\n";

    for (ManagedElement* stick : ram)
    {
        SystemMemory* castRAM = (SystemMemory*)stick;

        cout << "\n\t\tManufacturer: " << castRAM->getManufacturer()
        << "\n\t\tSerial Number: " << castRAM->getSerialNumber()
        << "\n\t\tPart Number: " << castRAM->getPartNumber()
        << "\n\t\tForm Factor: " << castRAM->getFormFactor()
        << "\n\t\tType: " << castRAM->getType()
        << "\n\t\tChannel: " << castRAM->getChannel()
        << "\n\t\tDIMM Name: " << castRAM->getDimmName()
        << "\n\t\tCapacity: " << uint64_t(castRAM->getSize() / 1024 / 1024)
        << "MB\n\t\tClock: " << castRAM->getCurrentClock()
        << "MHz\n\t\tVoltage: " << castRAM->getVoltage()
        << "V\n\t\tWidth: " << castRAM->getWidth()
        << "\n\n";
    }

    return 0;
}
