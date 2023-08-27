#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

sf::Font& defaultFont();
sf::Texture& loadTexture(const std::string& path);