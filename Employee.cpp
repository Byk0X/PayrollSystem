//
// Created by maciejl on 8/17/24.
//

#include <string>
#include <iostream>

#include "Employee.h"
#include "DatabaseConnection.h"


void Employee::showEmployeeInfo() {

    std::cout << "ID: " << this->name << "\n" <<
        "Name: " << this->position << "\n" <<
            "Position " << this->position << "\n" <<
                "Hourly rate: " << this->hourlyRate << std::endl;

}

bool Employee::saveToDB(DatabaseConnection& db) {

    std::string sql = "INSERT INTO Employees (name, position, hourlyRate) VALUES "
                      "('" + this->name + "', '" + this->position + "', " + std::to_string(this->hourlyRate) + ");";

    try {
        db.executeQuery(sql);
    } catch (...) {
        return false;
    }
    return true;
}

bool Employee::updateInDB(DatabaseConnection& db) const {


    char confirm;
    bool first = true;

    bool newNameC = true;
    bool newPositionC = true;
    bool newHourlyRateC = true;

    std::string newName;
    std::string newPosistion;
    double newHourlyRate;

    std::cout << "Would you like to update employee's name? [Y/N]" << std::endl;
    std::cin >> confirm;

    if(confirm == 'Y') {
        std::cout << "Enter new name: ";
        std::cin >> newName;
    }
    else {
        newNameC = false;
    }

    std::cout << "Would you like to update employee's position? [Y/N]" << std::endl;
    std::cin >> confirm;

    if(confirm == 'Y') {
        std::cout << "Enter new position: ";
        std::cin >> newPosistion;
    }
    else {
        newPositionC = false;
    }

    std::cout << "Would you like to update employee's hourly rate? [Y/N]" << std::endl;
    std::cin >> confirm;

    if(confirm == 'Y') {
        std::cout << "Enter new hourly rate: ";
        std::cin >> newHourlyRate;
    }
    else {
        newHourlyRateC = false;
    }

    std::string sql = "UPDATE Employees SET ";

    if(newNameC) {
        sql += "name = '" + newName + "'";
        first = false;
    }

    if(newPositionC) {
        if(!first) sql += ", ";
        sql += "position = '" + newPosistion + "'";
        first = false;
    }

    if(newHourlyRateC) {

        if(!first) sql += ", ";
        sql += "hourlyRate = " + std::to_string(newHourlyRate);
    }

    sql += " WHERE employeeID = " + std::to_string(this->getEmployeeID()) + ";";

    try {
        db.executeQuery(sql);
        return true;
    } catch (...) {
        return false;
    }

}

bool Employee::removeFromDB(DatabaseConnection& db) {

    std::string sql = "DELETE FROM PayrollRecords WHERE employeeID = " + std::to_string(this->getEmployeeID()) + ";" ;
    db.executeQuery(sql);

    sql = "DELETE FROM TimeLogs WHERE employeeID = " + std::to_string(this->getEmployeeID()) + ";" ;
    db.executeQuery(sql);

    sql = "DELETE FROM Employees WHERE employeeID = " + std::to_string(this->getEmployeeID()) + ";" ;
    db.executeQuery(sql);
}
