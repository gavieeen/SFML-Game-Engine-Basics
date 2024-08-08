#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class TextureManager
{
public:
    static TextureManager *GetInstance();
    sf::Texture *GetTexture(const std::string &name);

    void AddTexture(const std::string &name, const std::string &filename);

private:
    TextureManager();
    std::unordered_map<std::string, sf::Texture *> textures;
    static TextureManager *instance;
};

#endif