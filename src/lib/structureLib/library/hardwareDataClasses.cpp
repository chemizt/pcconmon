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
    if (newSocket == "")
    {
        this->socket = "N/A";
    }
    else
    {
        this->socket = newSocket;
    }
}

void Processor::setFamily(string newFamily)
{
    if (newFamily == "")
    {
        this->family = "N/A";
    }
    else
    {
        this->family = newFamily;
    }
}

void Processor::setCurrentClock(string newCurrentClock)
{
    if (newCurrentClock == "")
    {
        this->currentClock = "N/A";
    }
    else
    {
        this->currentClock = newCurrentClock;
    }
}

void Processor::setMaxClock(string newMaxClock)
{
    if (newMaxClock == "")
    {
        this->maxClock = "N/A";
    }
    else
    {
        this->maxClock = newMaxClock;
    }
}

void Processor::setBusClock(string newBusClock)
{
    if (newBusClock == "")
    {
        this->busClock = "N/A";
    }
    else
    {
        this->busClock = newBusClock;
    }
}

void Processor::setVoltage(string newVoltage)
{
    if (newVoltage == "")
    {
        this->socket = "N/A";
    }
    else
    {
        this->socket = newVoltage;
    }
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

string VideoController::getVideoProcessor()
{
    return this->videoProcessor;
}

uint16_t VideoController::getCurrentHorizontalResolution()
{
    return this->currentHorizontalResolution;
}

uint16_t VideoController::getCurrentRefreshRate()
{
    return this->currentRefreshRate;
}

uint16_t VideoController::getCurrentVerticalResolution()
{
    return this->currentVerticalResolution;
}

uint16_t VideoController::getMaxRefreshRate()
{
    return this->maxRefreshRate;
}

uint16_t VideoController::getMinRefreshRate()
{
    return this->minRefreshRate;
}

void VideoController::setVideoProcessor(string newVideoProcessor)
{
    if (newVideoProcessor == "")
    {
        this->videoProcessor = "N/A";
    }
    else
    {
        this->videoProcessor = newVideoProcessor;
    }
}

void VideoController::setDescription(string newDescription)
{
    if (newDescription == "")
    {
        this->videoProcessor = "Graphics Processing Unit";
    }
    else
    {
        this->videoProcessor = newDescription;
    }
}

void VideoController::setType(string newType)
{
    if (newType == "")
    {
        this->videoProcessor = "GPU";
    }
    else
    {
        this->videoProcessor = newType;
    }
}

void VideoController::setCurrentHorizontalResolution(uint16_t newCurrentHorizontalResolution)
{
    this->currentHorizontalResolution = newCurrentHorizontalResolution;
}

void VideoController::setCurrentRefreshRate(uint16_t newCurrentRefreshRate)
{
    this->currentRefreshRate = newCurrentRefreshRate;
}

void VideoController::setCurrentVerticalResolution(uint16_t newCurrentVerticalResolution)
{
    this->currentVerticalResolution = newCurrentVerticalResolution;
}

void VideoController::setMaxRefreshRate(uint16_t newMaxRefreshRate)
{
    this->maxRefreshRate = newMaxRefreshRate;
}

void VideoController::setMinRefreshRate(uint16_t newMinRefreshRate)
{
    this->minRefreshRate = newMinRefreshRate;
}
