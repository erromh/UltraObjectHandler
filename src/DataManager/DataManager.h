#pragma once
#include <fstream>
#include <iostream>
#include <sqlite3.h>
#include <string>
// #include <vector>
#include <list>

#include "Object.h"

class DataManager
{
  private:
    DataManager();
    DataManager(DataManager &obj) = delete;
    ~DataManager();

  private:
    static DataManager *_instance;
    std::list<Object> _objects;

  public:
    void operator=(const DataManager &) = delete;
    static DataManager *getInstance();

  public:
    void readData();
    void addObjectToList();
    void groupingObjects();
    std::list<Object> &loadDataFromFile();
};
