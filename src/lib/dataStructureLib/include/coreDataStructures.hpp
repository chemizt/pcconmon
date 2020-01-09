#ifndef CORE_DATA_STRUCTURES
#define CORE_DATA_STRUCTURES

#include "commonInclude.hpp"

class Device
{
    protected:
        int id;
        string name;
        string description;
    public:
        Device(int newId, string newName);
        Device(int newId, string newName, string newDescription);
        int getId();
        string getName();
        string getDescription();
        void setId(int newId);
        void setName(string newName);
        void setDescription(string newDescription);
};



#endif