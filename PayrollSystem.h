//
// Created by maciejl on 8/17/24.
//

#ifndef PAYROLLSYSTEM_H
#define PAYROLLSYSTEM_H

#include <iostream>
#include <string>

#include "Employee.h"
#include "DatabaseConnection.h"

class PayrollSystem {

public:
    // Obliczenia wynagrodzeń
    static double calculateGrossPay(int employeeID, const std::string& startDate, const std::string& endDate, DatabaseConnection db);
    static double calculateDeductions(int employeeID, double grossPay, DatabaseConnection db);
    static double calculateNetPay(int employeeID, const std::string& startDate, const std::string& endDate, DatabaseConnection db);

    // Raportowanie
    static void generatePayrollReport(const std::string& startDate, const std::string& endDate, DatabaseConnection db);
    static void generateEmployeeHoursReport(int employeeID, const std::string& startDate, const std::string& endDate, DatabaseConnection db);

};



#endif //PAYROLLSYSTEM_H
