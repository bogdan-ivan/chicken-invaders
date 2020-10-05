#pragma once
#include <SFML/Network.hpp>

enum class ConnectionType
{
	SERVER,
	CLIENT
};

class Network
{
public:
	Network(ConnectionType connectionType);
	~Network();
private:
	void initializeIp();
	void listen();
	void connect();
	void sendMessage();
	void receiveMessage();
private:
	uint16_t m_port;
	sf::IpAddress m_ip;
	sf::TcpSocket m_socket;
	sf::TcpListener m_listener;
	ConnectionType m_connectionType;
	char m_mode;
};

