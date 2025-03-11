#pragma once
#include <iostream>

#include "DataManager.h"
#include "MainMenu.h"

namespace Controllers
{
class MainController
{
  private:
    MainController();

    MainController(MainController &obj) = delete;

    ~MainController();

  private:
    static MainController *_instance;

  public:
    void operator=(const MainController &) = delete;

    static MainController *getInstance();

  public:
    void readingObjects();

    void addingObjectsToList();

    void groupingObjects();

    void saveResultsToFile();

    void goToMenu();
};
} // namespace Controllers
