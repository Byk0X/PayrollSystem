//
// Created by maciejl on 8/17/24.
//

#include "PayrollSystem.h"


double taxRate = 0.23;
double insurance = 0.19;

double PayrollSystem::calculateGrossPay(int employeeID, const std::string &startDate, const std::string &endDate,
    DatabaseConnection &db) {

    double totalHoursWorked = 0.0;
    double hourlyRate = 0.0;

    std::string sql = "SELECT SUM(hoursWorked) FROM TimeLogs WHERE employeeID = " + std::to_string(employeeID) +
                        " AND date >= '" + startDate + "' AND date <= '" + endDate + "';";

    auto results = db.fetchResults(sql);

    if(!results.empty()) {
        totalHoursWorked = std::stod(results[0][0]);
    }

    sql = "SELECT hourlyRate FROM Employees WHERE employeeID = " + std::to_string(employeeID) + ";";
    results = db.fetchResults(sql);
    if (!results.empty()) {
        hourlyRate = std::stod(results[0][0]);
    }

    return totalHoursWorked * hourlyRate;

}

double PayrollSystem::calculateDeductions(int employeeID, double grossPay, DatabaseConnection &db) {

    double deductions = (grossPay * taxRate) + insurance;
    return deductions;
}

double PayrollSystem::calculateNetPay(int employeeID, const std::string &startDate, const std::string &endDate,
    DatabaseConnection &db) {

    double grossPay = calculateGrossPay(employeeID, startDate, endDate, db);
    double deductions = calculateDeductions(employeeID, grossPay, db);

    return grossPay - deductions;
}

void PayrollSystem::generatePayrollReport(const std::string &startDate, const std::string &endDate,
    DatabaseConnection &db) {

    std::string query = "SELECT employeeID FROM Employees;";
    auto results = db.fetchResults(query);

    for (const auto& row : results) {
        int employeeID = std::stoi(row[0]);
        double grossPay = calculateGrossPay(employeeID, startDate, endDate, db);
        double deductions = calculateDeductions(employeeID, grossPay, db);
        double netPay = grossPay - deductions;

        // Generate a report entry for the employee
        std::cout << "Employee ID: " << employeeID
                  << ", Gross Pay: " << grossPay
                  << ", Deductions: " << deductions
                  << ", Net Pay: " << netPay << std::endl;
    }


}

void PayrollSystem::generateEmployeeHoursReport(int employeeID, const std::string &startDate,
    const std::string &endDate, DatabaseConnection &db) {

    std::string query = "SELECT date, hoursWorked FROM Attendance WHERE employeeID = " + std::to_string(employeeID) +
                        " AND date >= '" + startDate + "' AND date <= '" + endDate + "';";
    auto results = db.fetchResults(query);

    std::cout << "Hours Worked Report for Employee ID: " << employeeID << std::endl;
    for (const auto& row : results) {
        std::string date = row[0];
        double hoursWorked = std::stod(row[1]);
        std::cout << "Date: " << date << ", Hours Worked: " << hoursWorked << std::endl;
    }

}
