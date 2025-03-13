#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "Object.h"

class DataManager
{
  private:
    static std::unique_ptr<DataManager> _instance;
    std::vector<Object> _objects;
    std::string _filePath = std::string(PROJECT_ROOT_DIR) + "/resources/data/data.txt";
    Object obj;

  private:
    int safeInput();

  public:
    DataManager();
    ~DataManager();

  public:
    void operator=(const DataManager &) = delete;
    static DataManager &getInstance();

  public:
    void printData();
    void addObjectToList();
    void groupingObjects();

    std::unordered_map<std::string, std::vector<Object>> groupByType(const std::vector<Object> &objects);
    std::map<int, std::vector<Object>> groupByYear(const std::vector<Object> &objects);
    void sortByName(std::vector<Object> &objects);
    void sortByCoordinate(std::vector<Object> &objects);

    void printGroupedByType(const std::unordered_map<std::string, std::vector<Object>> &grouped);
    void printGroupedByYear(const std::map<int, std::vector<Object>> &grouped);
};
