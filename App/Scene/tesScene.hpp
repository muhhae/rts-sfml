#pragma once

#include "System/SceneManager.hpp"
#include "UI/Button.hpp"

class tesScene : public Scene
{
    public:
        tesScene(std::string sceneName) : Scene(sceneName) {}
        void onUpdate(sf::RenderWindow& window, sf::Time dt);
        void onStart(sf::RenderWindow& window);
        void onExit(sf::RenderWindow& window);
    private:
        sf::CircleShape shape;
        sf::Vector2f latestMousePos;
        
        sf::View gameView;
        
        float speed = 1000;
        
        std::vector<sf::CircleShape> shapes;
        
        Button tesSceneButton;
        Button BlueButton;
        Button MainButton;
};

