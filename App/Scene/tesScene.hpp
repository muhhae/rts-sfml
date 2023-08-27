#pragma once

#include "System/SceneManager.hpp"

class tesScene : public Scene
{
    public:
        bool onUpdate(sf::RenderWindow& window, sf::Time dt);
        void onStart(sf::RenderWindow& window);
        void onExit(sf::RenderWindow& window);
    private:
        sf::CircleShape shape;
        sf::Vector2f latestMousePos;
        
        sf::View gameView;
        
        float speed = 1000;
};

