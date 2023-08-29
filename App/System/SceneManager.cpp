#include "SceneManager.hpp"
#include "Global.hpp"

SceneManager * SceneManager::instance = new SceneManager;
std::string SceneManager::currentScene = "";


void SceneManager::loadScene(Scene* scene , sf::RenderWindow& window)
{
    sf::Clock clock;
    
    scene->onStart(window);
    while (window.isOpen())
    {
        scene->onUpdate(window, clock.restart());
        if (currentScene != scene->name)
            break;
    }
    scene ->onExit(window);
}