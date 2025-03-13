#pragma once
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
    DataManager &manager;

  public:
    void operator=(const MainController &) = delete;
    static MainController *getInstance();

  public:
    void readingObjects();
    void addingObjectsToList();
    void groupingObjects();
    void goToMenu();
};
} // namespace Controllers
