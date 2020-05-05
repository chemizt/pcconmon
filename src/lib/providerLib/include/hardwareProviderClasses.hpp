#ifndef IG_HARDWARE_CLASSES_PL
#define IG_HARDWARE_CLASSES_PL

#include "commonInclude.hpp"
#include "coreProviderClasses.hpp"
#include "hardwareDataClasses.hpp"

class ProcessorProvider : public Provider
{
    private:
        string gatherBasicInfo();
        void createManagedElement(string infoString);
    public:
        using Provider::Provider;
        ProcessorProvider() { };
        void scanForManagedElements();
};

class VideoControllerProvider : public Provider
{
    private:
        string gatherBasicInfo();
        void createManagedElement(string infoString);
    public:
        using Provider::Provider;
        VideoControllerProvider() { };
        void scanForManagedElements();
};

class DiskDriveProvider : public Provider
{
    private:
        string gatherBasicInfo();
        void createManagedElement(string infoString);
    public:
        using Provider::Provider;
        DiskDriveProvider() { };
        void scanForManagedElements();
};

#endif
