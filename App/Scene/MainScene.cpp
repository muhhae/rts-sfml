#include "MainScene.hpp"
#include <iostream>
#include "System/Global.hpp"


void MainScene::onUpdate(sf::RenderWindow & window, sf::Time dt)
{
    static int fpsCounter = 0;
    static float fpsTimer = 1;
    
    fpsTimer -= dt.asSeconds();
    fpsCounter++;
    
    static sf::Text text("FPS : ", defaultFont(), 30);
    text.setPosition(window.getView().getSize().x / -2, window.getView().getSize().y / -2);
    
    if (fpsTimer <= 0)
    {
        text.setString("FPS : " + std::to_string(fpsCounter));
        fpsCounter = 0;
        fpsTimer = 1;
    }
     
    sf::Event event;
    while(window.pollEvent(event))
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
        sf::CircleShape shape;
        shape.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
        shape.setRadius(10);
        shape.setFillColor(sf::Color::Red);
        shapes.push_back(shape);
    }
    
    for (auto & shape : shapes)
    {
        shape.move(0, 100 * dt.asSeconds());
    }
    
    sf::Text ms(std::to_string(dt.asSeconds()) + " s", defaultFont(), 30);
    ms.setPosition(text.getPosition());
    ms.move(0, 30);
    
    window.clear(sf::Color::Black);
    for (auto& shape : shapes)
    {
        window.draw(shape);
    }
    window.draw(text);
    window.draw(ms);
    window.display();
}

void MainScene::onStart(sf::RenderWindow & window)
{
    std::cout << "onStart MainScene\n";
}

void MainScene::onExit(sf::RenderWindow & window)
{
    std::cout << "onExit MainScene\n";
    shapes.clear();
}
