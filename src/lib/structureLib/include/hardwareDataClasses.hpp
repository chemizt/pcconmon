#ifndef IG_HARDWARE_CLASSES_SL
#define IG_HARDWARE_CLASSES_SL

#include <map>

#include "coreDataClasses.hpp"
#include "commonInclude.hpp"

using std::map;

class IntegratedCircuit
{
    protected:
        string _currentClock;
        string _voltage;
        string _width;
    public:
        IntegratedCircuit() { };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getCurrentClock();
        string getVoltage();
        string getWidth();
        void setCurrentClock(string newCurrentClock);
        void setVoltage(string newVoltage);
        void setWidth(string newWidth);
};

class StorageUnit
{
    protected:
        string _size;
    public:
        StorageUnit() { };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getSize();
        void setSize(string newSize);
};

class Processor : public Device, public IntegratedCircuit
{
    private:
        string _busClock;
        string _family;
        string _maxClock;
        string _socket;
        string _coreCount;
        string _enabledCoreCount;
        string _threadCount;
    public:
        Processor() { this->setDescription(""); this->setType(""); };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getBusClock();
        string getFamily();
        string getMaxClock();
        string getSocket();
        string getCoreCount();
        string getEnabledCoreCount();
        string getThreadCount();
        void setBusClock(string newBusClock);
        void setCoreCount(string newCoreCount);
        void setDescription(string newDescription);
        void setEnabledCoreCount(string newEnabledCoreCount);
        void setFamily(string newFamily);
        void setMaxClock(string newMaxClock);
        void setSocket(string newSocket);
        void setThreadCount(string newThreadCount);
        void setType(string newType);
};

class VideoController : public Device
{
    private:
        string _videoProcessor;
        string _currentHorizontalResolution;
        string _currentRefreshRate;
        string _currentVerticalResolution;
        string _maxRefreshRate;
        string _minRefreshRate;
    public:
        VideoController() { this->setDescription(""); this->setType(""); };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getVideoProcessor();
        string getCurrentHorizontalResolution();
        string getCurrentRefreshRate();
        string getCurrentVerticalResolution();
        string getMaxRefreshRate();
        string getMinRefreshRate();
        void setCurrentHorizontalResolution(string newCurrentHorizontalResolution);
        void setCurrentRefreshRate(string newCurrentRefreshRate);
        void setCurrentVerticalResolution(string newCurrentVerticalResolution);
        void setDescription(string newDescription);
        void setMaxRefreshRate(string newMaxRefreshRate);
        void setMinRefreshRate(string newMinRefreshRate);
        void setType(string newType);
        void setVideoProcessor(string newVideoProcessor);
};

class DiskDrive : public Device, public StorageUnit
{
    private:
        string _firmwareRevision;
        string _interfaceType;
        string _logicalName;
        string _bytesPerSector;
    public:
        DiskDrive() { this->setDescription(""); this->setType(""); };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getFirmwareRevision();
        string getInterfaceType();
        string getLogicalName();
        string getBytesPerSector();
        void setBytesPerSector(string newBytesPerSector);
        void setDescription(string newDescription);
        void setFirmwareRevision(string newFirmwareRevision);
        void setInterfaceType(string newInterfaceType);
        void setLogicalName(string newLogicalName);
        void setType(string newType);
};

class BaseBoard : public Device
{
    private:
        bool _isHosting = false;
        bool _isHotswappable = false;
        bool _isRemovable = false;
        bool _isReplaceable = false;
    public:
        BaseBoard() { this->setDescription(""); this->setType(""); };
        void serialize(json& j);
        void deSerialize(const json& j);
        bool isHosting();
        bool isHotswappable();
        bool isRemovable();
        bool isReplaceable();
        void setDescription(string newDescription);
        void setHosting();
        void setHotswappable();
        void setRemovable();
        void setReplaceable();
        void setType(string newType);
};

class SystemMemory : public Device, public IntegratedCircuit, public StorageUnit
{
    private:
        string _channel;
        string _dimmName;
        string _formFactor;
    public:
        SystemMemory() { this->setDescription(""); this->setType(""); };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getChannel();
        string getDimmName();
        string getFormFactor();
        void setChannel(string newChannel);
        void setDescription(string newDescription);
        void setDimmName(string newDimmName);
        void setFormFactor(string newFormFactor);
        void setType(string newType);
};

class ComputerSystem : public Device
{
    private:
        map<string, ManagedElement*> _baseBoards;
        map<string, ManagedElement*> _diskDrives;
        map<string, ManagedElement*> _processors;
        map<string, ManagedElement*> _systemMemory;
        map<string, ManagedElement*> _videoControllers;
        string _operatingSystemName;
        string _architecture;
    public:
        ComputerSystem() { this->setDescription(""); this->setType(""); }
        void serialize(json& j);
        void deSerialize(const json& j);
        map<string, ManagedElement*> getBaseBoards();
        map<string, ManagedElement*> getDiskDrives();
        map<string, ManagedElement*> getProcessors();
        map<string, ManagedElement*> getSystemMemory();
        map<string, ManagedElement*> getVideoControllers();
        string getOperatingSystemName();
        string getArchitecture();
        void setArchitecture(string newArchitecture);
        void setBaseBoards(map<string, ManagedElement*> newBaseBoardsList);
        void setDescription(string newDescription);
        void setDiskDrives(map<string, ManagedElement*> newDiskDrivesList);
        void setOperatingSystemName(string newOsName);
        void setProcessors(map<string, ManagedElement*> newProcessorsList);
        void setSystemMemory(map<string, ManagedElement*> newSystemMemoryList);
        void setType(string newType);
        void setVideoControllers(map<string, ManagedElement*> newVideoControllersList);
};

#endif
