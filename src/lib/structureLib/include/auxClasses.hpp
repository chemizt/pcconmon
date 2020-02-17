#ifndef IG_AUX_CLASSES_SL
#define IG_AUX_CLASSES_SL

#include "coreClasses.hpp"
#include "hardwareClasses.hpp"
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