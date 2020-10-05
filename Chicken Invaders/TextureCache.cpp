#include "TextureCache.h"
#include <fstream>
#include <execution>
#include <iostream>
#include "Timer.h"


TextureCache::TextureCache()
{
	TextureCache::logger->startLogging("Logging.txt");
}

TextureCache::~TextureCache()
{

}

sf::Texture* TextureCache::getTexture(std::string name) noexcept
{
	/*if (m_textures.contains(name))
	{
		return m_textures[name];
	}*/
	if (auto it = m_textures.find(name); it != m_textures.end())
	{
		return m_textures[name];
	}
	else
	{
		TextureCache::logger->log(LoggingLevel::ERROR, "Failed to load " + name + " texture");
		return m_textures["Missing"];
	}
}

void TextureCache::clearCache() noexcept
{
	for (auto& texture : m_textures)
	{
		delete texture.second;
	}
	m_textures.clear();
}

void TextureCache::loadTextures(std::string fileName)
{
	TextureCache::logger->log(LoggingLevel::INFO, "Loading textures...");
	std::ifstream input(fileName);
	if (!input.good())
	{
		TextureCache::logger->log(LoggingLevel::ERROR, "Error opening Texture load file");
		return;
	}
	int numberOfTextures;
	input >> numberOfTextures;
	std::string textureName;
	std::string texturePath;

	auto meshLoad = [](const std::string& path) {
		sf::Texture* t = new sf::Texture;
		t->loadFromFile(path);
		return t;
	};
	std::vector<std::string> meshFilepaths;
	std::vector<std::string> meshNames;
	std::vector<sf::Texture*> meshes;
	meshFilepaths.reserve(numberOfTextures);
	meshNames.reserve(numberOfTextures);
	meshes.resize(numberOfTextures);

	{
		Timer t;
		for (int i = 0; i < numberOfTextures; ++i)
		{
			input >> textureName;
			input >> texturePath;
			meshFilepaths.push_back(std::move(texturePath));
			meshNames.push_back(std::move(textureName));
		}
		std::transform(std::execution::par, meshFilepaths.begin(), meshFilepaths.end(), meshes.begin(), [&](auto const& file) {
			return meshLoad(file);
			});
		for (int i = 0; i < numberOfTextures; ++i)
			m_textures[meshNames[i]] = meshes[i];

		meshes.clear();
	}

	if (m_textures.size() == numberOfTextures)
		TextureCache::logger->log(LoggingLevel::DEBUG, "Textures loaded succesfully !");
	else
		TextureCache::logger->log(LoggingLevel::WARNING, "Some textures failed to load !");

}

std::unordered_map<std::string, sf::Texture*> TextureCache::m_textures;
std::shared_ptr<Logger> TextureCache::logger = Logger::getInstance();