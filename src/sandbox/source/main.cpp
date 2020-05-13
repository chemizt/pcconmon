#include <iostream>

#include "coreProviderClasses.hpp"
#include "hardwareDataClasses.hpp"
#include "hardwareProviderClasses.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    DiskDriveProvider* dprov = new DiskDriveProvider();
    dprov->scanForManagedElements();
    vector<ManagedElement*> drives = dprov->getAllManagedElements();

    for (ManagedElement* drive : drives)
    {
        DiskDrive* castDrive = (DiskDrive*)drive;

        cout << "Name: " << castDrive->getName()
        << "\nManufacturer: " << castDrive->getManufacturer()
        << "\nModel: " << castDrive->getModel()
        << "\nSerial Number: " << castDrive->getSerialNumber()
        << "\nLogical Name: " << castDrive->getLogicalName()
        << "\nBytes per Sector: " << castDrive->getBytesPerSector()
        << "\nCapacity: " << uint64_t(castDrive->getSize() / 1024 / 1024)
        << "MB\nFirmware Revision: " << castDrive->getFirmwareRevision()
        << "\nVersion: " << castDrive->getVersion()
        << "\nInterface Type: " << castDrive->getInterfaceType()
        << "\nType: " << castDrive->getType()
        << "\nDescription: " << castDrive->getDescription()
        << "\n\n";
    }

    BaseBoardProvider* bprov = new BaseBoardProvider();
    bprov->scanForManagedElements();
    vector<ManagedElement*> motherboards = bprov->getAllManagedElements();

    for (ManagedElement* motherboard : motherboards)
    {
        BaseBoard* castMB = (BaseBoard*)motherboard;

        cout << "\nManufacturer: " << castMB->getManufacturer()
        << "\nModel: " << castMB->getModel()
        << "\nSerial Number: " << castMB->getSerialNumber()
        << "\nVersion: " << castMB->getVersion()
        << "\nHosting: " << (castMB->isHosting() ? "Yes" : "No")
        << "\nHotswappable: " << (castMB->isHotswappable() ? "Yes" : "No")
        << "\nRemovable: " << (castMB->isRemovable() ? "Yes" : "No")
        << "\nReplaceable: " << (castMB->isReplaceable() ? "Yes" : "No")
        << "\n\n";
    }

    return 0;
}
