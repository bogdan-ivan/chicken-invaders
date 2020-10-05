#include "AudioCache.h"

AudioCache::AudioCache()
{
	AudioCache::logger->startLogging("Logging.txt");
}

AudioCache::~AudioCache()
{

}

void AudioCache::playSound(std::string name) noexcept
{
	if (auto it = m_sounds.find(name); it != m_sounds.end())
	{
		m_sounds[name]->play();
	}
	else
	{
		AudioCache::logger->log(LoggingLevel::ERROR, "Failed to load " + name + " sound");
		return;
	}
}

void AudioCache::playMusic(std::string name) noexcept
{
	if (auto it = m_music.find(name); it != m_music.end())
	{
		m_music[name]->setVolume(50);
		m_music[name]->play();
	}
	else
	{
		AudioCache::logger->log(LoggingLevel::ERROR, "Failed to play " + name + " music");
		return;
	}
}

void AudioCache::stopMusic(std::string name) noexcept
{
	if (auto it = m_music.find(name); it != m_music.end())
	{
		m_music[name]->stop();
	}
	else
	{
		AudioCache::logger->log(LoggingLevel::ERROR, "Failed to stop " + name + " music");
		return;
	}
}

void AudioCache::pauseMusic(std::string name) noexcept
{
	if (auto it = m_music.find(name); it != m_music.end())
	{
		m_music[name]->pause();
	}
	else
	{
		AudioCache::logger->log(LoggingLevel::ERROR, "Failed to stop " + name + " music");
		return;
	}
}

void AudioCache::clearCache() noexcept
{
	for (auto& buffer : m_buffers)
	{
		delete buffer.second;
	}
	for (auto& sound : m_sounds)
	{
		delete sound.second;
	}
	m_buffers.clear();
	m_sounds.clear();
}

void AudioCache::loadSounds(std::string fileName)
{
	AudioCache::logger->log(LoggingLevel::INFO, "Loading sounds...");
	std::ifstream input(fileName);
	if (!input.good())
	{
		AudioCache::logger->log(LoggingLevel::ERROR, "Error opening Audio load file");
		return;
	}
	int numberOfSounds;
	int numberOfMusic;
	input >> numberOfSounds;
	input >> numberOfMusic;
	std::string soundName;
	std::string soundPath;

	for (int i = 0; i < numberOfSounds; ++i)
	{
		input >> soundName;
		input >> soundPath;
		sf::SoundBuffer* t = new sf::SoundBuffer;
		t->loadFromFile(soundPath);
		m_buffers[soundName] = t;
	}

	for (auto& buffer : m_buffers)
	{
		sf::Sound* t = new sf::Sound;
		t->setBuffer(*buffer.second);
		m_sounds[buffer.first] = t;
	}

	for (int i = 0; i < numberOfMusic; ++i)
	{
		input >> soundName;
		input >> soundPath;
		sf::Music* t = new sf::Music;
		t->openFromFile(soundPath);
		m_music[soundName] = t;
	}

	if (m_buffers.size() == numberOfSounds)
		AudioCache::logger->log(LoggingLevel::DEBUG, "Buffers loaded succesfully !");
	else
		AudioCache::logger->log(LoggingLevel::WARNING, "Some buffers failed to load !");
	if (m_sounds.size() == numberOfSounds)
		AudioCache::logger->log(LoggingLevel::DEBUG, "Sounds loaded succesfully !");
	else
		AudioCache::logger->log(LoggingLevel::WARNING, "Some sounds failed to load !");
}

std::unordered_map<std::string, sf::SoundBuffer*> AudioCache::m_buffers;
std::unordered_map<std::string, sf::Sound*> AudioCache::m_sounds;
std::unordered_map<std::string, sf::Music*> AudioCache::m_music;
std::shared_ptr<Logger> AudioCache::logger = Logger::getInstance();