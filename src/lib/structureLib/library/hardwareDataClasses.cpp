#include "hardwareDataClasses.hpp"

string Processor::getSocket()
{   
    return this->_socket;
}

string Processor::getFamily()
{
    return this->_family;
}

string IntegratedCircuit::getCurrentClock()
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

string IntegratedCircuit::getVoltage()
{
    return this->_voltage;
}

string IntegratedCircuit::getWidth()
{
    return this->_width;
}

string Processor::getCoreCount()
{
    return this->_coreCount;
}

string Processor::getEnabledCoreCount()
{
    return this->_enabledCoreCount;
}

string Processor::getThreadCount()
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

void IntegratedCircuit::setCurrentClock(string newCurrentClock)
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

void IntegratedCircuit::setVoltage(string newVoltage)
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

void IntegratedCircuit::setWidth(string newWidth)
{
    this->_width = newWidth;
}

void Processor::setCoreCount(string newCoreCount)
{
    this->_coreCount = newCoreCount;
}

void Processor::setEnabledCoreCount(string newEnabledCoreCount)
{
    this->_enabledCoreCount = newEnabledCoreCount;
}

void Processor::setThreadCount(string newThreadCount)
{
    this->_threadCount = newThreadCount;
}

string VideoController::getVideoProcessor()
{
    return this->_videoProcessor;
}

string VideoController::getCurrentHorizontalResolution()
{
    return this->_currentHorizontalResolution;
}

string VideoController::getCurrentRefreshRate()
{
    return this->_currentRefreshRate;
}

string VideoController::getCurrentVerticalResolution()
{
    return this->_currentVerticalResolution;
}

string VideoController::getMaxRefreshRate()
{
    return this->_maxRefreshRate;
}

string VideoController::getMinRefreshRate()
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

void VideoController::setCurrentHorizontalResolution(string newCurrentHorizontalResolution)
{
    this->_currentHorizontalResolution = newCurrentHorizontalResolution;
}

void VideoController::setCurrentRefreshRate(string newCurrentRefreshRate)
{
    this->_currentRefreshRate = newCurrentRefreshRate;
}

void VideoController::setCurrentVerticalResolution(string newCurrentVerticalResolution)
{
    this->_currentVerticalResolution = newCurrentVerticalResolution;
}

void VideoController::setMaxRefreshRate(string newMaxRefreshRate)
{
    this->_maxRefreshRate = newMaxRefreshRate;
}

void VideoController::setMinRefreshRate(string newMinRefreshRate)
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

string DiskDrive::getBytesPerSector()
{
    return this->_bytesPerSector;
}

string StorageUnit::getSize()
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

void DiskDrive::setBytesPerSector(string newBytesPerSector)
{
    this->_bytesPerSector = newBytesPerSector;
}

void StorageUnit::setSize(string newSize)
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

string SystemMemory::getFormFactor()
{
    return this->_formFactor;
}

string SystemMemory::getChannel()
{
    return this->_channel;
}

string SystemMemory::getDimmName()
{
    return this->_dimmName;
}

void SystemMemory::setFormFactor(string newFormFactor)
{
    if (newFormFactor == "")
    {
        this->_formFactor = "N/A";
    }
    else
    {
        this->_formFactor = newFormFactor;
    }
}

void SystemMemory::setChannel(string newChannel)
{
    if (newChannel == "")
    {
        this->_channel = "N/A";
    }
    else
    {
        this->_channel = newChannel;
    }
}

void SystemMemory::setDimmName(string newDimmName)
{
    if (newDimmName == "")
    {
        this->_dimmName = "N/A";
    }
    else
    {
        this->_dimmName = newDimmName;
    }
}

void SystemMemory::setDescription(string newDescription)
{
    if (newDescription == "")
    {
        this->_description = "System Memory";
    }
    else
    {
        this->_description = newDescription;
    }
}

void SystemMemory::setType(string newType)
{
    if (newType == "")
    {
        this->_type = "DDR SDRAM";
    }
    else
    {
        this->_type = newType;
    }
}

map<string, ManagedElement*> ComputerSystem::getBaseBoards()
{
    return this->_baseBoards;
}

map<string, ManagedElement*> ComputerSystem::getDiskDrives()
{
    return this->_diskDrives;
}

map<string, ManagedElement*> ComputerSystem::getProcessors()
{
    return this->_processors;
}

map<string, ManagedElement*> ComputerSystem::getSystemMemory()
{
    return this->_systemMemory;
}

map<string, ManagedElement*> ComputerSystem::getVideoControllers()
{
    return this->_videoControllers;    
}

string ComputerSystem::getArchitecture()
{
    return this->_architecture;
}

string ComputerSystem::getOperatingSystemName()
{
    return this->_operatingSystemName;
}

void ComputerSystem::setBaseBoards(map<string, ManagedElement*> newBaseBoardsList)
{
    this->_baseBoards = newBaseBoardsList;
}

