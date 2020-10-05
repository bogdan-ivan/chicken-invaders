#include "Logger.h"
#include <iostream>

Logger::Logger()
{

}

Logger::~Logger()
{
	m_output.close();
}

std::shared_ptr<Logger> Logger::getInstance()
{
	static std::weak_ptr<Logger> instance;
	if (auto ptr = instance.lock())
	{
		return ptr;
	}
	std::shared_ptr<Logger> ptr(new Logger);
	instance = ptr;
	return ptr;
}

void Logger::startLogging(std::string fileName)
{
	m_output.open(fileName);
	if (m_output.good())
	{
		m_logToFile = true;
		log(LoggingLevel::INFO, fileName + " was opened");
	}
	else
	{
		log(LoggingLevel::ERROR, "error opening file");
		//throw "Can't open file !";
	}
}

void Logger::startLogging()
{
	m_logToFile = false;
}

void Logger::log(LoggingLevel level, std::string message)
{
	switch (level)
	{
	case LoggingLevel::FATAL:
	{
		std::cout << "[FATAL] : " << message << "\n";
		if(m_logToFile)
			m_output << "[FATAL] : " << message << "\n";
		break;
	}
	case LoggingLevel::ERROR:
	{
		std::cout << "[ERROR]: " << message << "\n";
		if (m_logToFile)
			m_output << "[ERROR] : " << message << "\n";
		break;
	}
	case LoggingLevel::WARNING:
	{
		std::cout << "[WARNING] : " << message << "\n";
		if (m_logToFile)
			m_output << "[WARNING] : " << message << "\n";
		break;
	}
	case LoggingLevel::INFO:
	{
		std::cout << "[INFO] : " << message << "\n";
		if (m_logToFile)
			m_output << "[INFO] : " << message << "\n";
		break;
	}
	case LoggingLevel::DEBUG:
	{
		std::cout << "[DEBUG] : " << message << "\n";
		if (m_logToFile)
			m_output << "[DEBUG] : " << message << "\n";
		break;
	}
	default:
		break;
	}
	m_output.flush();
}

void Logger::stopLogging()
{
	log(LoggingLevel::DEBUG, "Stopped logging");
	m_output.close();
}

