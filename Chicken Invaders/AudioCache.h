#pragma once
#include "SFML/Audio.hpp"
#include <unordered_map>
#include "Logger.h"

class AudioCache
{
public:
	AudioCache();
	~AudioCache();
	static void playSound(std::string name) noexcept;
	static void playMusic(std::string name) noexcept;
	static void stopMusic(std::string name) noexcept;
	static void pauseMusic(std::string name) noexcept;
	static void clearCache() noexcept;
	static void loadSounds(std::string fileName);
private:
	static std::unordered_map<std::string, sf::SoundBuffer*> m_buffers;
	static std::unordered_map<std::string, sf::Sound*> m_sounds;
	static std::unordered_map<std::string, sf::Music*> m_music;
	static std::shared_ptr<Logger> logger;
};

