//
// Created by maciejl on 8/18/24.
//

#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <sqlite3.h>
#include <string>
#include <vector>


class DatabaseConnection {

private:
    sqlite3* dbConnection;


public:
    DatabaseConnection();
    ~DatabaseConnection();

    // Metody do zarządzania połączeniem
    bool connect();
    void disconnect();

    // Metody do wykonywania zapytań
    bool executeQuery(const std::string &query);
    std::vector<std::vector<std::string>> fetchResults(const std::string& query);

    // Singleton dla zarządzania połączeniem
    static DatabaseConnection& getInstance();

    sqlite3* getDB(){return this->dbConnection;};
};



#endif //DATABASECONNECTION_H
