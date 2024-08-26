//
// Created by maciejl on 8/18/24.
//

#include "TimeLog.h"

bool TimeLog::saveToDB(DatabaseConnection &db) {

    std::string sql = "INSERT INTO TimeLogs (employeeID, date, hoursWorkde) VALUES "
                        "('" + std::to_string(this->employeeID) + "', '" + this->date + "', " + std::to_string(this->hoursWorked) + ");";

    try {
        db.executeQuery(sql);
    } catch (...) {
        return false;
    }
    return true;

}

double TimeLog::getTotalHoursFromDB(int employeeID, const std::string &startDate, const std::string &endDate, DatabaseConnection &db) {

    //SELECT sum(hoursWorked) FROM TimeLogs WHERE employeeID = 1 AND date BETWEEN "2024-08-16" and "2024-08-20"

    std::string sql = "SELECT sum(hoursWorked) FROM TimeLogs WHERE employeeID = " +
        std::to_string(employeeID) + "AND date BETWEEN " + startDate + " AND " + endDate + ";";

    try {
        auto results = db.fetchResults(sql);

        return std::stod(results[0][0]);
    } catch (...) {
        throw;
    }
}
