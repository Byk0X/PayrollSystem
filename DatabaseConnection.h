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
    sqlite3* dbConnection = nullptr;


public:
    DatabaseConnection();
    ~DatabaseConnection();

    // Metody do zarządzania połączeniem
    bool connect();

    // Metody do wykonywania zapytań
    bool executeQuery(const std::string &query);
    std::vector<std::vector<std::string>> fetchResults(const std::string& query) const;

    sqlite3* getDB() const {return this->dbConnection;};


};



#endif //DATABASECONNECTION_H
