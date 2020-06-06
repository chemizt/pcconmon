#include "configModificationProviderClasses.hpp"

void BasicOperationStateChangeProvider::executeShutdownCommand()
{
    #ifdef _WIN32
    _cmdExecutor->executeCommand("shutdown /s /t 60");
    #else
    _cmdExecutor->executeCommand("shutdown -t 60");
    #endif
}

void BasicOperationStateChangeProvider::executeRebootCommand()
{
    #ifdef _WIN32
    _cmdExecutor->executeCommand("shutdown /g /t 60");
    #else
    _cmdExecutor->executeCommand("shutdown -r -t 60");
    #endif
}
