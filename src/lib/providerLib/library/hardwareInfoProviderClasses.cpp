#include "hardwareInfoProviderClasses.hpp"

#pragma region createManagedElement

void ProcessorProvider::createManagedElement(string infoString)
{
    Processor* result = new Processor();
    smatch matching;

    #ifdef _WIN32
    regex busClockRgx("ExtClock=([0-9]+)");
    regex coreRgx("NumberOfCores=([0-9]+)");
    regex currentClockRgx("CurrentClockSpeed=([0-9]+)");
    regex enabledCoreRgx("NumberOfEnabledCore=([0-9]+)");
    regex familyRgx("Family=(.+)");
    regex idRgx("ProcessorId=(.+)");
    regex maxClockRgx("MaxClockSpeed=([0-9]+)");
    regex nameRgx("\\WName=(.+)");
    regex socketRgx("SocketDesignation=(.+)");
    regex threadRgx("ThreadCount=([0-9]+)");
    regex widthRgx("AddressWidth=([0-9]+)");
    #else
    regex busClockRgx("External Clock: ([0-9]+)");
    regex coreRgx("Core Count: ([0-9]+)");
    regex currentClockRgx("CPU MHz: +([0-9]+)");
    regex enabledCoreRgx("Core Enabled: ([0-9]+)");
    regex familyRgx("Family: (.+)");
    regex idRgx("ID: (.+)");
    regex maxClockRgx("CPU max MHz: +([0-9]+)");
    regex nameRgx("Version: (.+)");
    regex socketRgx("Socket Designation: (.+)");
    regex threadRgx("Thread Count: ([0-9]+)");
    regex widthRgx("([0-9]+)-bit capable");
    #endif
    
    if (regex_search(infoString, matching, busClockRgx)) 
    {
        result->setBusClock(matching[1]);
    }

    if (regex_search(infoString, matching, maxClockRgx)) 
    {
        result->setMaxClock(matching[1]);
    }

    if (regex_search(infoString, matching, currentClockRgx)) 
    {
        result->setCurrentClock(matching[1]);
    }

    if (regex_search(infoString, matching, familyRgx)) 
    {
        result->setFamily(matching[1]);
    }

    if (regex_search(infoString, matching, idRgx)) 
    {
        result->setId(matching[1]);
    }
    
    if (regex_search(infoString, matching, nameRgx)) 
    {
        result->setName(matching[1]);
    }

    if (regex_search(infoString, matching, socketRgx)) 
    {
        result->setSocket(matching[1]);
    }

    if (regex_search(infoString, matching, widthRgx)) 
    {
        result->setWidth(matching[1]);
    }

    if (regex_search(infoString, matching, coreRgx))
    {
        result->setCoreCount(matching[1]);
    }

    if (regex_search(infoString, matching, threadRgx))
    {
        result->setThreadCount(matching[1]);
    }

    if (regex_search(infoString, matching, enabledCoreRgx))
    {
        result->setEnabledCoreCount(matching[1]);
    }

    _createdManagedElements.push_back(result);
}

