#pragma once
#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "Logger.h"

class TextureCache
{
public:
	TextureCache();
	~TextureCache();
	static sf::Texture* getTexture(std::string name) noexcept;
	static void clearCache() noexcept;
	static void loadTextures(std::string fileName);
private:
	static std::unordered_map<std::string, sf::Texture*> m_textures;
	static std::shared_ptr<Logger> logger;
};




