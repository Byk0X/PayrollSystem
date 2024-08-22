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

    sqlite3_close(this->dbConnection);
    std::cout << "Connection closed\n";
}

bool DatabaseConnection::connect() {

    int result = sqlite3_open("payrollSystem.db", &(this->dbConnection));

    if(result) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(this->dbConnection) << std::endl;
        return false;
    }

    std::cout << "Successfuly opened database" << std::endl;

    return true;
}



auto DatabaseConnection::executeQuery(const std::string &query) -> bool {
    char* errorMessage;
    int result = sqlite3_exec(this->dbConnection, query.c_str(), nullptr, 0, &errorMessage);

    if(result != SQLITE_OK) {
        sqlite3_free(errorMessage);
        return false;
    }

    return true;
}

std::vector<std::vector<std::string>> DatabaseConnection::fetchResults(const std::string &query) const {
    std::vector<std::vector<std::string>> results;
    sqlite3_stmt* stmt = nullptr;


    // Przygotowanie zapytania SQL
    int rc = sqlite3_prepare_v2(this->dbConnection, query.c_str(), -1, &stmt, nullptr);


    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(this->dbConnection) << std::endl;
    }

    // Wykonanie zapytania i odczyt wyników
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        int columnCount = sqlite3_column_count(stmt);

        for (int i = 0; i < columnCount; i++) {
            const unsigned char *text = sqlite3_column_text(stmt, i);
            row.push_back(text ? reinterpret_cast<const char*>(text) : "");
        }

        results.push_back(row);

    }

    // Finalizowanie statementu
    if (stmt) {
        sqlite3_finalize(stmt);
    }
    return results;
}
