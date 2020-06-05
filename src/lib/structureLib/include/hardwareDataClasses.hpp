#ifndef IG_HARDWARE_CLASSES_SL
#define IG_HARDWARE_CLASSES_SL

#include "coreDataClasses.hpp"
#include "commonInclude.hpp"

class IntegratedCircuit
{
    protected:
        string _currentClock;
        string _voltage;
        uint16_t _width;
    public:
        IntegratedCircuit() { };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getCurrentClock();
        string getVoltage();
        uint16_t getWidth();
        void setCurrentClock(string newCurrentClock);
        void setVoltage(string newVoltage);
        void setWidth(uint16_t newWidth);
};

class StorageUnit
{
    protected:
        uint64_t _size;
    public:
        StorageUnit() { };
        void serialize(json& j);
        void deSerialize(const json& j);
        uint64_t getSize();
        void setSize(uint64_t newSize);
};

class Processor : public Device, public IntegratedCircuit
{
    private:
        string _busClock;
        string _family;
        string _maxClock;
        string _socket;
        uint16_t _coreCount;
        uint16_t _enabledCoreCount;
        uint16_t _threadCount;
    public:
        Processor() { this->setDescription(""); this->setType(""); };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getBusClock();
        string getFamily();
        string getMaxClock();
        string getSocket();
        uint16_t getCoreCount();
        uint16_t getEnabledCoreCount();
        uint16_t getThreadCount();
        void setBusClock(string newBusClock);
        void setCoreCount(uint16_t newCoreCount);
        void setDescription(string newDescription);
        void setEnabledCoreCount(uint16_t newEnabledCoreCount);
        void setFamily(string newFamily);
        void setMaxClock(string newMaxClock);
        void setSocket(string newSocket);
        void setThreadCount(uint16_t newThreadCount);
        void setType(string newType);
};

class VideoController : public Device
{
    private:
        string _videoProcessor;
        uint16_t _currentHorizontalResolution;
        uint16_t _currentRefreshRate;
        uint16_t _currentVerticalResolution;
        uint16_t _maxRefreshRate;
        uint16_t _minRefreshRate;
    public:
        VideoController() { this->setDescription(""); this->setType(""); };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getVideoProcessor();
        uint16_t getCurrentHorizontalResolution();
        uint16_t getCurrentRefreshRate();
        uint16_t getCurrentVerticalResolution();
        uint16_t getMaxRefreshRate();
        uint16_t getMinRefreshRate();
        void setCurrentHorizontalResolution(uint16_t newCurrentHorizontalResolution);
        void setCurrentRefreshRate(uint16_t newCurrentRefreshRate);
        void setCurrentVerticalResolution(uint16_t newCurrentVerticalResolution);
        void setDescription(string newDescription);
        void setMaxRefreshRate(uint16_t newMaxRefreshRate);
        void setMinRefreshRate(uint16_t newMinRefreshRate);
        void setType(string newType);
        void setVideoProcessor(string newVideoProcessor);
};

class DiskDrive : public Device, public StorageUnit
{
    private:
        string _firmwareRevision;
        string _interfaceType;
        string _logicalName;
        uint16_t _bytesPerSector;
    public:
        DiskDrive() { this->setDescription(""); this->setType(""); };
        void serialize(json& j);
        void deSerialize(const json& j);
        string getFirmwareRevision();
        string getInterfaceType();
        string getLogicalName();
        uint16_t getBytesPerSector();
        void setBytesPerSector(uint16_t newBytesPerSector);
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
        vector<ManagedElement*> _baseBoards;
        vector<ManagedElement*> _diskDrives;
        vector<ManagedElement*> _processors;
        vector<ManagedElement*> _systemMemory;
        vector<ManagedElement*> _videoControllers;
    public:
        ComputerSystem() { this->setDescription(""); this->setType(""); }
        void serialize(json& j);
        void deSerialize(const json& j);
        vector<ManagedElement*> getBaseBoards();
        vector<ManagedElement*> getDiskDrives();
        vector<ManagedElement*> getProcessors();
        vector<ManagedElement*> getSystemMemory();
        vector<ManagedElement*> getVideoControllers();
        void setBaseBoards(vector<ManagedElement*> newBaseBoardsList);
        void setDescription(string newDescription);
        void setDiskDrives(vector<ManagedElement*> newDiskDrivesList);
        void setProcessors(vector<ManagedElement*> newProcessorsList);
        void setSystemMemory(vector<ManagedElement*> newSystemMemoryList);
        void setType(string newType);
        void setVideoControllers(vector<ManagedElement*> newVideoControllersList);
};

#endif
