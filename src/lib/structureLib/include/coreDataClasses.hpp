#ifndef IG_CORE_CLASSES_SL
#define IG_CORE_CLASSES_SL

#include "commonInclude.hpp"

class ManagedElement
{
    protected:
        string description;
        string id;
        string name;
    public:
        ManagedElement() { };
        string getDescription();
        string getId();
        string getName();
        virtual void setDescription(string newDescription) = 0;
        void setId(string newId);
        void setName(string newName);
};

class Device : public ManagedElement
{
    protected:
        string capabilities;
        string manufacturer;
        string type;
        string version;
    public:
        using ManagedElement::ManagedElement;
        string getCapabilities();
        string getManufacturer();
        string getType();
        string getVersion();
        virtual void setType(string newType) = 0;
        void setCapabilities(string newCapabilities);
        void setManufacturer(string newManufacturer);
        void setVersion(string newVersion);
};

#endif
