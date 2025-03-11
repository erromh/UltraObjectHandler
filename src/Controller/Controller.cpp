#include "Controller.h"

Controllers::MainController *Controllers::MainController::_instance = nullptr;

Controllers::MainController *Controllers::MainController::getInstance()
{
    return _instance;
}

void Controllers::MainController::readingObjects()
{
    DataManager::getInstance()->readData();
}

void Controllers::MainController::addingObjectsToList()
{
    // DataManager::getInstance()->addObjectToList();
}

void Controllers::MainController::groupingObjects()
{
    // DataManager::getInstance()->groupingObjects();
}

void Controllers::MainController::saveResultsToFile()
{
    // DataManager::getInstance()
    std::cout << "saveResultsToFile() works\n";
}

void Controllers::MainController::goToMenu()
{
    Menu::MainMenu::getInstance()->startMenu();
}
