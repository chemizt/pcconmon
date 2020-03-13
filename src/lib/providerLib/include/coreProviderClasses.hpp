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

using std::stringstream;

class Provider
{
    protected:
        virtual string gatherInfo() = 0;
    public:
        Provider() { };
        virtual ManagedElement* createManagedElement() = 0;
};

#endif
