#pragma once

#include "System/SceneManager.hpp"

class tesScene : public Scene
{
    public:
        bool onUpdate(sf::RenderWindow& window);
        void onStart();
        void onExit();
};

