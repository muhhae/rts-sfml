#include "tesScene.hpp"
#include "System/Log.hpp"

#include <iostream>

void tesScene::onUpdate(sf::RenderWindow & window, sf::Time dt)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window.close();
        
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape) window.close();
            if (event.key.code == sf::Keyboard::Space) ;
        }
    }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        latestMousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
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
    
    BlueButton.update(window);
    
    window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(BlueButton);
    window.display();
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
    
    BlueButton.setButtonColor(sf::Color::Red);
    BlueButton.setButtonSize(sf::Vector2f(200,100));
    BlueButton.setButtonPosition(sf::Vector2f(400,-400));
    BlueButton.setTextString("tesScene");
    BlueButton.setTextSize(20);
    BlueButton.setTextColor(sf::Color::White);
    BlueButton.setTextPosition(sf::Vector2f(0,0));
    BlueButton.setTextCenter();
    BlueButton.setOrigin(sf::Vector2f(100,50));
    
    BlueButton.setButtonOnUpdate([&](){
        BlueButton.setButtonColor(sf::Color::Blue);
    });
    
    BlueButton.setButtonOnHover([&](){
        BlueButton.setButtonColor(sf::Color::Green);
    });
    
    BlueButton.setButtonOnClick([&](){
        SceneManager::changeScene("Blue");
    });
}

void tesScene::onExit(sf::RenderWindow& window)
{
    std::cout << "onExit tesScene\n";
}
