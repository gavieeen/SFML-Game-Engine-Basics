#include "TextureManager.h"

TextureManager *TextureManager::instance = nullptr;

TextureManager *TextureManager::GetInstance()
{
    if (instance == nullptr)
        instance = new TextureManager();

    return instance;
}

void TextureManager::AddTexture(const std::string &name, const std::string &filename)
{
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(filename); // load sprite as texture object
    textures[name] = texture;
}

sf::Texture *TextureManager::GetTexture(const std::string &name)
{
    return (textures.find(name) != textures.end()) ? textures[name] : nullptr;
}

TextureManager::TextureManager() : textures()
{
    // Constructor implementation
}