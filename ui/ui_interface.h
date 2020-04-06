#pragma once

#include "game.h"

#include <memory>

namespace Snake {
namespace UI {

class UIInterface {
public:
    UIInterface(std::shared_ptr<Model::Game> gameModelPtr);

    virtual void Draw() = 0;
    virtual void HandleInput() = 0;

protected:
    void HandleLeftKey();
    void HandleRightKey();
    void HandleUpKey();
    void HandleDownKey();

protected:
    std::shared_ptr<Model::Game> _gameModelPtr;
};

} // ns UI
} // ns Snake
