#include "tesScene.hpp"
#include "System/Log.hpp"

#include <iostream>

bool tesScene::onUpdate(sf::RenderWindow & window, sf::Time dt)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window.close();
        
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape) window.close();
        }
    }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        latestMousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    }
    
    sf::Vector2f moveDir = latestMousePos - shape.getPosition();
    
    float distance = sqrt(moveDir.x * moveDir.x + moveDir.y * moveDir.y);
    
    // LOG("distance: " << distance);
    
    if (distance > 1)
    {
        moveDir = moveDir / sqrt(moveDir.x * moveDir.x + moveDir.y * moveDir.y);
        moveDir = moveDir * speed * dt.asSeconds();
        shape.move(moveDir);
    }
    else
    {
        shape.setPosition(latestMousePos);
    }
    
    window.clear(sf::Color::Black);
        window.draw(shape);
    window.display();
    
    return true;
}

void tesScene::onStart(sf::RenderWindow& window)
{
    std::cout << "onStart tesScene\n";
    shape.setPosition(100,100);
    shape.setFillColor(sf::Color::Green);
    shape.setRadius(100);
    shape.setPointCount(6);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(100,100);
    
    latestMousePos = shape.getPosition();
}

void tesScene::onExit(sf::RenderWindow& window)
{
    std::cout << "onExit tesScene\n";
}
