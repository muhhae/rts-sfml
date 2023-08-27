#include <SFML/Graphics.hpp>

#include <iostream>

#include "UI/Button.hpp"
#include "System/SceneManager.hpp"

#include "Scene/tesScene.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    
    SceneManager sceneManager;
    sceneManager.loadScene(new tesScene() , window);

    return 0;
}