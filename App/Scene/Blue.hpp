#pragma once

#include "System/SceneManager.hpp"

class Blue : public Scene
{
    public:
        Blue(std::string sceneName) : Scene(sceneName) {}
        void onUpdate(sf::RenderWindow& window, sf::Time dt);
        void onStart(sf::RenderWindow& window);
        void onExit(sf::RenderWindow& window);
    private:
        sf::CircleShape shape;
        sf::Vector2f latestMousePos;
        
        sf::View gameView;
        
        float speed = 1000;
};

