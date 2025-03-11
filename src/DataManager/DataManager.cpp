#include "DataManager.h"

DataManager *DataManager::_instance = nullptr;

DataManager *DataManager::getInstance()
{
    return _instance;
}

std::list<Object> &DataManager::loadDataFromFile()
{
    const char *_filePath = char(PROJECT_ROOT_DIR) + "/resources/data/data.db";

    std::list<Object> data;
    sqlite3 *db;
    sqlite3_stmt *stmt;

    if (sqlite3_open(_filePath, &db) != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return data;
    }

    /*const char *sql1 =
        "INSERT INTO objects(object_name, first_coordinate, second_coordinate, object_type, creation_time) VALUES"
        "('Tree', 12, 34, 'Static', strftime('%s', 'now')),"
        "('Rock', 45, 67, 'Static', strftime('%s', 'now', '+1 seconds')),"
        "('NPC', 78, 90, 'Dynamic', strftime('%s', 'now', '+2 seconds')),"
        "('Enemy', 23, 56, 'Dynamic', strftime('%s', 'now', '+3 seconds')),"
        "('Player', 89, 12, 'Interactive', strftime('%s', 'now', '+4 seconds')),"
        "('House', 34, 78, 'Static', strftime('%s', 'now', '+5 seconds')),"
        "('Car', 90, 45, 'Dynamic', strftime('%s', 'now', '+6 seconds')),"
        " ('Animal', 67, 89, 'Dynamic', strftime('%s', 'now', '+7 seconds')),"
        "('Weapon', 56, 23, 'Interactive', strftime('%s', 'now', '+8 seconds')),"
        "('Item', 78, 34, 'Interactive', strftime('%s', 'now', '+9 seconds')),"
        "('Tree', 11, 22, 'Static', strftime('%s', 'now', '+10 seconds')),"
        "('Rock', 33, 44, 'Static', strftime('%s', 'now', '+11 seconds')),"
        "('NPC', 55, 66, 'Dynamic', strftime('%s', 'now', '+12 seconds')),"
        "('Enemy', 77, 88, 'Dynamic', strftime('%s', 'now', '+13 seconds')),"
        "('Player', 99, 11, 'Interactive', strftime('%s', 'now', '+14 seconds')),"
        "('House', 22, 33, 'Static', strftime('%s', 'now', '+15 seconds')),"
        "('Car', 44, 55, 'Dynamic', strftime('%s', 'now', '+16 seconds')),"
        "('Animal', 66, 77, 'Dynamic', strftime('%s', 'now', '+17 seconds')),"
        "('Weapon', 88, 99, 'Interactive', strftime('%s', 'now', '+18 seconds')),"
        "('Item', 11, 22, 'Interactive', strftime('%s', 'now', '+19 seconds')),"
        "('Tree', 13, 24, 'Static', strftime('%s', 'now', '+20 seconds')),"
        " ('Rock', 35, 46, 'Static', strftime('%s', 'now', '+21 seconds')),"
        "('NPC', 57, 68, 'Dynamic', strftime('%s', 'now', '+22 seconds')),"
        "('Enemy', 79, 80, 'Dynamic', strftime('%s', 'now', '+23 seconds')),"
        "('Player', 21, 32, 'Interactive', strftime('%s', 'now', '+24 seconds')),"
        "('House', 43, 54, 'Static', strftime('%s', 'now', '+25 seconds')),"
        "('Car', 65, 76, 'Dynamic', strftime('%s', 'now', '+26 seconds')),"
        "('Animal', 87, 98, 'Dynamic', strftime('%s', 'now', '+27 seconds')),"
        "('Weapon', 19, 20, 'Interactive', strftime('%s', 'now', '+28 seconds')),"
        "('Item', 31, 42, 'Interactive', strftime('%s', 'now', '+29 seconds')),"
        "('Tree', 14, 25, 'Static', strftime('%s', 'now', '+30 seconds')),"
        "('Rock', 36, 47, 'Static', strftime('%s', 'now', '+31 seconds')),"
        "('NPC', 58, 69, 'Dynamic', strftime('%s', 'now', '+32 seconds')),"
        "('Enemy', 70, 81, 'Dynamic', strftime('%s', 'now', '+33 seconds')),"
        "('Player', 22, 33, 'Interactive', strftime('%s', 'now', '+34 seconds')),"
        "('House', 44, 55, 'Static', strftime('%s', 'now', '+35 seconds')),"
        "('Car', 66, 77, 'Dynamic', strftime('%s', 'now', '+36 seconds')),"
        "('Animal', 88, 99, 'Dynamic', strftime('%s', 'now', '+37 seconds')),"
        "('Weapon', 20, 21, 'Interactive', strftime('%s', 'now', '+38 seconds')),"
        "('Item', 32, 43, 'Interactive', strftime('%s', 'now', '+39 seconds')),"
        "('Tree', 15, 26, 'Static', strftime('%s', 'now', '+40 seconds')),"
        "('Rock', 37, 48, 'Static', strftime('%s', 'now', '+41 seconds')),"
        "('NPC', 59, 70, 'Dynamic', strftime('%s', 'now', '+42 seconds')),"
        "('Enemy', 71, 82, 'Dynamic', strftime('%s', 'now', '+43 seconds')),"
        "('Player', 23, 34, 'Interactive', strftime('%s', 'now', '+44 seconds')),"
        "('House', 45, 56, 'Static', strftime('%s', 'now', '+45 seconds')),"
        "('Car', 67, 78, 'Dynamic', strftime('%s', 'now', '+46 seconds')),"
        "('Animal', 89, 90, 'Dynamic', strftime('%s', 'now', '+47 seconds')),"
        "('Weapon', 21, 22, 'Interactive', strftime('%s', 'now', '+48 seconds')),"
        "('Item', 33, 44, 'Interactive', strftime('%s', 'now', '+49 seconds'));";*/

    const char *sql =
        "CREATE TABLE IF NOT EXISTS objects (id INTEGER PRIMARY KEY AUTOINCREMENT, object_name TEXT NOT "
        "NULL, first_coordinate INTEGER NOT NULL, second_coordinate INTEGER NOT NULL,"
        " object_type TEXT NOT NULL, creation_time REAL NOT NULL);"
        "SELECT object_name, first_coordinate, second_coordinate, object_type, creation_time FROM objects;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return data;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Object obj;
        obj.objectName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        obj.firstCoordinate = sqlite3_column_int(stmt, 1);
        obj.secondCoordinate = sqlite3_column_int(stmt, 2);
        obj.objectType = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
        obj.creationTime = sqlite3_column_double(stmt, 4);
        data.push_back(obj);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return data;
}

void DataManager::readData()
{
    _objects = loadDataFromFile();

    for (const auto &obj : _objects)
    {
        std::cout << "Name: " << obj.objectName << ", Coordinates: (" << obj.firstCoordinate << ", "
                  << obj.secondCoordinate << ")"
                  << ", Type: " << obj.objectType << ", Created: " << obj.creationTime << std::endl;
    }

    /*for (int i = 0; i < _objects.size(); i++)
    {
        std::cout << _objects[i].objectName << " " << _objects[i].firstCoordinate << " " << _objects[i].secondCoordinate
                  << " " << _objects[i].objectType << " " << _objects[i].creationTime << "\n";
    }*/

    /*for (const auto &entry : _objects)
    {
        std::cout << entry.objectname << " " << entry.firstcoordinate << " " << entry.secondcoordinate << " "
                  << entry.objecttype << " " << entry.creationtime << "\n";
    }*/
}
