#include "hardwareDataClasses.hpp"

string Processor::getSocket()
{   
    return this->_socket;
}

string Processor::getFamily()
{
    return this->_family;
}

string Processor::getCurrentClock()
{
    return this->_currentClock;
}

string Processor::getMaxClock()
{
    return this->_maxClock;
}

string Processor::getBusClock()
{
    return this->_busClock;
}

string Processor::getVoltage()
{
    return this->_voltage;
}

uint16_t Processor::getWidth()
{
    return this->_width;
}

uint16_t Processor::getCoreCount()
{
    return this->_coreCount;
}

uint16_t Processor::getEnabledCoreCount()
{
    return this->_enabledCoreCount;
}

uint16_t Processor::getThreadCount()
{
    return this->_threadCount;
}

void Processor::setDescription(string newDescription)
{
    if (newDescription == "")
    {
        this->_description = "Central Processing Unit";
    }
    else
    {
        this->_description = newDescription;
    }
    
}

void Processor::setType(string newType)
{
    if (newType == "")
    {
        this->_type = "CPU";
    }
    else
    {
        this->_type = newType;
    }
}

void Processor::setSocket(string newSocket)
{
    if (newSocket == "")
    {
        this->_socket = "N/A";
    }
    else
    {
        this->_socket = newSocket;
    }
}

void Processor::setFamily(string newFamily)
{
    if (newFamily == "")
    {
        this->_family = "N/A";
    }
    else
    {
        this->_family = newFamily;
    }
}

void Processor::setCurrentClock(string newCurrentClock)
{
    if (newCurrentClock == "")
    {
        this->_currentClock = "N/A";
    }
    else
    {
        this->_currentClock = newCurrentClock;
    }
}

void Processor::setMaxClock(string newMaxClock)
{
    if (newMaxClock == "")
    {
        this->_maxClock = "N/A";
    }
    else
    {
        this->_maxClock = newMaxClock;
    }
}

void Processor::setBusClock(string newBusClock)
{
    if (newBusClock == "")
    {
        this->_busClock = "N/A";
    }
    else
    {
        this->_busClock = newBusClock;
    }
}

void Processor::setVoltage(string newVoltage)
{
    if (newVoltage == "")
    {
        this->_voltage = "N/A";
    }
    else
    {
        this->_voltage = newVoltage;
    }
}

void Processor::setWidth(uint16_t newWidth)
{
    this->_width = newWidth;
}

void Processor::setCoreCount(uint16_t newCoreCount)
{
    this->_coreCount = newCoreCount;
}

void Processor::setEnabledCoreCount(uint16_t newEnabledCoreCount)
{
    this->_enabledCoreCount = newEnabledCoreCount;
}

void Processor::setThreadCount(uint16_t newThreadCount)
{
    this->_threadCount = newThreadCount;
}

string VideoController::getVideoProcessor()
{
    return this->_videoProcessor;
}

uint16_t VideoController::getCurrentHorizontalResolution()
{
    return this->_currentHorizontalResolution;
}

uint16_t VideoController::getCurrentRefreshRate()
{
    return this->_currentRefreshRate;
}

uint16_t VideoController::getCurrentVerticalResolution()
{
    return this->_currentVerticalResolution;
}

uint16_t VideoController::getMaxRefreshRate()
{
    return this->_maxRefreshRate;
}

uint16_t VideoController::getMinRefreshRate()
{
    return this->_minRefreshRate;
}

void VideoController::setVideoProcessor(string newVideoProcessor)
{
    if (newVideoProcessor == "")
    {
        this->_videoProcessor = "N/A";
    }
    else
    {
        this->_videoProcessor = newVideoProcessor;
    }
}

void VideoController::setDescription(string newDescription)
{
    if (newDescription == "")
    {
        this->_description = "Graphics Processing Unit";
    }
    else
    {
        this->_description = newDescription;
    }
}

void VideoController::setType(string newType)
{
    if (newType == "")
    {
        this->_type = "GPU";
    }
    else
    {
        this->_type = newType;
    }
}

void VideoController::setCurrentHorizontalResolution(uint16_t newCurrentHorizontalResolution)
{
    this->_currentHorizontalResolution = newCurrentHorizontalResolution;
}

void VideoController::setCurrentRefreshRate(uint16_t newCurrentRefreshRate)
{
    this->_currentRefreshRate = newCurrentRefreshRate;
}

void VideoController::setCurrentVerticalResolution(uint16_t newCurrentVerticalResolution)
{
    this->_currentVerticalResolution = newCurrentVerticalResolution;
}

void VideoController::setMaxRefreshRate(uint16_t newMaxRefreshRate)
{
    this->_maxRefreshRate = newMaxRefreshRate;
}

void VideoController::setMinRefreshRate(uint16_t newMinRefreshRate)
{
    this->_minRefreshRate = newMinRefreshRate;
}

string DiskDrive::getFirmwareRevision()
{
    return this->_firmwareRevision;
}

string DiskDrive::getInterfaceType()
{
    return this->_interfaceType;
}

string DiskDrive::getLogicalName()
{
    return this->_logicalName;
}

uint16_t DiskDrive::getBytesPerSector()
{
    return this->_bytesPerSector;
}

uint64_t DiskDrive::getSize()
{
    return this->_size;
}

void DiskDrive::setFirmwareRevision(string newFirmwareRevision)
{
    if (newFirmwareRevision == "")
    {
        this->_firmwareRevision = "N/A";
    }
    else
    {
        this->_firmwareRevision = newFirmwareRevision;
    }
}

void DiskDrive::setInterfaceType(string newInterfaceType)
{
    if (newInterfaceType == "")
    {
        this->_interfaceType = "N/A";
    }
    else
    {
        this->_interfaceType = newInterfaceType;
    }
}

void DiskDrive::setLogicalName(string newLogicalName)
{
    if (newLogicalName == "")
    {
        this->_logicalName = "N/A";
    }
    else
    {
        this->_logicalName = newLogicalName;
    }
}

void DiskDrive::setBytesPerSector(uint16_t newBytesPerSector)
{
    this->_bytesPerSector = newBytesPerSector;
}

void DiskDrive::setSize(uint64_t newSize)
{
    this->_size = newSize;
}

void DiskDrive::setDescription(string newDescription)
{
    if (newDescription == "")
    {
        this->_description = "Data Storage Unit";
    }
    else
    {
        this->_description = newDescription;
    }
}

void DiskDrive::setType(string newType)
{
    if (newType == "")
    {
        this->_type = "Disk";
    }
    else
    {
        this->_type = newType;
    }
}

bool BaseBoard::isHosting()
{
    return this->_isHosting;
}

bool BaseBoard::isReplaceable()
{
    return this->_isReplaceable;
}

bool BaseBoard::isHotswappable()
{
    return this->_isHotswappable;
}

bool BaseBoard::isRemovable()
{
    return this->_isRemovable;
}

void BaseBoard::setHosting()
{
    this->_isHosting = true;
}

void BaseBoard::setReplaceable()
{
    this->_isReplaceable = true;
}

void BaseBoard::setHotswappable()
{
    this->_isHotswappable = true;
}

void BaseBoard::setRemovable()
{
    this->_isRemovable = true;
}

void BaseBoard::setDescription(string newDescription)
{
    if (newDescription == "")
    {
        this->_description = "Main System Board";
    }
    else
    {
        this->_description = newDescription;
    }
}

void BaseBoard::setType(string newType)
{
    if (newType == "")
    {
        this->_type = "Motherboard";
    }
    else
    {
        this->_type = newType;
    }
}