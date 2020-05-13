#ifndef IG_HARDWARE_CLASSES_SL
#define IG_HARDWARE_CLASSES_SL

#include "coreDataClasses.hpp"
#include "commonInclude.hpp"

class Processor : public Device
{
    private:
        string _busClock;
        string _currentClock;
        string _family;
        string _maxClock;
        string _socket;
        string _voltage;
        uint16_t _coreCount;
        uint16_t _enabledCoreCount;
        uint16_t _threadCount;
        uint16_t _width;
    public:
        string getBusClock();
        string getCurrentClock();
        string getFamily();
        string getMaxClock();
        string getSocket();
        string getVoltage();
        uint16_t getCoreCount();
        uint16_t getEnabledCoreCount();
        uint16_t getThreadCount();
        uint16_t getWidth();
        void setBusClock(string newBusClock);
        void setCoreCount(uint16_t newCoreCount);
        void setCurrentClock(string newCurrentClock);
        void setDescription(string newDescription);
        void setEnabledCoreCount(uint16_t newEnabledCoreCount);
        void setFamily(string newFamily);
        void setMaxClock(string newMaxClock);
        void setSocket(string newSocket);
        void setThreadCount(uint16_t newThreadCount);
        void setType(string newType);
        void setVoltage(string newVoltage);
        void setWidth(uint16_t newWidth);
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

class DiskDrive : public Device
{
    private:
        string _firmwareRevision;
        string _interfaceType;
        string _logicalName;
        uint16_t _bytesPerSector;
        uint64_t _size;
    public:
        string getFirmwareRevision();
        string getInterfaceType();
        string getLogicalName();
        uint16_t getBytesPerSector();
        uint64_t getSize();
        void setBytesPerSector(uint16_t newBytesPerSector);
        void setDescription(string newDescription);
        void setFirmwareRevision(string newFirmwareRevision);
        void setInterfaceType(string newInterfaceType);
        void setLogicalName(string newLogicalName);
        void setSize(uint64_t newSize);
        void setType(string newType);
};

class BaseBoard : public Device
{
    private:
        bool _isHosting = false;
        bool _isReplaceable = false;
        bool _isHotswappable = false;
        bool _isRemovable = false;
    public:
        bool isHosting();
        bool isReplaceable();
        bool isHotswappable();
        bool isRemovable();
        void setHosting();
        void setReplaceable();
        void setHotswappable();
        void setRemovable();
        void setDescription(string newDescription);
        void setType(string newType);
};

#endif
