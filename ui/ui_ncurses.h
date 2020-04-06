#pragma once

#include "ui_interface.h"
#include "window.h"

#include <utility>
#include <memory>

namespace Snake {
namespace UI {

class UINcurses : public UIInterface {
public:
    UINcurses(unsigned int width,
             unsigned int height);

    ~UINcurses() override;

    void Draw() override;
    void HandleInput() override;

private:
    std::unique_ptr<Common::Window> _window;
};

} // ns UI
} // ns Snake