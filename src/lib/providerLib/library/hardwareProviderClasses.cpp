#include "hardwareProviderClasses.hpp"

Processor* ProcessorProvider::createManagedElement()
{
    Processor* result = new Processor();
    string infoString = gatherInfo();
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
    regex currentClockRgx("Current Speed: ([0-9]+)");
    regex enabledCoreRgx("Core Enabled: ([0-9]+)");
    regex familyRgx("Family: (.+)");
    regex idRgx("ID: (.+)");
    regex maxClockRgx("Max Speed: ([0-9]+) MHz");
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

    return result;
}

VideoController* VideoControllerProvider::createManagedElement()
{
    VideoController* result = new VideoController();
    string infoString = gatherInfo();
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
    #else
    regex currentRefRateRgx("CurrentRefreshRate=([0-9]+)");
    regex refRateRgx("VertRefresh (([0-9]+)-([0-9]+))");
    regex resRgx("DisplaySize (([0-9]+) ([0-9]+))");
    regex nameRgx("\\WName=(.+)");
    regex videoProcessorRgx("VideoProcessor=(.+)");

    if (regex_search(infoString, matching, refRateRgx)) 
    {
        result->setMaxRefreshRate(std::stoi(matching[3]));
    }

    if (regex_search(infoString, matching, refRateRgx)) 
    {
        result->setMinRefreshRate(std::stoi(matching[2]));
    }

    if (regex_search(infoString, matching, resRgx)) 
    {
        result->setCurrentHorizontalResolution(std::stoi(matching[2]));
    }

    if (regex_search(infoString, matching, resRgx)) 
    {
        result->setCurrentVerticalResolution(std::stoi(matching[3]));
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

    return result;
}

string ProcessorProvider::gatherInfo()
{
    stringstream result;

    #ifdef _WIN32
    string stdOut = "";
    string stdErr = "";
    uint32_t retCode = 0;

    SystemCapture("wmic cpu get /all /format:textvaluelist", stdOut, stdErr, retCode);

    if (!retCode) result << stdOut;
    #else
    string buffer;
    redi::ipstream command("dmidecode -t 4", redi::pstreams::pstdout | redi::pstreams::pstderr);
    
    while (std::getline(command.out(), buffer))
    {
        result << buffer << "\n";
    }
    
    if (command.eof() && command.fail())
    {
        command.clear();
    }
    #endif

    return result.str();
}

string VideoControllerProvider::gatherInfo()
{
    stringstream result;

    #ifdef _WIN32
    string stdOut = "";
    string stdErr = "";
    uint32_t retCode = 0;

    SystemCapture("wmic path win32_videocontroller get /all /format:textvaluelist", stdOut, stdErr, retCode);

    if (!retCode) result << stdOut;
    #else
    string buffer;
    redi::ipstream command("get-edid | parse-edid", redi::pstreams::pstdout | redi::pstreams::pstderr);
    
    while (std::getline(command.out(), buffer))
    {
        result << buffer << "\n";
    }
    
    if (command.eof() && command.fail())
    {
        command.clear();
    }
    #endif

    return result.str();
}
