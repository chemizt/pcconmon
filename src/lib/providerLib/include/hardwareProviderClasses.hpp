#ifndef IG_HARDWARE_CLASSES_PL
#define IG_HARDWARE_CLASSES_PL

#include <regex>

#include "commonInclude.hpp"
#include "coreProviderClasses.hpp"
#include "hardwareDataClasses.hpp"

using std::regex;
using std::smatch;
using std::regex_search;

class ProcessorProvider : public Provider
{
    protected:
    public:
        using Provider::Provider;
        ProcessorProvider();
        Processor* createManagedElement();
        string gatherInfo();
};

#endif
