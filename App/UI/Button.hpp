#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

#include "System/Global.hpp"

class Button : public sf::Drawable
{
public:
    Button(){}
    
    void setOrigin(sf::Vector2f origin) {m_button.setOrigin(origin);}
    void setButtonPosition(sf::Vector2f position) {m_button.setPosition(position); m_text.setPosition(m_text.getPosition() + position);}
    void setButtonSize(sf::Vector2f size) {m_button.setSize(size);}
    void setButtonColor(sf::Color color) {m_button.setFillColor(color);}
    void setButtonOutlineColor(sf::Color color) {m_button.setOutlineColor(color);}
    void setButtonOutlineThickness(float thickness) {m_button.setOutlineThickness(thickness);}
    void setButtonTexture(sf::Texture& texture) {m_button.setTexture(&texture);}
    
    void setFont(const sf::Font& font) {m_text.setFont(font);}
    void setTextCenter();
    void setTextString(std::string string) {m_text.setString(string);}
    void setTextSize(unsigned int size) {m_text.setCharacterSize(size);}
    void setTextColor(sf::Color color) {m_text.setFillColor(color);}
    void setTextPosition(sf::Vector2f position) {m_text.setPosition(m_button.getPosition() + position);}
    
    void setButtonOnClick(std::function<void()> functionOnClick) {m_onClick = functionOnClick;}
    void setButtonOnHover(std::function<void()> functionOnHover) {m_onHover = functionOnHover;}
    void setButtonOnUpdate(std::function<void()> functionOnUpdate) {m_onUpdate = functionOnUpdate;}
    
    void update(const sf::RenderWindow & window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::RectangleShape m_button = sf::RectangleShape(sf::Vector2f(100, 50));
    sf::Text m_text = sf::Text("Button", defaultFont(), 24);
    
    std::function<void()> m_onClick;
    std::function<void()> m_onHover;
    std::function<void()> m_onRelease;
    std::function<void()> m_onUpdate;
    
    static bool isMouseDown;
};

