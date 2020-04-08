#include "game.h"
#include "game_controller.hpp"
#include "menu_window.h"
#include "ncurses_game_view.h"
#include "notifyer.h"
#include "size_getter_window.h"
#include "utils.h"

using namespace Snake;

using Position = std::pair<int, int>;

int main() {
    UI::Initialize();

    UI::Notifyer notifyer;
    UI::MenuWindow menuWindow;
    UI::SizeGetterWindow sizeGetterWindow;
    Controller::GameController<UI::NcursesView> gameController;

    UI::StatusType currentStatus;
    while (true) {
        menuWindow.Show();
        currentStatus = menuWindow.GetUserInput();
        menuWindow.Hide();
        UI::Clear();

        int width;
        int height;
        switch (currentStatus) {
            case UI::StatusType::START:
                sizeGetterWindow.Show();
                width = sizeGetterWindow.GetTableWidth();
                height = sizeGetterWindow.GetTableHeight();
                if (2 > width || 2 > height) {
                    notifyer.Notify("Table too small", 2);
                    sizeGetterWindow.Hide();
                    UI::Clear();
                    continue;
                }
                if (COLS < width || LINES < height + static_cast<int>(UI::NcursesView::SCORE_WINDOW_HEIGHT)) {
                    notifyer.Notify("Table too large", 2);
                    sizeGetterWindow.Hide();
                    UI::Clear();
                    continue;
                }
                sizeGetterWindow.Hide();
                UI::Clear();
                gameController.StartGame(width, height);
                notifyer.Notify("Game Over!", 2);
                UI::Clear();
                break;
            case UI::StatusType::SCORES:
                notifyer.Notify("In progress...", 2);
                break;
            case UI::StatusType::EXIT:
                UI::Terminate();
                return 0;
        }
    }

    return -1;











//    std::shared_ptr<Snake::Model::Game> gameModel = std::make_shared<Snake::Model::Game>();
//    gameModel->Initialize(40, 40);
//
//    Snake::UI::UINcurses ui(gameModel, 0, 0);
//
//    while (!gameModel->IsGameOver()) {
//        ui.HandleInput();
//        ui.Draw();
//        gameModel->StepGame();
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }

    //Snake::UI::MainWindow mainWindow;
    //mainWindow.StartMenuLoop();

//    Snake::UI::MenuWindow menuWindow(std::make_pair<int, int>(0, 0), 35, 15);
//    menuWindow.Show();
//    if (menuWindow.GetUserInput() == Snake::UI::StatusType::EXIT) {
//        Snake::UI::Utils::Terminate();
//        return -1;
//    }


    return 0;
}
