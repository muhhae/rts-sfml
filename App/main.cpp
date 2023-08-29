#include <SFML/Graphics.hpp>

#include <iostream>

#include "UI/Button.hpp"
#include "System/SceneManager.hpp"

#include "Scene/tesScene.hpp"
#include "Scene/Blue.hpp"
#include "Scene/MainScene.hpp"

#include <memory>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
    sf::View view = window.getDefaultView();
    view.setCenter(sf::Vector2f(0,0));
    window.setView(view);
    
    std::vector<Scene*> scenes;
    
    scenes.push_back(new tesScene("tesScene"));
    scenes.push_back(new Blue("Blue"));
    scenes.push_back(new MainScene("MainScene"));
    
    SceneManager::changeScene("tesScene");
    
    while (window.isOpen())
    {
        auto it = std::find_if(scenes.begin(), scenes.end(), [&](Scene* scene){
            return scene->name == SceneManager::currentScene;
        });
        if (it != scenes.end())
            SceneManager::loadScene(*it, window);
    }
    
    for (auto& scene : scenes)
    {
        delete scene;
    }
    
    return 0;
}