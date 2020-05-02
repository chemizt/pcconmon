#ifndef IG_CORE_CLASSES_PL
#define IG_CORE_CLASSES_PL

#include <sstream>

#include "commonInclude.hpp"
#include "coreDataClasses.hpp"
#ifdef _WIN32
#include "winCmdExec.hpp"
#else
#include "pstream.h"
#endif

class Provider
{
    protected:
        virtual string gatherInfo() = 0;
        string executeCommand(string cmdToExec);
    public:
        Provider() { };
        virtual ManagedElement* createManagedElement() = 0;
};

#endif
