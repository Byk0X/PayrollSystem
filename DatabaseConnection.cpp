//
// Created by maciejl on 8/18/24.
//

#include "DatabaseConnection.h"

#include <iostream>


DatabaseConnection::DatabaseConnection() {

    if(!this->connect()) {
        exit( 404);
    }
}

DatabaseConnection::~DatabaseConnection() {
    this->disconnect();

}

bool DatabaseConnection::connect() {

    int result = sqlite3_open("payrollSystem.db", &(this->dbConnection));

    if(result) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(this->dbConnection) << std::endl;
    }
    else {
        std::cout << "Successfuly opened database" << std::endl;
    }
}

void DatabaseConnection::disconnect() {

    if(this->dbConnection) {
        sqlite3_close(this->dbConnection);
    }

}

auto DatabaseConnection::executeQuery(const std::string &query) -> bool {
    char* errorMessage;
    int result = sqlite3_exec(this->dbConnection, query.c_str(), NULL, 0, &errorMessage);

    if(result != SQLITE_OK) {
        sqlite3_free(errorMessage);
        return false;
    }
}

std::vector<std::vector<std::string>> DatabaseConnection::fetchResults(const std::string &query) {

    std::vector<std::vector<std::string>> results;
    sqlite3_stmt* stmt;

    while(sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        int columnCount = sqlite3_column_count(stmt);

        for(int i=0; i < columnCount; i++) {
            const unsigned char *text = sqlite3_column_text(stmt, i);
            row.push_back(text ? std::string(reinterpret_cast<const char*>(text)) : "");
        }

        results.push_back(row);
    }
    sqlite3_finalize(stmt);
    return results;
}

DatabaseConnection & DatabaseConnection::getInstance() {
}
