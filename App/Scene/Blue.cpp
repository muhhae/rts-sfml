#include "Blue.hpp"
#include "System/Log.hpp"
#include "System/Global.hpp"
#include "Math/VectorOperation.hpp"

#include <iostream>

void Blue::onUpdate(sf::RenderWindow & window, sf::Time dt)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window.close();
        
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape) window.close();
            if (event.key.code == sf::Keyboard::Space);
        }
    }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        latestMousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    }
    
    sf::Vector2f moveDir = latestMousePos - shape.getPosition();
    sf::Vector2f offset = Normalize(moveDir) * speed * dt.asSeconds();
    if (Magnitude(offset) < Magnitude(moveDir))
    {
        shape.move(offset);
    }
    else
    {
        shape.setPosition(latestMousePos);
    }
    
    sf::Text text("FPS : " + std::to_string(1 / dt.asSeconds()), defaultFont(), 30);
    text.setPosition(window.getView().getSize().x / -2, window.getView().getSize().y / -2);
    
    sf::Text ms(std::to_string(dt.asSeconds()) + " s", defaultFont(), 30);
    ms.setPosition(text.getPosition());
    ms.move(0, 30);
    
    window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(text);
        window.draw(ms);
    window.display();
}

void Blue::onStart(sf::RenderWindow& window)
{
    std::cout << "onStart Blue\n";
    shape.setPosition(100,100);
    shape.setFillColor(sf::Color::Green);
    shape.setRadius(100);
    shape.setPointCount(6);
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(100,100);
    
    latestMousePos = shape.getPosition();
}

void Blue::onExit(sf::RenderWindow& window)
{
    std::cout << "onExit Blue\n";
}
