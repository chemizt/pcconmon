#ifndef IG_CORE_CLASSES_SL
#define IG_CORE_CLASSES_SL

#include "commonInclude.hpp"

class ManagedElement
{
    protected:
        string _description;
        string _id;
        string _name;
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
        string _capabilities;
        string _manufacturer;
        string _model;
        string _partNumber;
        string _serialNumber;
        string _type;
        string _version;
    public:
        string getCapabilities();
        string getManufacturer();
        string getModel();
        string getPartNumber();
        string getSerialNumber();
        string getType();
        string getVersion();
        virtual void setType(string newType) = 0;
        void setCapabilities(string newCapabilities);
        void setManufacturer(string newManufacturer);
        void setModel(string newModel);
        void setPartNumber(string newPartNumber);
        void setSerialNumber(string newSerialNumber);
        void setVersion(string newVersion);
};

#endif
