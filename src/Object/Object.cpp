#include "Object.h"

std::ostream &operator<<(std::ostream &os, const Object &obj)
{
    return os << "{" << obj._objectName << ", " << obj._firstCoordinate << ", " << obj._secondCoordinate << ", "
              << obj._objectType << ", " << obj._creationTime << "}\n";
}

std::istream &operator>>(std::istream &is, Object &obj)
{
    return is >> obj._objectName >> obj._firstCoordinate >> obj._secondCoordinate >> obj._objectType >>
           obj._creationTime;
}

double Object::getCurrentTime()
{
    return std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count();
}

float Object::getValidFloat(const std::string &prompt)
{
    float value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите число.\n";
        }
        else
        {
            return value;
        }
    }
}

std::string Object::getValidString(const std::string &prompt)
{
    std::string value;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin >> std::ws, value);
        if (!value.empty())
        {
            return value;
        }
        std::cout << "Ошибка: введите непустое значение.\n";
    }
}

void Object::inputObjectData()
{
    _objectName = getValidString("Enter object name: ");
    _firstCoordinate = getValidFloat("Enter first coordinate: ");
    _secondCoordinate = getValidFloat("Enter second coordinate: ");
    _objectType = getValidString("Enter object type: ");
}
