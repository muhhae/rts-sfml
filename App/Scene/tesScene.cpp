#include "tesScene.hpp"

#include <iostream>

bool tesScene::onUpdate(sf::RenderWindow & window)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(100,100);
    
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window.close();
    }
    
    window.clear(sf::Color::Black);
    
    window.draw(shape);
    
    window.display();
    
    return true;
}

void tesScene::onStart()
{
    std::cout << "onStart tesScene\n";
}

void tesScene::onExit()
{
    std::cout << "onExit tesScene\n";
}
