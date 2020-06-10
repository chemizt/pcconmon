#include <thread>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/algorithm/string.hpp>

#include "hardwareDataClasses.hpp"
#include "hardwareInfoProviderClasses.hpp"
#include "configModificationProviderClasses.hpp"

class Server
{
    private:
        boost::asio::io_service service;
        boost::asio::ip::tcp::endpoint endPoint;
        boost::asio::ip::tcp::acceptor acceptor;
        std::map<std::string, boost::shared_ptr<boost::asio::ip::tcp::socket>> clients;
        void processClientSession(boost::shared_ptr<boost::asio::ip::tcp::socket> sock);
    public:
        Server();
        Server(uint16_t port);
        void listen();
};

class Agent
{
    private:
        BasicOperationStateChangeProvider commander;
        ComputerSystemProvider informer;
        ComputerSystem* thisSystem;
        boost::asio::io_service service;
        boost::asio::ip::tcp::endpoint endPoint;
        boost::asio::ip::tcp::acceptor acceptor;
        std::map<std::string, boost::shared_ptr<boost::asio::ip::tcp::socket>> clients;
        void processClientSession(boost::shared_ptr<boost::asio::ip::tcp::socket> sock);
        void listen();
        void closeAllConnections();
    public:
        Agent();
        Agent(uint16_t port);
        int operate();
};

void Agent::processClientSession(boost::shared_ptr<boost::asio::ip::tcp::socket> sock)
{
    boost::system::error_code ec;
    std::string message;

    while (true)
    {
        char data[512] = {};
        std::string strData;

        try
        {
            size_t len = sock->read_some(boost::asio::buffer(data));

            if (len > 0)
            {
                strData = std::string(data);
                boost::to_upper(data);

                if (strData == "IDENTIFY")
                {
                    sock->write_some(boost::asio::buffer(thisSystem->getName()));
                }
                else if (strData == "REFRESH")
                {
                    json j;
                    std::stringstream ss;

                    informer.scanForManagedElements();
                    thisSystem->serialize(j);
                    ss << j;
                    sock->write_some(boost::asio::buffer(ss.str()));
                }
                else if (strData == "SHUTDOWN")
                {
                    commander.executeShutdownCommand();
                    closeAllConnections();
                    break;
                }
                else if (strData == "REBOOT")
                {
                    commander.executeRebootCommand();
                    closeAllConnections();
                    break;
                }
            }
        }
        catch (std::exception& e)
        {
            sock->close();
            break;
        }
    }
}

void Agent::closeAllConnections()
{
    for (std::pair<std::string, boost::shared_ptr<boost::asio::ip::tcp::socket>> sock : clients)
    {
        sock.second->close();
    }
}

void Agent::listen()
{
    while (true)
    {
        boost::shared_ptr<boost::asio::ip::tcp::socket> sock(new boost::asio::ip::tcp::socket(service));
        std::string fullAddress = "";
        std::string message = "";

        acceptor.accept(*sock);
        fullAddress += sock->remote_endpoint().address().to_string() + ":" + std::to_string(sock->remote_endpoint().port());
        clients.insert({fullAddress, sock});
        std::thread pThread(&Agent::processClientSession, this, sock);
        pThread.detach();
    }
}

Agent::Agent() : commander(), informer(), service(), endPoint(boost::asio::ip::tcp::v4(), 9090), acceptor(service, endPoint)
{
    informer.scanForManagedElements();
    thisSystem = (ComputerSystem*)informer.getManagedElement();
}

Agent::Agent(uint16_t port) : commander(), informer(), service(), endPoint(boost::asio::ip::tcp::v4(), port), acceptor(service, endPoint)
{
    informer.scanForManagedElements();
    thisSystem = (ComputerSystem*)informer.getManagedElement();
}

int Agent::operate()
{
    int opResult = 0;

    listen();

    return opResult;
}

int main()
{
    Agent pcConMonAgent;
    int result = pcConMonAgent.operate();
    
    return result;
}