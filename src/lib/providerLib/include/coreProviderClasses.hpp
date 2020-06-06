#ifndef IG_CORE_CLASSES_PL
#define IG_CORE_CLASSES_PL

#include "commonInclude.hpp"
#include "coreDataClasses.hpp"
#ifdef _WIN32
#include "winCmdExec.hpp"
#else
#include "pstream.h"
#endif

class CommandExecutor
{
    public:
        CommandExecutor() { };
        string executeCommand(string cmdToExec);
};

class Provider
{
    protected:
        CommandExecutor* _cmdExecutor;
    public:
        Provider() { _cmdExecutor = new CommandExecutor(); };
};

class InformationProvider : public Provider
{
    protected:
        vector<ManagedElement*> _createdManagedElements;
        virtual void createManagedElement(string infoString) = 0;
        virtual string gatherBasicInfo() = 0;
        vector<string> splitStringByRegex(string infoString, string splitRegex);
    public:
        using Provider::Provider;
        virtual void scanForManagedElements() = 0;
        vector<ManagedElement*> getAllManagedElements();
};

#endif
