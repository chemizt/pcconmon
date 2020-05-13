#include "coreDataClasses.hpp"

string ManagedElement::getId()
{
    return this->_id;
}

string ManagedElement::getName()
{
    return this->_name;
}

string ManagedElement::getDescription()
{
    return this->_description;
}

void ManagedElement::setId(string newId)
{
    this->_id = newId;
}

void ManagedElement::setName(string newName)
{
    this->_name = newName;
}

string Device::getManufacturer()
{
    return this->_manufacturer;
}

string Device::getCapabilities()
{
    return this->_capabilities;
}

string Device::getType()
{
    return this->_type;
}

string Device::getVersion()
{
    return this->_version;
}

string Device::getSerialNumber()
{
    return this->_serialNumber;
}

void Device::setManufacturer(string newManufacturer)
{
    this->_manufacturer = newManufacturer;
}

void Device::setVersion(string newVersion)
{
    this->_version = newVersion;
}

void Device::setCapabilities(string newCapabilities)
{
    this->_capabilities = newCapabilities;
}

void Device::setSerialNumber(string newSerialNumber)
{
    this->_serialNumber = newSerialNumber;
}

void Device::setModel(string newModel)
{
    if (newModel == "")
    {
        this->_model = "N/A";
    }
    else
    {
        this->_model = newModel;
    }
}

string Device::getModel()
{
    return this->_model;
}
