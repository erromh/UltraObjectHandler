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
        if (std::cin >> value && value >= 1 && value <= 4)
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
        std::cout << "Welcome to object reader\nВыберите действие\n\n";

        std::cout << "[1] Прочитать список объектов из файла\n[2] Добавить объект в список\n[3] Группировка "
                     "объектов\n[4] Выход"
                     "\n->";

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
            Controllers::MainController::getInstance()->addingObjectsToList();
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            Controllers::MainController::getInstance()->groupingObjects();
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            std::exit(0);
            break;

        default:
            std::cout << "Not such option\n";
            break;
        }
    }
}
