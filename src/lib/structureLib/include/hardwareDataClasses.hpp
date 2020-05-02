#ifndef IG_HARDWARE_CLASSES_SL
#define IG_HARDWARE_CLASSES_SL

#include "coreDataClasses.hpp"
#include "commonInclude.hpp"

class Processor : public Device
{
    private:
        string busClock;
        string currentClock;
        string family;
        string maxClock;
        string socket;
        string voltage;
        uint16_t coreCount;
        uint16_t enabledCoreCount;
        uint16_t threadCount;
        uint16_t width;
    public:
        using Device::ManagedElement;
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
        string videoProcessor;
        uint16_t currentHorizontalResolution;
        uint16_t currentRefreshRate;
        uint16_t currentVerticalResolution;
        uint16_t maxRefreshRate;
        uint16_t minRefreshRate;
    public:
        using Device::ManagedElement;
        string getVideoProcessor();
        uint16_t getCurrentHorizontalResolution();
        uint16_t getCurrentRefreshRate();
        uint16_t getCurrentVerticalResolution();
        uint16_t getMaxRefreshRate();
        uint16_t getMinRefreshRate();
        void setCurrentHorizontalResolution(uint16_t newCurrentHorizontalResolution);
        void setCurrentRefreshRate(uint16_t newCurrentRefreshRate);
        void setCurrentVerticalResolution(uint16_t newCurrentVerticalResolution);
        void setMaxRefreshRate(uint16_t newMaxRefreshRate);
        void setMinRefreshRate(uint16_t newMinRefreshRate);
        void setDescription(string newDescription);
        void setType(string newType);
        void setVideoProcessor(string newVideoProcessor);
};

#endif
