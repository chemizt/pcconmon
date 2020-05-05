#include "coreProviderClasses.hpp"

string CommandExecutor::executeCommand(string cmdToExec)
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

    result += "##########\n";

    return result;
}

vector<ManagedElement*> Provider::getAllManagedElements()
{
    return this->createdManagedElements;
}

uint16_t Provider::countRegexMatches(string infoString, string searchRegex)
{
    regex rgx(searchRegex);

    auto matchStart = sregex_iterator(infoString.begin(), infoString.end(), rgx);
    auto matchEnd = sregex_iterator();

    return std::distance(matchStart, matchEnd);
}
