#include "coreDataClasses.hpp"

string ManagedElement::getId()
{
    return this->id;
}

string ManagedElement::getName()
{
    return this->name;
}

string ManagedElement::getDescription()
{
    return this->description;
}

void ManagedElement::setId(string newId)
{
    this->id = newId;
}

void ManagedElement::setName(string newName)
{
    this->name = newName;
}

string Device::getManufacturer()
{
    return this->manufacturer;
}

string Device::getCapabilities()
{
    return this->capabilities;
}

string Device::getType()
{
    return this->type;
}

string Device::getVersion()
{
    return this->version;
}

void Device::setManufacturer(string newManufacturer)
{
    this->manufacturer = newManufacturer;
}

void Device::setVersion(string newVersion)
{
    this->version = newVersion;
}

void Device::setCapabilities(string newCapabilities)
{
    this->capabilities = newCapabilities;
}
