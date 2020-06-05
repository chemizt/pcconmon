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
    if (newManufacturer == "")
    {
        this->_manufacturer = "N/A";
    }
    else
    {
        this->_manufacturer = newManufacturer;
    }
}

void Device::setVersion(string newVersion)
{
    if (newVersion == "")
    {
        this->_version = "N/A";
    }
    else
    {
        this->_version = newVersion;
    }
}

void Device::setCapabilities(string newCapabilities)
{
    if (newCapabilities == "")
    {
        this->_capabilities = "N/A";
    }
    else
    {
        this->_capabilities = newCapabilities;
    }
}

void Device::setSerialNumber(string newSerialNumber)
{
    if (newSerialNumber == "")
    {
        this->_serialNumber = "N/A";
    }
    else
    {
        this->_serialNumber = newSerialNumber;
    }
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

void Device::setPartNumber(string newPartNumber)
{
    if (newPartNumber == "")
    {
        this->_partNumber = "N/A";
    }
    else
    {
        this->_partNumber = newPartNumber;
    }
}

string Device::getPartNumber()
{
    return this->_partNumber;
}

void ManagedElement::serialize(json& j)
{
    j = json{{"_description", this->_description}, {"_id", this->_id}, {"_name", this->_name}};
}

void ManagedElement::deSerialize(const json& j)
{
    j.at("_description").get_to(this->_description);
    j.at("_id").get_to(this->_id);
    j.at("_name").get_to(this->_name);
}

void Device::serialize(json& j)
{
    json curJ = json{{"_capabilities", this->_capabilities}, {"_manufacturer", this->_manufacturer}, {"_model", this->_model},
    {"_partNumber", this->_partNumber}, {"_serialNumber", this->_serialNumber}, {"_type", this->_type},
    {"_version", this->_version}};
    json mJ;

    ManagedElement::serialize(mJ);
    curJ.insert(mJ.begin(), mJ.end());
    j = curJ;
}

void Device::deSerialize(const json& j)
{
    this->ManagedElement::deSerialize(j);
    j.at("_capabilities").get_to(this->_capabilities);
    j.at("_manufacturer").get_to(this->_manufacturer);
    j.at("_model").get_to(this->_model);
    j.at("_partNumber").get_to(this->_partNumber);
    j.at("_serialNumber").get_to(this->_serialNumber);
    j.at("_type").get_to(this->_type);
    j.at("_version").get_to(this->_version);
}
