#include "MainMenu.h"

int main()
{
    setlocale(LC_ALL, "rus");

    Menu::MainMenu::getInstance()->startMenu();

    return 0;
}