void ComputerSystem::setDescription(string newDescription)
{
    if (newDescription == "")
    {
        this->_description = "Computer System";
    }
    else
    {
        this->_description = newDescription;
    }
}

void ComputerSystem::setDiskDrives(map<string, ManagedElement*> newDiskDrivesList)
{
    this->_diskDrives = newDiskDrivesList;
}

void ComputerSystem::setProcessors(map<string, ManagedElement*> newProcessorsList)
{
    this->_processors = newProcessorsList;
}

void ComputerSystem::setSystemMemory(map<string, ManagedElement*> newSystemMemoryList)
{
    this->_systemMemory = newSystemMemoryList;
}

void ComputerSystem::setType(string newType)
{
    if (newType == "")
    {
        this->_type = "PC";
    }
    else
    {
        this->_type = newType;
    }
}

void ComputerSystem::setVideoControllers(map<string, ManagedElement*> newVideoControllersList)
{
    this->_videoControllers = newVideoControllersList;
}

void ComputerSystem::setArchitecture(string newArchitecture)
{
    if (newArchitecture == "")
    {
        this->_architecture = "N/A";
    }
    else
    {
        this->_architecture = newArchitecture;
    }
}

void ComputerSystem::setOperatingSystemName(string newOsName)
{
    if (newOsName == "")
    {
        this->_operatingSystemName = "N/A";
    }
    else
    {
        this->_operatingSystemName = newOsName;
    }
}

void IntegratedCircuit::serialize(json& j)
{
    j = json{{"_currentClock", this->_currentClock}, {"_voltage", this->_voltage}, {"_width", this->_width}};
}

void IntegratedCircuit::deSerialize(const json& j)
{
    j.at("_currentClock").get_to(this->_currentClock);
    j.at("_voltage").get_to(this->_voltage);
    j.at("_width").get_to(this->_width);
}

void StorageUnit::serialize(json& j)
{
    j = json{{"_size", this->_size}};
}

void StorageUnit::deSerialize(const json& j)
{
    j.at("_size").get_to(this->_size);
}

void Processor::serialize(json& j)
{
    json curJ = json{{"_busClock", this->_busClock}, {"_family", this->_family}, {"_maxClock", this->_maxClock},
    {"_socket", this->_socket}, {"_coreCount", this->_coreCount}, {"_enabledCoreCount", this->_enabledCoreCount},
    {"_threadCount", this->_threadCount}};
    json iCJ;
    json dJ;

    IntegratedCircuit::serialize(iCJ);
    Device::serialize(dJ);
    curJ.insert(iCJ.begin(), iCJ.end());
    curJ.insert(dJ.begin(), dJ.end());
    j = curJ;
}

void Processor::deSerialize(const json& j)
{
    this->IntegratedCircuit::deSerialize(j);
    this->Device::deSerialize(j);
    j.at("_busClock").get_to(this->_busClock);
    j.at("_family").get_to(this->_family);
    j.at("_maxClock").get_to(this->_maxClock);
    j.at("_socket").get_to(this->_socket);
    j.at("_coreCount").get_to(this->_coreCount);
    j.at("_enabledCoreCount").get_to(this->_enabledCoreCount);
    j.at("_threadCount").get_to(this->_threadCount);
}

void VideoController::serialize(json& j)
{
    json curJ = json{{"_videoProcessor", this->_videoProcessor}, {"_currentHorizontalResolution", this->_currentHorizontalResolution}, {"_currentRefreshRate", this->_currentRefreshRate},
    {"_currentVerticalResolution", this->_currentVerticalResolution}, {"_maxRefreshRate", this->_maxRefreshRate}, {"_minRefreshRate", this->_minRefreshRate}};
    json dJ;

    Device::serialize(dJ);
    curJ.insert(dJ.begin(), dJ.end());
    j = curJ;
}

void VideoController::deSerialize(const json& j)
{
    this->Device::deSerialize(j);
    j.at("_videoProcessor").get_to(this->_videoProcessor);
    j.at("_currentHorizontalResolution").get_to(this->_currentHorizontalResolution);
    j.at("_currentRefreshRate").get_to(this->_currentRefreshRate);
    j.at("_currentVerticalResolution").get_to(this->_currentVerticalResolution);
    j.at("_maxRefreshRate").get_to(this->_maxRefreshRate);
    j.at("_minRefreshRate").get_to(this->_minRefreshRate);
}

void DiskDrive::serialize(json& j)
{
    json curJ = json{{"_firmwareRevision", this->_firmwareRevision}, {"_interfaceType", this->_interfaceType}, {"_logicalName", this->_logicalName},
    {"_bytesPerSector", this->_bytesPerSector}};
    json sUJ;
    json dJ;

    StorageUnit::serialize(sUJ);
    Device::serialize(dJ);
    curJ.insert(sUJ.begin(), sUJ.end());
    curJ.insert(dJ.begin(), dJ.end());
    j = curJ;
}

