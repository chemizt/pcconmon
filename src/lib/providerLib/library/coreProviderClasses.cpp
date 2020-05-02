#include "coreProviderClasses.hpp"

string Provider::executeCommand(string cmdToExec)
{
    string result = "";

    #ifdef _WIN32
    {
        string stdOut = "";
        string stdErr = "";
        uint32_t retCode = 0;

        SystemCapture(cmdToExec, stdOut, stdErr, retCode);

        if (!retCode) result = stdOut;
    }
    #else
    {
        string buffer;
        redi::ipstream command(cmdToExec, redi::pstreams::pstdout | redi::pstreams::pstderr);
    
        while (std::getline(command.out(), buffer))
        {
            result += buffer + "\n";
        }

        if (command.eof() && command.fail())
        {
            command.clear();
        }
    }
    #endif

    return result;
}