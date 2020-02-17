#include "auxClasses.hpp"

ManagedElement* ProcessorFactory::create()
{
    Processor* newProcessor = new Processor();
    newProcessor->setType("");
    newProcessor->setDescription("");
    return newProcessor;
}