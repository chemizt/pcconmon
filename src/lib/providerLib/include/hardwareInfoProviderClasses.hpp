#ifndef IG_HARDWARE_CLASSES_PL
#define IG_HARDWARE_CLASSES_PL

#include "commonInclude.hpp"
#include "coreProviderClasses.hpp"
#include "hardwareDataClasses.hpp"

class ProcessorProvider : public InformationProvider
{
    private:
        string gatherBasicInfo();
        void createManagedElement(string infoString);
    public:
        using InformationProvider::InformationProvider;
        ProcessorProvider() { };
        void scanForManagedElements();
};

class VideoControllerProvider : public InformationProvider
{
    private:
        string gatherBasicInfo();
        void createManagedElement(string infoString);
    public:
        using InformationProvider::InformationProvider;
        VideoControllerProvider() { };
        void scanForManagedElements();
};

class DiskDriveProvider : public InformationProvider
{
    private:
        string gatherBasicInfo();
        string gatherAdvancedInfo(string elementName);
        void createManagedElement(string infoString);
    public:
        using InformationProvider::InformationProvider;
        DiskDriveProvider() { };
        void scanForManagedElements();
};

class BaseBoardProvider : public InformationProvider
{
    private:
        string gatherBasicInfo();
        void createManagedElement(string infoString);
    public:
        using InformationProvider::InformationProvider;
        BaseBoardProvider() { };
        void scanForManagedElements();
};

class SystemMemoryProvider : public InformationProvider
{
    private:
        string gatherBasicInfo();
        void createManagedElement(string infoString);
    public:
        using InformationProvider::InformationProvider;
        SystemMemoryProvider() { };
        void scanForManagedElements();
};

class ComputerSystemProvider : public InformationProvider
{
    private:
        BaseBoardProvider _baseBoardProv;
        DiskDriveProvider _diskDriveProv;
        ProcessorProvider _processorProv;
        SystemMemoryProvider _sysMemProv;
        VideoControllerProvider _vidConProv;
        string gatherBasicInfo();
        void createManagedElement(string infoString);
    public:
        using InformationProvider::InformationProvider;
        ComputerSystemProvider() { };
        ManagedElement* getManagedElement() { return _createdManagedElements.at(0); };
        void scanForManagedElements();
};

#endif