void VideoControllerProvider::createManagedElement(string infoString)
{
    VideoController* result = new VideoController();
    smatch matching;

    #ifdef _WIN32
    regex currentHorResRgx("CurrentHorizontalResolution=([0-9]+)");
    regex currentRefRateRgx("CurrentRefreshRate=([0-9]+)");
    regex currentVerResRgx("CurrentVerticalResolution=([0-9]+)");
    regex maxRefRateRgx("MaxRefreshRate=([0-9]+)");
    regex minRefRateRgx("MinRefreshRate=([0-9]+)");
    regex nameRgx("\\WName=(.+)");
    regex videoProcessorRgx("VideoProcessor=(.+)");

    if (regex_search(infoString, matching, maxRefRateRgx)) 
    {
        result->setMaxRefreshRate(matching[1]);
    }

    if (regex_search(infoString, matching, minRefRateRgx)) 
    {
        result->setMinRefreshRate(matching[1]);
    }

    if (regex_search(infoString, matching, currentHorResRgx)) 
    {
        result->setCurrentHorizontalResolution(matching[1]);
    }
    
    if (regex_search(infoString, matching, currentVerResRgx)) 
    {
        result->setCurrentVerticalResolution(matching[1]);
    }
    #else
    regex currentRefRateRgx("CurrentRefreshRate=([0-9]+)");
    regex refRateRgx("VertRefresh ([0-9]+)-([0-9]+)");
    regex resRgx("DisplaySize ([0-9]+) ([0-9]+)");
    regex nameRgx("product: (.+)");
    regex videoProcessorRgx("product: (.+)");

    if (regex_search(infoString, matching, refRateRgx)) 
    {
        result->setMaxRefreshRate(matching[2]);
    }

    if (regex_search(infoString, matching, refRateRgx)) 
    {
        result->setMinRefreshRate(matching[1]);
    }

    if (regex_search(infoString, matching, resRgx)) 
    {
        result->setCurrentHorizontalResolution(matching[1]);
    }

    if (regex_search(infoString, matching, resRgx)) 
    {
        result->setCurrentVerticalResolution(matching[2]);
    }
    #endif

    if (regex_search(infoString, matching, nameRgx)) 
    {
        result->setName(matching[1]);
    }

    if (regex_search(infoString, matching, currentRefRateRgx)) 
    {
        result->setCurrentRefreshRate(matching[1]);
    }

    if (regex_search(infoString, matching, videoProcessorRgx)) 
    {
        result->setVideoProcessor(matching[1]);
    }

    _createdManagedElements.push_back(result);
}

void DiskDriveProvider::createManagedElement(string infoString)
{
    DiskDrive* result = new DiskDrive();
    smatch matching;

    #ifdef _WIN32
    regex bytesPerSectorRgx("BytesPerSector=(.+)");
    regex fwRevRgx("FirmwareRevision=(.+)");
    regex intTypeRgx("InterfaceType=(.+)");
    regex logNameRgx("\\WDeviceID=(.+)");
    regex manModelRgx("Model=(\\w+)* (.+)");
    regex nameRgx("Caption=(.+)");
    regex serNoRgx("SerialNumber=\\s*([\\w-_]+)");
    regex sizeRgx("Size=(.+)");

    if (regex_search(infoString, matching, intTypeRgx)) 
    {
        result->setInterfaceType(matching[1]);
    }
    #else
    regex bytesPerSectorRgx("Physical Sector size:\\s+([0-9]+)");
    regex fwRevRgx("Firmware Revision:\\s+(\\w+)");
    regex logNameRgx("logical name: (.+)");
    regex manModelRgx("Model Number:\\s+(\\w+)* (\\w+)");
    regex nameRgx("product: (.+)");
    regex serNoRgx("serial: (.+)");
    regex sizeRgx("device size with M = 1024\\*1024:\\s+([0-9]+)");
    regex versionRgx("version: (.+)");

    if (regex_search(infoString, matching, versionRgx)) 
    {
        result->setVersion(matching[1]);
    }
    #endif

    if (regex_search(infoString, matching, bytesPerSectorRgx)) 
    {
        result->setBytesPerSector(matching[1]);
    }
    
    if (regex_search(infoString, matching, fwRevRgx)) 
    {
        result->setFirmwareRevision(matching[1]);
    }

    if (regex_search(infoString, matching, logNameRgx)) 
    {
        result->setLogicalName(matching[1]);
    }

    if (regex_search(infoString, matching, manModelRgx)) 
    {
        result->setManufacturer(matching[1]);
        result->setModel(matching[2]);
    }

    if (regex_search(infoString, matching, nameRgx)) 
    {
        result->setName(matching[1]);
    }

    if (regex_search(infoString, matching, serNoRgx)) 
    {
        result->setSerialNumber(matching[1]);
    }

    if (regex_search(infoString, matching, sizeRgx)) 
    {
        #ifdef _WIN32
        result->setSize(matching[1]);
        #else
        result->setSize(std::to_string(std::stoull(matching[1]) * 1024 * 1024));
        #endif
    }

    _createdManagedElements.push_back(result);
}

