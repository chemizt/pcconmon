#include "coreProviderClasses.hpp"

string Provider::executeCommand(string command)
{
    string result = "";

    #ifdef _WIN32
    {
        string stdOut = "";
        string stdErr = "";
        uint32_t retCode = 0;

        SystemCapture(command, stdOut, stdErr, retCode);

        if (!retCode) result = stdOut;
    }
    #else
    {
        redi::ipstream command(command, redi::pstreams::pstdout | redi::pstreams::pstderr);
    
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