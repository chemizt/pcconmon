#ifndef IG_AUX_CLASSES_SL
#define IG_AUX_CLASSES_SL

#include "coreDataClasses.hpp"
#include "hardwareDataClasses.hpp"
#include "commonInclude.hpp"

class ManagedElementFactory
{
    public:
        virtual ManagedElement* create() = 0;
};

class ProcessorFactory : public ManagedElementFactory
{
    public:
        ManagedElement* create();
};

#endif
