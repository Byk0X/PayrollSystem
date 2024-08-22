#include <iostream>
#include <string>

#include "DatabaseConnection.h"
#include "Employee.h"
#include "TimeLog.h"


Employee returnEmployye(DatabaseConnection &db);

void showAllEmployee(DatabaseConnection &db);

int main() {

    DatabaseConnection db;

    showAllEmployee(db);

    Employee employee = returnEmployye(db);

    return 0;
}


void showAllEmployee(DatabaseConnection &db) {

    int employeeID = 1;
    std::string sql = "SELECT * FROM Employees WHERE employeeID = " + std::to_string(employeeID) + ";";

    auto results = db.fetchResults(sql);

    for(int i=0; i < results.size(); i++) {
        std::cout << results[i][0] << " " << results[i][1] << " " << results[i][2] << " " << results[i][3] << std::endl;
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

