//
// Created by maciejl on 8/17/24.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <sqlite3.h>

#include "DatabaseConnection.h"


class Employee {


private:
    int employeeID;
    std::string name;
    std::string position;
    double hourlyRate;

public:
    Employee(){};

    Employee(int id, std::string n, std::string pos, double rate)
        : employeeID(id), name(n), position(pos), hourlyRate(rate) {}


    int getEmployeeID() const { return employeeID; }
    std::string getName() const { return name; }
    std::string getPosition() const { return position; }
    double getHourlyRate() const { return hourlyRate; }


    void setName(const std::string& n) { name = n; }
    void setPosition(const std::string& pos) { position = pos; }
    void setHourlyRate(double rate) { hourlyRate = rate; }

    // Metody do interakcji z bazą danych
    static Employee getFromDB(int employeeID, DatabaseConnection db);
    bool saveToDB(DatabaseConnection& db);
    bool updateInDB(DatabaseConnection& db);
    bool removeFromDB(DatabaseConnection& db);

};



#endif //EMPLOYEE_H
