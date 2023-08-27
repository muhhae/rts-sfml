#include "Global.hpp"

sf::Font& defaultFont()
{
    static sf::Font font;
    if (font.getInfo().family == "") font.loadFromFile("Resources/Fonts/firaFont.ttf");
    return font;
}

sf::Texture & loadTexture(const std::string & path)
{
    static std::map<std::string, sf::Texture> textures;
    if (textures.find(path) == textures.end())
    {
        textures[path] = sf::Texture();
        textures[path].loadFromFile(path);
    }
    return textures[path];
}
