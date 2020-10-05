#pragma once
#include <memory>
#include <string>
#include <fstream>

enum class LoggingLevel
{
	FATAL,
	ERROR,
	WARNING,
	INFO,
	DEBUG
};

class Logger
{
public:
	static std::shared_ptr<Logger> getInstance();
	void startLogging(std::string fileName);
	void startLogging();
	void log(LoggingLevel level, std::string message);
	void stopLogging();
	~Logger();
private:
	Logger();
	std::ofstream m_output;
	bool m_logToFile;
};