void BaseBoardProvider::createManagedElement(string infoString)
{
    BaseBoard* result = new BaseBoard();
    smatch matching;

    #ifdef _WIN32
    regex modelRgx("Product=(.+)");
    regex manufacturerRgx("Manufacturer=(.+)");
    regex versionRgx("Version=(.+)");
    regex serNoRgx("SerialNumber=(.+)");
    regex isHostingRgx("HostingBoard=TRUE");
    regex isHotswappableRgx("HotSwappable=TRUE");
    regex isRemovableRgx("Removable=TRUE");
    regex isReplaceableRgx("Replaceable=TRUE");
    #else
    regex modelRgx("Product Name: (.+)");
    regex manufacturerRgx("Manufacturer: (.+)");
    regex versionRgx("Version: (.+)");
    regex serNoRgx("Serial Number: (.+)");
    regex isHostingRgx("Board is a hosting board");
    regex isHotswappableRgx("Board is hotswappable");
    regex isRemovableRgx("Board is removable");
    regex isReplaceableRgx("Board is replaceable");
    #endif
    
    if (regex_search(infoString, matching, modelRgx)) 
    {
        result->setModel(matching[1]);
    }

    if (regex_search(infoString, matching, manufacturerRgx)) 
    {
        result->setManufacturer(matching[1]);
    }
    
    if (regex_search(infoString, matching, versionRgx)) 
    {
        result->setVersion(matching[1]);
    }

    if (regex_search(infoString, matching, serNoRgx)) 
    {
        result->setSerialNumber(matching[1]);
    }

    if (regex_search(infoString, matching, isHostingRgx)) 
    {
        result->setHosting();
    }

    if (regex_search(infoString, matching, isHotswappableRgx)) 
    {
        result->setHotswappable();
    }
    
    if (regex_search(infoString, matching, isRemovableRgx)) 
    {
        result->setRemovable();
    }

    if (regex_search(infoString, matching, isReplaceableRgx)) 
    {
        result->setReplaceable();
    }

    result->setName(result->getModel());

    _createdManagedElements.push_back(result);
}

void SystemMemoryProvider::createManagedElement(string infoString)
{
    SystemMemory* result = new SystemMemory();
    smatch matching;

    #ifdef _WIN32
    regex capacityRgx("Capacity=(.+)");
    regex channelRgx("BankLabel=\\w+ (.+)");
    regex clockRgx("ConfiguredClockSpeed=(.+)");
    regex dimmRgx("DeviceLocator=(.+)");
    regex formFactorRgx("FormFactor=(.+)");
    regex manufacturerRgx("Manufacturer=(.+)");
    regex partNoRgx("PartNumber=(.+)");
    regex serNoRgx("SerialNumber=(.+)");
    regex typeRgx("TypeDetail=(.+)");
    regex voltageRgx("ConfiguredVoltage=(.+)");
    regex widthRgx("TotalWidth=(.+)");
    #else
    regex capacityRgx("Size: ([0-9]+)");
    regex channelRgx("Locator: (\\w+)-");
    regex clockRgx("Configured Memory Speed: ([0-9]+)");
    regex dimmRgx("Locator: \\w+-(\\w+)");
    regex formFactorRgx("Form Factor: (.+)");
    regex manufacturerRgx("Manufacturer: (.+)");
    regex partNoRgx("Part Number: (.+)");
    regex serNoRgx("Serial Number: (.+)");
    regex typeRgx("Type: (.+)");
    regex voltageRgx("Configured Voltage: ([0-9.]+)");
    regex widthRgx("Total Width: ([0-9]+)");
    #endif
    
    if (regex_search(infoString, matching, capacityRgx)) 
    {
        #ifdef _WIN32
        result->setSize(matching[1]);
        #else
        result->setSize(std::to_string(std::stoull(matching[1]) * 1024 * 1024));
        #endif
    }

    if (regex_search(infoString, matching, channelRgx)) 
    {
        result->setChannel(matching[1]);
    }

    if (regex_search(infoString, matching, clockRgx)) 
    {
        result->setCurrentClock(matching[1]);
    }

    if (regex_search(infoString, matching, dimmRgx)) 
    {
        result->setDimmName(matching[1]);
    }

    if (regex_search(infoString, matching, formFactorRgx)) 
    {
        result->setFormFactor(matching[1]);
    }

    if (regex_search(infoString, matching, manufacturerRgx)) 
    {
        result->setManufacturer(matching[1]);
    }
    
    if (regex_search(infoString, matching, partNoRgx)) 
    {
        result->setPartNumber(matching[1]);
    }
    
    if (regex_search(infoString, matching, serNoRgx)) 
    {
        result->setSerialNumber(matching[1]);
    }

    if (regex_search(infoString, matching, typeRgx)) 
    {
        result->setType(matching[1]);
    }

    if (regex_search(infoString, matching, voltageRgx)) 
    {
        #ifdef _WIN32
        result->setVoltage(std::to_string(std::stof(matching[1]) / 1000).substr(0, 4));
        #else
        result->setVoltage(matching[1]);
        #endif
    }

    if (regex_search(infoString, matching, widthRgx)) 
    {
        result->setWidth(matching[1]);
    }

    result->setName("Физическая память " + result->getDimmName() + "-" + result->getChannel());

    _createdManagedElements.push_back(result);
}

