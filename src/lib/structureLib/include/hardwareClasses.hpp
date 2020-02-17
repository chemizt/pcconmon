#ifndef IG_HARDWARE_CLASSES_SL
#define IG_HARDWARE_CLASSES_SL

#include "coreClasses.hpp"
#include "commonInclude.hpp"

class Processor : public Device
{
    private:
        string socket;
        string family;
        string currentClock;
        string maxClock;
        string busClock;
        string voltage;
        uint16_t width;
        uint16_t coreCount;
        uint16_t enabledCoreCount;
        uint16_t threadCount;
    public:
        using Device::ManagedElement;
        string getSocket();
        string getFamily();
        string getCurrentClock();
        string getMaxClock();
        string getBusClock();
        string getVoltage();
        uint16_t getWidth();
        uint16_t getCoreCount();
        uint16_t getEnabledCoreCount();
        uint16_t getThreadCount();
        void setDescription(string newDescription);
        void setType(string newType);
        void setSocket(string newSocket);
        void setFamily(string newFamily);
        void setCurrentClock(string newCurrentClock);
        void setMaxClock(string newMaxClock);
        void setBusClock(string newBusClock);
        void setVoltage(string newVoltage);
        void setWidth(uint16_t newWidth);
        void setCoreCount(uint16_t newCoreCount);
        void setEnabledCoreCount(uint16_t newEnabledCoreCount);
        void setThreadCount(uint16_t newThreadCount);
};

#endif