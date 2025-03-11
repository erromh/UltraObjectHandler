#include "MainMenu.h"

Menu::MainMenu *Menu::MainMenu::_instance = nullptr;

Menu::MainMenu *Menu::MainMenu::getInstance()
{
    return _instance;
}

int Menu::MainMenu::safeMenuInput()
{
    int value;

    while (true)
    {
        if (std::cin >> value && value >= 1 && value <= 5)
        {
            return value;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Menu::MainMenu::startMenu()
{
    while (true)
    {
        std::cout << "Welcome to object reader\nSelect an action\n\n";

        std::cout
            << "[1] Read a list of objects from a file\n[2] Add object to list\n[3] Group current objects\n[4] Save "
               "results to file\n[5] Exit\n->";

        int option = safeMenuInput();

        switch (option)
        {
        case 1:
            system("cls");
            Controllers::MainController::getInstance()->readingObjects();
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            // add new object
            Controllers::MainController::getInstance()->addingObjectsToList();
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            // grouping objects
            Controllers::MainController::getInstance()->groupingObjects();
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            Controllers::MainController::getInstance()->saveResultsToFile();
            // save results to file
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            std::exit(0);
            break;

        default:
            std::cout << "Not such option\n";
            break;
        }
    }
}
