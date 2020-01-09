#include "coreDataStructures.hpp"

Device::Device(int newId, string newName)
{
    this->id = newId;
    this->name = newName;
}

Device::Device(int newId, string newName, string newDescription)
{
    this->id = newId;
    this->name = newName;
    this->description = newDescription;
}

int Device::getId()
{
    return this->id;
}

string Device::getName()
{
    return this->name;
}

string Device::getDescription()
{
    return this->description;
}

void Device::setId(int newId)
{
    this->id = newId;
}

void Device::setName(string newName)
{
    this->name = newName;
}

void Device::setDescription(string newDescription)
{
    this->description = newDescription;
}
