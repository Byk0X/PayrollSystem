//
// Created by maciejl on 8/18/24.
//

#include "TimeLog.h"

bool TimeLog::saveToDB(DatabaseConnection db) {

    std::string sql = "INSERT INTO TimeLogs (employeeID, date, hoursWorkde) VALUES "
                        "('" + std::to_string(this->employeeID) + "', '" + this->date + "', " + std::to_string(this->hoursWorked) + ");";

    try {
        db.executeQuery(sql);
    } catch (...) {
        return false;
    }
    return true;

}

double TimeLog::getTotalHoursFromDB(int employeeID, const std::string &startDate, const std::string &endDate, DatabaseConnection db) {
}
