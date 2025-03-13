#pragma once
#include <chrono>
#include <iostream>

struct Object
{
    std::string _objectName;
    float _firstCoordinate;
    float _secondCoordinate;
    std::string _objectType;
    double _creationTime;

    friend std::ostream &operator<<(std::ostream &os, const Object &obj);
    friend std::istream &operator>>(std::istream &is, Object &obj);
    static double getCurrentTime();
    static float getValidFloat(const std::string &prompt);
    static std::string getValidString(const std::string &prompt);
    void inputObjectData();
};
