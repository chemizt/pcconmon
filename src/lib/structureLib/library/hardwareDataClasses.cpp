#include "hardwareDataClasses.hpp"

string Processor::getSocket()
{   
    return this->socket;
}

string Processor::getFamily()
{
    return this->family;
}

string Processor::getCurrentClock()
{
    return this->currentClock;
}

string Processor::getMaxClock()
{
    return this->maxClock;
}

string Processor::getBusClock()
{
    return this->busClock;
}

string Processor::getVoltage()
{
    return this->voltage;
}

uint16_t Processor::getWidth()
{
    return this->width;
}

uint16_t Processor::getCoreCount()
{
    return this->coreCount;
}

uint16_t Processor::getEnabledCoreCount()
{
    return this->enabledCoreCount;
}

uint16_t Processor::getThreadCount()
{
    return this->threadCount;
}

void Processor::setDescription(string newDescription)
{
    if (newDescription == "")
    {
        this->description = "Central Processing Unit";
    }
    else
    {
        this->description = newDescription;
    }
    
}

void Processor::setType(string newType)
{
    if (newType == "")
    {
        this->type = "CPU";
    }
    else
    {
        this->type = newType;
    }
}

void Processor::setSocket(string newSocket)
{
    this->socket = newSocket;
}

void Processor::setFamily(string newFamily)
{
    this->family = newFamily;
}

void Processor::setCurrentClock(string newCurrentClock)
{
    this->currentClock = newCurrentClock;
}

void Processor::setMaxClock(string newMaxClock)
{
    this->maxClock = newMaxClock;
}

void Processor::setBusClock(string newBusClock)
{
    this->busClock = newBusClock;
}

void Processor::setVoltage(string newVoltage)
{
    this->voltage = newVoltage;
}

void Processor::setWidth(uint16_t newWidth)
{
    this->width = newWidth;
}

void Processor::setCoreCount(uint16_t newCoreCount)
{
    this->coreCount = newCoreCount;
}

void Processor::setEnabledCoreCount(uint16_t newEnabledCoreCount)
{
    this->enabledCoreCount = newEnabledCoreCount;
}

void Processor::setThreadCount(uint16_t newThreadCount)
{
    this->threadCount = newThreadCount;
}
