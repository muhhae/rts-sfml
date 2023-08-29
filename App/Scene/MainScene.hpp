#pragma once

#include "System/SceneManager.hpp"

class MainScene : public Scene
{
    public:
        MainScene(std::string sceneName) : Scene(sceneName) {}
        void onUpdate(sf::RenderWindow& window, sf::Time dt);
        void onStart(sf::RenderWindow& window);
        void onExit(sf::RenderWindow& window);
    private:  
        std::vector<sf::CircleShape> shapes;
};

