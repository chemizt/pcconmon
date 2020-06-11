#include <thread>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/algorithm/string.hpp>

#include "hardwareDataClasses.hpp"
#include "hardwareInfoProviderClasses.hpp"
#include "configModificationProviderClasses.hpp"

class Agent
{
    private:
        BasicOperationStateChangeProvider commander;
        ComputerSystem* thisSystem;
        ComputerSystemProvider informer;
        boost::asio::io_service service;
        boost::asio::ip::tcp::endpoint tcpEndPoint;
        boost::asio::ip::tcp::acceptor acceptor;
        boost::asio::ip::udp::endpoint udpEndPoint;
        std::map<std::string, boost::shared_ptr<boost::asio::ip::tcp::socket>> clients;
        void closeAllConnections();
        void listenTcp();
        void listenUdp();
        void processTcpSession(boost::shared_ptr<boost::asio::ip::tcp::socket> sock);
    public:
        Agent();
        Agent(uint16_t port);
        int operate();
};

void Agent::processTcpSession(boost::shared_ptr<boost::asio::ip::tcp::socket> sock)
{
    std::string fullAddress = sock->remote_endpoint().address().to_string() + ":" + std::to_string(sock->remote_endpoint().port());
    while (true)
    {
        char data[128] = {};
        std::string strData;

        try
        {
            size_t len = sock->read_some(boost::asio::buffer(data));

            if (len > 0)
            {
                strData = std::string(data);
                boost::to_upper(strData);

                if (strData == "SEND")
                {
                    json j;
                    vector<uint8_t> vMsgPack;

                    std::cout << "Received TCP SEND" << std::endl;

                    thisSystem->serialize(j);
                    vMsgPack = json::to_msgpack(j);
                    sock->write_some(boost::asio::buffer(vMsgPack));
                }
                else if (strData == "REFRESH")
                {
                    json j;
                    vector<uint8_t> vMsgPack;

                    std::cout << "Received TCP REFRESH" << std::endl;

                    informer.scanForManagedElements();
                    thisSystem->serialize(j);
                    vMsgPack = json::to_msgpack(j);
                    sock->write_some(boost::asio::buffer(vMsgPack));
                }
                else if (strData == "SHUTDOWN")
                {
                    std::cout << "Received TCP SHUTDOWN" << std::endl;

                    commander.executeShutdownCommand();
                    sock->close();
                    break;
                }
                else if (strData == "REBOOT")
                {
                    std::cout << "Received TCP REBOOT" << std::endl;

                    commander.executeRebootCommand();
                    sock->close();
                    break;
                }
            }
        }
        catch (std::exception& e)
        {
            clients.erase(fullAddress);
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

void Agent::listenTcp()
{
    while (true)
    {
        boost::shared_ptr<boost::asio::ip::tcp::socket> sock(new boost::asio::ip::tcp::socket(service));
        std::string fullAddress = "";
        std::string message = "";

        acceptor.accept(*sock);
        fullAddress += sock->remote_endpoint().address().to_string() + ":" + std::to_string(sock->remote_endpoint().port());
        clients.insert({fullAddress, sock});
        std::thread pThread(&Agent::processTcpSession, this, sock);
        pThread.detach();
    }
}

void Agent::listenUdp()
{
    boost::shared_ptr<boost::asio::ip::udp::socket> sock(new boost::asio::ip::udp::socket(service));
    boost::asio::ip::udp::endpoint remoteEndPoint(boost::asio::ip::udp::v4(), 9090);

    sock->open(boost::asio::ip::udp::v4());
    sock->set_option(boost::asio::socket_base::broadcast(true));
    sock->set_option(boost::asio::socket_base::reuse_address(true));
    sock->bind(udpEndPoint);

    while (true)
    {
        char data[128] = {};
        std::string strData;

        try
        {
            size_t len = sock->receive_from(boost::asio::buffer(data), remoteEndPoint);
            if (len > 0)
            {
                strData = std::string(data);
                boost::to_upper(strData);

                if (strData == "IDENTIFY")
                {
                    std::cout << "Received UDP IDENTIFY" << std::endl;
                    sock->send_to(boost::asio::buffer(thisSystem->getName()), remoteEndPoint);
                }
                else if (strData == "SHUTDOWN" || strData == "REBOOT")
                {
                    sock->close();
                    break;
                }
            }
        }
        catch (std::exception& e)
        {
            std::cout << "An exception occurred: " << e.what() << std::endl;
            sock->close();
            break;
        }
    }
}

Agent::Agent() : commander(), informer(), service(), tcpEndPoint(boost::asio::ip::tcp::v4(), 9090), acceptor(service, tcpEndPoint), udpEndPoint(boost::asio::ip::address_v4::from_string("0.0.0.0"), 9090)
{
    informer.scanForManagedElements();
    thisSystem = (ComputerSystem*)informer.getManagedElement();
}

Agent::Agent(uint16_t port) : commander(), informer(), service(), tcpEndPoint(boost::asio::ip::tcp::v4(), port), acceptor(service, tcpEndPoint), udpEndPoint(boost::asio::ip::address_v4::from_string("0.0.0.0"), port)
{
    informer.scanForManagedElements();
    thisSystem = (ComputerSystem*)informer.getManagedElement();
}

int Agent::operate()
{
    int opResult = 0;

    std::cout << "Running PCConMon Agent v0.2.1" << std::endl;
    std::thread udpThread(&Agent::listenUdp, this);
    udpThread.detach();
    listenTcp();

    return opResult;
}

int main()
{
    Agent pcConMonAgent;
    int result = pcConMonAgent.operate();
    
    return result;
}