#include <iostream>
#include <string>

#include "DatabaseConnection.h"
#include "Employee.h"
#include "TimeLog.h"

void showAllEmployee(DatabaseConnection db);

int main() {

    DatabaseConnection db;
    Employee employee;

    db.connect();



    return 0;
}


void showAllEmployee(DatabaseConnection db) {



}