void ComputerSystemProvider::createManagedElement(string infoString)
{
    ComputerSystem* result = new ComputerSystem();

    smatch matching;

    #ifdef _WIN32
    regex osNameRgx("Caption=.+(Windows.+)");
    regex csNameRgx("CSName=(.+)");
    regex architectureRgx("OSArchitecture=([0-9]+)");
    #else
    regex osNameRgx("Operating System: (.+)");
    regex csNameRgx("Static hostname: (.+)");
    regex architectureRgx("Architecture: (.+)");
    #endif
    
    if (regex_search(infoString, matching, osNameRgx)) 
    {
        result->setOperatingSystemName(matching[1]);
    }
    else
    {
        result->setOperatingSystemName("");
    }

    if (regex_search(infoString, matching, csNameRgx)) 
    {
        result->setName(matching[1]);
    }
    else
    {
        result->setName("");
    }

    if (regex_search(infoString, matching, architectureRgx)) 
    {
        #ifdef _WIN32
        result->setArchitecture("x" + matching[1].str());
        #else
        result->setArchitecture(matching[1]);
        #endif
    }
    else
    {
        result->setArchitecture("");
    }

    _baseBoardProv.scanForManagedElements();
    _diskDriveProv.scanForManagedElements();
    _processorProv.scanForManagedElements();
    _sysMemProv.scanForManagedElements();
    _vidConProv.scanForManagedElements(); 


    vector<ManagedElement*> bbs = _baseBoardProv.getAllManagedElements();
    vector<ManagedElement*> dds = _diskDriveProv.getAllManagedElements();
    vector<ManagedElement*> procs = _processorProv.getAllManagedElements();
    vector<ManagedElement*> sm = _sysMemProv.getAllManagedElements();
    vector<ManagedElement*> vcs = _vidConProv.getAllManagedElements();

    map<string, ManagedElement*> bbsm;
    map<string, ManagedElement*> ddsm;
    map<string, ManagedElement*> procsm;
    map<string, ManagedElement*> smm;
    map<string, ManagedElement*> vcsm;

    for (ManagedElement* me : bbs)
    {
        bbsm.insert({me->getName(), me});
    }

    for (ManagedElement* me : dds)
    {
        ddsm.insert({me->getName(), me});
    }

    for (ManagedElement* me : procs)
    {
        procsm.insert({me->getName(), me});
    }

    for (ManagedElement* me : sm)
    {
        smm.insert({me->getName(), me});
    }

    for (ManagedElement* me : vcs)
    {
        vcsm.insert({me->getName(), me});
    }

    result->setBaseBoards(bbsm);
    result->setDiskDrives(ddsm);
    result->setProcessors(procsm);
    result->setSystemMemory(smm);
    result->setVideoControllers(vcsm);

    _createdManagedElements.push_back(result);
}

#pragma endregion
#pragma region gatherBasicInfo

string ProcessorProvider::gatherBasicInfo()
{
    string result = "";

    #ifdef _WIN32
    result += _cmdExecutor->executeCommand("wmic path win32_processor get /all /format:textvaluelist");
    #else
    result += _cmdExecutor->executeCommand("dmidecode -t 4");
    result += _cmdExecutor->executeCommand("lscpu");
    #endif

    return result;
}

