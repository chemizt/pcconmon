#include "hardwareProviderClasses.hpp"

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
        result->setWidth(std::stoi(matching[1]));
    }

    if (regex_search(infoString, matching, coreRgx))
    {
        result->setCoreCount(std::stoi(matching[1]));
    }

    if (regex_search(infoString, matching, threadRgx))
    {
        result->setThreadCount(std::stoi(matching[1]));
    }

    if (regex_search(infoString, matching, enabledCoreRgx))
    {
        result->setEnabledCoreCount(std::stoi(matching[1]));
    }

    createdManagedElements.push_back(result);
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
        result->setMaxRefreshRate(std::stoi(matching[1]));
    }

    if (regex_search(infoString, matching, minRefRateRgx)) 
    {
        result->setMinRefreshRate(std::stoi(matching[1]));
    }

    if (regex_search(infoString, matching, currentHorResRgx)) 
    {
        result->setCurrentHorizontalResolution(std::stoi(matching[1]));
    }
    
    if (regex_search(infoString, matching, currentVerResRgx)) 
    {
        result->setCurrentVerticalResolution(std::stoi(matching[1]));
    }
    #else // TODO: work out a way to get video processor info and current refresh rate (LINUX)
    regex currentRefRateRgx("CurrentRefreshRate=([0-9]+)"); // TODO rework this
    regex refRateRgx("VertRefresh ([0-9]+)-([0-9]+)");
    regex resRgx("DisplaySize ([0-9]+) ([0-9]+)");
    regex nameRgx("product: (.+)");
    regex videoProcessorRgx("VideoProcessor=(.+)"); // TODO rework that

    if (regex_search(infoString, matching, refRateRgx)) 
    {
        result->setMaxRefreshRate(std::stoi(matching[2]));
    }

    if (regex_search(infoString, matching, refRateRgx)) 
    {
        result->setMinRefreshRate(std::stoi(matching[1]));
    }

    if (regex_search(infoString, matching, resRgx)) 
    {
        result->setCurrentHorizontalResolution(std::stoi(matching[1]));
    }

    if (regex_search(infoString, matching, resRgx)) 
    {
        result->setCurrentVerticalResolution(std::stoi(matching[2]));
    }
    #endif

    if (regex_search(infoString, matching, nameRgx)) 
    {
        result->setName(matching[1]);
    }

    if (regex_search(infoString, matching, currentRefRateRgx)) 
    {
        result->setCurrentRefreshRate(std::stoi(matching[1]));
    }

    if (regex_search(infoString, matching, videoProcessorRgx)) 
    {
        result->setVideoProcessor(matching[1]);
    }

    createdManagedElements.push_back(result);
}

void DiskDriveProvider::createManagedElement(string infoString)
{
    DiskDrive* result = new DiskDrive();
    smatch matching;

    #ifdef _WIN32
    
    #else

    #endif

    createdManagedElements.push_back(result);
}

#pragma endregion
#pragma region gatherBasicInfo

string ProcessorProvider::gatherBasicInfo()
{
    string result = "";

    #ifdef _WIN32
    result += cmdExecutor->executeCommand("wmic cpu get /all /format:textvaluelist");
    #else
    result += cmdExecutor->executeCommand("dmidecode -t 4");
    result += cmdExecutor->executeCommand("lscpu");
    #endif

    return result;
}

string VideoControllerProvider::gatherBasicInfo()
{
    string result = "";

    #ifdef _WIN32
    result += cmdExecutor->executeCommand("wmic path win32_videocontroller get /all /format:textvaluelist");
    #else
    result += cmdExecutor->executeCommand("get-edid | parse-edid");
    result += cmdExecutor->executeCommand("lshw -c display");
    #endif

    return result;
}

string DiskDriveProvider::gatherBasicInfo()
{
    string result = "";

    #ifdef _WIN32
    result += cmdExecutor->executeCommand("wmic path win32_diskdrive get /all /format:textvaluelist");
    #else
    result += cmdExecutor->executeCommand("lshw -c disk");
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
        result += cmdExecutor->executeCommand("hdparm -I " + matching[1].str());
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

void DiskDriveProvider::scanForManagedElements()
{
    string scanResult = this->gatherBasicInfo();
    string splRgx;
    vector<string> splResult;

    #ifdef _WIN32
    splRgx = "(\\r\\r\\n){2,3}";
    #else
    splRgx = "\\R\\s+\\*";
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

#pragma endregion