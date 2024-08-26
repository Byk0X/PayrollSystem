//
// Created by maciejl on 8/18/24.
//

#ifndef TIMELOG_H
#define TIMELOG_H

#include <string>


#include "DatabaseConnection.h"


class TimeLog {
private:
    int employeeID;
    std::string date;
    double hoursWorked;

public:



    TimeLog(int id, const std::string& d, double hours)
            : employeeID(id), date(d), hoursWorked(hours) {}

    // Gettery i Settery
    int getEmployeeID() const { return employeeID; }
    std::string getDate() const { return date; }
    double getHoursWorked() const { return hoursWorked; }

    void setDate(const std::string& d) { date = d; }
    void setHoursWorked(double hours) { hoursWorked = hours; }

    // Metody do interakcji z bazą danych
    bool saveToDB(DatabaseConnection &db);
    static double getTotalHoursFromDB(int employeeID, const std::string& startDate, const std::string& endDate, DatabaseConnection &db);
};



#endif //TIMELOG_H