void DiskDrive::deSerialize(const json& j)
{
    this->StorageUnit::deSerialize(j);
    this->Device::deSerialize(j);
    j.at("_firmwareRevision").get_to(this->_firmwareRevision);
    j.at("_interfaceType").get_to(this->_interfaceType);
    j.at("_logicalName").get_to(this->_logicalName);
    j.at("_bytesPerSector").get_to(this->_bytesPerSector);
}

void BaseBoard::serialize(json& j)
{
    json curJ = json{{"_isHosting", this->_isHosting}, {"_isHotswappable", this->_isHotswappable}, {"_isRemovable", this->_isRemovable},
    {"_isReplaceable", this->_isReplaceable}};
    json dJ;

    Device::serialize(dJ);
    curJ.insert(dJ.begin(), dJ.end());
    j = curJ;
}

void BaseBoard::deSerialize(const json& j)
{
    this->Device::deSerialize(j);
    j.at("_isHosting").get_to(this->_isHosting);
    j.at("_isHotswappable").get_to(this->_isHotswappable);
    j.at("_isRemovable").get_to(this->_isRemovable);
    j.at("_isReplaceable").get_to(this->_isReplaceable);
}

void SystemMemory::serialize(json& j)
{
    json curJ = json{{"_channel", this->_channel}, {"_dimmName", this->_dimmName}, {"_formFactor", this->_formFactor}};
    json sUJ;
    json iCJ;
    json dJ;

    StorageUnit::serialize(sUJ);
    IntegratedCircuit::serialize(iCJ);
    Device::serialize(dJ);
    curJ.insert(sUJ.begin(), sUJ.end());
    curJ.insert(iCJ.begin(), iCJ.end());
    curJ.insert(dJ.begin(), dJ.end());
    j = curJ;
}

void SystemMemory::deSerialize(const json& j)
{
    this->StorageUnit::deSerialize(j);
    this->IntegratedCircuit::deSerialize(j);
    this->Device::deSerialize(j);
    j.at("_channel").get_to(this->_channel);
    j.at("_dimmName").get_to(this->_dimmName);
    j.at("_formFactor").get_to(this->_formFactor);
}

void ComputerSystem::serialize(json& j)
{
    json curJ;
    json dJ;

    for (const auto& [key, value] : _baseBoards)
    {
        json baseBoardJ;

        ((BaseBoard*)value)->serialize(baseBoardJ);
        curJ["_baseBoards"] += baseBoardJ;
    }

    for (const auto& [key, value] : _diskDrives)
    {
        json diskDriveJ;

        ((DiskDrive*)value)->serialize(diskDriveJ);
        curJ["_diskDrives"] += diskDriveJ;
    }

    for (const auto& [key, value] : _processors)
    {
        json processorJ;

        ((Processor*)value)->serialize(processorJ);
        curJ["_processors"] += processorJ;
    }

    for (const auto& [key, value] : _systemMemory)
    {
        json systemMemoryJ;

        ((SystemMemory*)value)->serialize(systemMemoryJ);
        curJ["_systemMemory"] += systemMemoryJ;
    }

    for (const auto& [key, value] : _videoControllers)
    {
        json videoControllerJ;

        ((VideoController*)value)->serialize(videoControllerJ);
        curJ["_videoControllers"] += videoControllerJ;
    }

    curJ["_operatingSystemName"] = _operatingSystemName;
    curJ["_architecture"] = _architecture;

    Device::serialize(dJ);
    curJ.insert(dJ.begin(), dJ.end());

    j = curJ;
}

void ComputerSystem::deSerialize(const json& j)
{
    this->ManagedElement::deSerialize(j);
    
    for (json curJ : j["_baseBoards"])
    {
        BaseBoard* newB = new BaseBoard();

        newB->deSerialize(curJ);
        _baseBoards.insert({newB->getName(), newB});
    }

    for (json curJ : j["_diskDrives"])
    {
        DiskDrive* newD = new DiskDrive();

        newD->deSerialize(curJ);
        _diskDrives.insert({newD->getName(), newD});
    }

    for (json curJ : j["_processors"])
    {
        Processor* newP = new Processor();

        newP->deSerialize(curJ);
        _processors.insert({newP->getName(), newP});
    }

    for (json curJ : j["_systemMemory"])
    {
        SystemMemory* newM = new SystemMemory();

        newM->deSerialize(curJ);
        _systemMemory.insert({newM->getName(), newM});
    }

    for (json curJ : j["_videoControllers"])
    {
        VideoController* newC = new VideoController();

        newC->deSerialize(curJ);
        _videoControllers.insert({newC->getName(), newC});
    }

    j.at("_operatingSystemName").get_to(this->_operatingSystemName);
    j.at("_architecture").get_to(this->_architecture);
}
