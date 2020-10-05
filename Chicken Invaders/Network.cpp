#include "Network.h"
#include <iostream>
#include <string>

Network::Network(ConnectionType connectionType)
	:m_port(11337), m_connectionType(connectionType)
{
	initializeIp();
}

Network::~Network()
{

}

void Network::initializeIp()
{
	m_ip = sf::IpAddress::getLocalAddress();
}

void Network::listen()
{
	if (m_connectionType == ConnectionType::SERVER)
	{
		m_listener.listen(m_port);
		m_listener.accept(m_socket);
	}
	else
	{
		std::cout << "This type of connection cannot listen !" << std::endl;
	}
}

void Network::connect()
{
	if (m_connectionType == ConnectionType::CLIENT)
	{
		m_socket.connect(m_ip, m_port);
	}
	else
	{
		std::cout << "This type of connection cannot connect !" << std::endl;
	}
}

void Network::sendMessage()
{
	std::string message = "Hello";
	m_socket.send(message.c_str(), message.length() + 1);
}

void Network::receiveMessage()
{
	char buffer[200];
	std::size_t received;
	m_socket.receive(buffer, sizeof(buffer), received);
	std::cout << buffer << std::endl;
}