string VideoControllerProvider::gatherBasicInfo()
{
    string result = "";

    #ifdef _WIN32
    result += _cmdExecutor->executeCommand("wmic path win32_videocontroller get /all /format:textvaluelist");
    #else
    result += _cmdExecutor->executeCommand("get-edid | parse-edid");
    result += _cmdExecutor->executeCommand("lshw -c display");
    #endif

    return result;
}

string DiskDriveProvider::gatherBasicInfo()
{
    string result = "";

    #ifdef _WIN32
    result += _cmdExecutor->executeCommand("wmic path win32_diskdrive get /all /format:textvaluelist");
    #else
    result += _cmdExecutor->executeCommand("lshw -c disk");
    #endif

    return result;
}

string BaseBoardProvider::gatherBasicInfo()
{
    string result = "";

    #ifdef _WIN32
    result += _cmdExecutor->executeCommand("wmic path win32_baseboard get /all /format:textvaluelist");
    #else
    result += _cmdExecutor->executeCommand("dmidecode -t 2");
    #endif

    return result;
}

string SystemMemoryProvider::gatherBasicInfo()
{
    string result = "";

    #ifdef _WIN32
    result += _cmdExecutor->executeCommand("wmic path win32_physicalmemory get /all /format:textvaluelist");
    #else
    result += _cmdExecutor->executeCommand("dmidecode -t 17");
    #endif

    return result;
}

string ComputerSystemProvider::gatherBasicInfo()
{
    string result = "";

    #ifdef _WIN32
    result += _cmdExecutor->executeCommand("wmic path win32_operatingsystem get /all /format:textvaluelist");
    #else
    result += _cmdExecutor->executeCommand("hostnamectl");
    #endif

    return result;
}

#pragma endregion
#pragma region gatherAdvancedInfo

string DiskDriveProvider::gatherAdvancedInfo(string basicInfo)
{
    smatch matching;
    string result = "";

    if (regex_search(basicInfo, matching, regex("(\\/dev\\/\\w+)")))
    {
        result += _cmdExecutor->executeCommand("hdparm -I " + matching[1].str());
    }

    return result;
}

#pragma endregion
#pragma region scanForManagedElements

void ProcessorProvider::scanForManagedElements() //TODO: work out a way to parse output for multiple CPUs
{
    string scanResult = this->gatherBasicInfo();
        
    this->createManagedElement(scanResult);
}

void VideoControllerProvider::scanForManagedElements() //TODO: same as for ProcessorProvider
{
    string scanResult = this->gatherBasicInfo();
        
    this->createManagedElement(scanResult);
}

void BaseBoardProvider::scanForManagedElements() //TODO: same as for ProcessorProvider
{
    string scanResult = this->gatherBasicInfo();
        
    this->createManagedElement(scanResult);
}

void ComputerSystemProvider::scanForManagedElements()
{
    string scanResult = this->gatherBasicInfo();
        
    this->createManagedElement(scanResult);
}

void DiskDriveProvider::scanForManagedElements()
{
    string scanResult = this->gatherBasicInfo();
    string splRgx;
    vector<string> splResult;

    #ifdef _WIN32
    splRgx = "(\\r\\r\\n){2,3}";
    #else
    splRgx = "\\*\\-disk";
    #endif

    splResult = splitStringByRegex(scanResult, splRgx);

    for (string subRes : splResult)
    {
        #ifdef _WIN32
        this->createManagedElement(subRes);
        #else
        this->createManagedElement(subRes + this->gatherAdvancedInfo(subRes));
        #endif
    }
}

void SystemMemoryProvider::scanForManagedElements()
{
    string scanResult = this->gatherBasicInfo();
    string splRgx;
    smatch matching;
    vector<string> splResult;

    #ifdef _WIN32
    splRgx = "(\\r\\r\\n){2,3}";
    #else
    splRgx = "Memory Device";
    #endif

    splResult = splitStringByRegex(scanResult, splRgx);

    for (string subRes : splResult)
    {
        if (regex_search(subRes, matching, regex("Memory"))) 
        {
            this->createManagedElement(subRes);
        }
    }
}

#pragma endregion