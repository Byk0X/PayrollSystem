#include <iostream>
#include <string>
#include <ctime>

#include "DatabaseConnection.h"
#include "Employee.h"
#include <iomanip>
#include "TimeLog.h"


Employee returnEmployye(DatabaseConnection &db);

void showAllEmployee(DatabaseConnection &db);

std::string returnTodaysDate();

int main() {

    DatabaseConnection db;


    showAllEmployee(db);

    Employee employee = returnEmployye(db);

    //TimeLog time_log(employee.getEmployeeID(), )
    std::string date = returnTodaysDate();
    return 0;
}


std::string returnTodaysDate() {

    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    std::string date = std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday);

    return date;

}

void showAllEmployee(DatabaseConnection &db) {

    std::string sql = "SELECT * FROM Employees;";

    auto results = db.fetchResults(sql);

    std::cout << std::left << std::setw(6) << "ID" << "  "
             << std::left << std::setw(30) << "Imię i nazwisko" << "  "
             << std::left << std::setw(20) << "Pozycja" << "  "
             << std::right << std::setw(8) << "Stawka" << std::endl;
    std::cout << std::string(74, '-') << std::endl;

    for(int i=0; i < results.size(); i++) {
        std::cout << std::left << std::setw(6) << results[i][0] << "  "      // ID
              << std::left << std::setw(30) << results[i][1] << "  "     // Imię i nazwisko
              << std::left << std::setw(20) << results[i][2] << "  "    // Pozycja
              << std::right << std::setw(8) << results[i][3] << std::endl; // Stawka
        std::cout << std::string(74, '-') << std::endl;
    }



}


Employee returnEmployye(DatabaseConnection &db) {

    int ID;

    std::cout << "Choose destinated employee: ";
    std::cin >> ID;
    std::string sql = "SELECT * FROM Employees WHERE employeeID =" + std::to_string(ID) + ";";

    auto result = db.fetchResults(sql);

    if(!result.empty()) {
        return {std::stoi(result[0][0]), result[0][1], result[0][2], std::stod(result[0][3])};
    }

    return Employee();


}

