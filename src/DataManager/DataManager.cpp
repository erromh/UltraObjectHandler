#include "DataManager.h"

std::unique_ptr<DataManager> DataManager::_instance = nullptr;

DataManager &DataManager::getInstance()
{
    if (!_instance)
    {
        _instance = std::make_unique<DataManager>();
    }
    return *_instance;
}

DataManager::DataManager()
{
}

DataManager::~DataManager()
{
}

void DataManager::printData()
{
    std::ifstream file(_filePath);

    if (file.is_open())
    {
        while (file >> obj._objectName >> obj._firstCoordinate >> obj._secondCoordinate >> obj._objectType >>
               obj._creationTime)
        {
            std::cout << obj;
        }
    }
    file.close();
}

void DataManager::addObjectToList()
{
    std::ofstream file(_filePath, std::ios::app);

    if (file.is_open())
    {
        obj.inputObjectData();

        file << obj._objectName << " " << obj._firstCoordinate << " " << obj._secondCoordinate << " " << obj._objectType
             << " " << obj.getCurrentTime();
    }

    file.close();
}

int DataManager::safeInput()
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

void DataManager::groupingObjects()
{
    std::ifstream file(_filePath);
    std::vector<Object> objects;

    if (file.is_open())
    {
        while (file >> obj._objectName >> obj._firstCoordinate >> obj._secondCoordinate >> obj._objectType >>
               obj._creationTime)
        {
            objects.push_back(obj);
        }
    }

    std::cout << "Выберите действие:\n"
              << "1 - Группировка по типу\n"
              << "2 - Группировка по году\n"
              << "3 - Сортировка по имени\n"
              << "4 - Сортировка по координате\n"
              << "Ваш выбор: ";

    int option = safeInput();

    switch (option)
    {
    case 1: {
        auto groupedByType = groupByType(objects);
        std::cout << "Группировка по типу выполнена.\n";
        printGroupedByType(groupedByType);
        break;
    }
    case 2: {
        auto groupedByYear = groupByYear(objects);
        std::cout << "Группировка по году выполнена.\n";
        printGroupedByYear(groupedByYear);
        break;
    }
    case 3: {
        sortByName(objects);
        std::cout << "Сортировка по имени выполнена.\n";
        std::cout << "Первый объект по имени: " << objects.front()._objectName << '\n';
        break;
    }
    case 4: {
        sortByCoordinate(objects);
        std::cout << "Сортировка по координате выполнена.\n";
        std::cout << "Первый объект по координате: " << objects.front()._firstCoordinate << '\n';
        break;
    }
    default:
        std::cout << "Неверный ввод\n";
        break;
    }
}

std::unordered_map<std::string, std::vector<Object>> DataManager::groupByType(const std::vector<Object> &objects)
{
    std::unordered_map<std::string, std::vector<Object>> grouped;

    for (const auto &obj : objects)
    {
        grouped[obj._objectType].push_back(obj);
    }

    return grouped;
}

std::map<int, std::vector<Object>> DataManager::groupByYear(const std::vector<Object> &objects)
{
    std::map<int, std::vector<Object>> grouped;

    for (const auto &obj : objects)
    {
        time_t t = static_cast<time_t>(obj._creationTime);
        tm *timeInfo = std::localtime(&t);
        int year = 1900 + timeInfo->tm_year;
        grouped[year].push_back(obj);
    }

    return grouped;
}

void DataManager::sortByName(std::vector<Object> &objects)
{
    std::sort(objects.begin(), objects.end(),
              [](const Object &a, const Object &b) { return a._objectName < b._objectName; });
}

void DataManager::sortByCoordinate(std::vector<Object> &objects)
{
    std::sort(objects.begin(), objects.end(),
              [](const Object &a, const Object &b) { return a._firstCoordinate < b._firstCoordinate; });
}

void DataManager::printGroupedByType(const std::unordered_map<std::string, std::vector<Object>> &grouped)
{
    for (const auto &[type, objects] : grouped)
    {
        std::cout << "\nТип: " << type << " (количество: " << objects.size() << ")\n";

        for (const auto &obj : objects)
        {
            std::cout << "  " << obj._objectName << " (" << obj._firstCoordinate << ", " << obj._secondCoordinate
                      << ") " << obj._creationTime << std::endl;
        }
    }
}

void DataManager::printGroupedByYear(const std::map<int, std::vector<Object>> &grouped)
{
    for (const auto &[year, objects] : grouped)
    {
        std::cout << "\nГод: " << year << " (количество: " << objects.size() << ")\n";

        for (const auto &obj : objects)
        {
            std::cout << "  " << obj._objectName << " (" << obj._firstCoordinate << ", " << obj._secondCoordinate
                      << ") " << obj._creationTime << '\n';
        }
    }
}
