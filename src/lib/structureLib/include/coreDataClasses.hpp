#ifndef IG_CORE_CLASSES_SL
#define IG_CORE_CLASSES_SL

#include "commonInclude.hpp"

class ManagedElement
{
    protected:
        string id;
        string name;
        string description;
    public:
        ManagedElement() { };
        string getId();
        string getName();
        string getDescription();
        void setId(string newId);
        void setName(string newName);
        virtual void setDescription(string newDescription) = 0;
};

class Device : public ManagedElement
{
    protected:
        string type;
        string manufacturer;
        string version;
        string capabilities;
    public:
        using ManagedElement::ManagedElement;
        string getType();
        string getManufacturer();
        string getVersion();
        string getCapabilities();
        virtual void setType(string newType) = 0;
        void setManufacturer(string newManufacturer);
        void setVersion(string newVersion);
        void setCapabilities(string newCapabilities);
};

#endif
