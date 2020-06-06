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

    return result;
}

vector<ManagedElement*> InformationProvider::getAllManagedElements()
{
    return this->_createdManagedElements;
}

vector<string> InformationProvider::splitStringByRegex(string infoString, string splitRegex)
{
    regex rgx(splitRegex);
    smatch matching;
    string currStr;
    vector<string> result;

    sregex_token_iterator iter(infoString.begin(), infoString.end(), rgx, -1);
    sregex_token_iterator end;

    for (; iter != end; ++iter)
    {
        currStr = *iter;

        if (regex_search(currStr, matching, regex("\\w"))) result.push_back(*iter);
    }

    return result;
}
