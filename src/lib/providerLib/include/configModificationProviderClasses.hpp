#ifndef IG_CONFIG_CLASSES_PL
#define IG_CONFIG_CLASSES_PL

#include "commonInclude.hpp"
#include "coreProviderClasses.hpp"

class BasicOperationStateChangeProvider : public Provider
{
    public:
        using Provider::Provider;
        BasicOperationStateChangeProvider() { };
        void executeShutdownCommand();
        void executeRebootCommand();
};

#endif