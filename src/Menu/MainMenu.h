#pragma once
#include <iostream>

#include "Controller.h"

namespace Menu
{
class MainMenu
{
  private:
    MainMenu();

    MainMenu(MainMenu &obj) = delete;

    ~MainMenu();

  private:
    static MainMenu *_instance;

    int safeMenuInput();

  public:
    void operator=(const MainMenu &) = delete;

    static MainMenu *getInstance();

    void startMenu();
};
} // namespace Menu
