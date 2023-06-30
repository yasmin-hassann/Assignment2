#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
protected:
    std::string name;   // Employee's name
    int age;            // Employee's age

public:
    Employee(const std::string& name, int age);

    // Virtual functions to be overridden by derived classes
    virtual double calculateWeeklySalary() const = 0;
    virtual double computeHealthCareContributions() const = 0;
    virtual int computeVacationDays() const = 0;
};

class Professional : public Employee {
private:
    double monthlySalary;   // Monthly salary of the professional employee
    int vacationDays;       // Number of vacation days for the professional employee

public:
    Professional(const std::string& name, int age, double monthlySalary, int vacationDays);

    // Override base class virtual functions
    double calculateWeeklySalary() const override;
    double computeHealthCareContributions() const override;
    int computeVacationDays() const override;
};

class Nonprofessional : public Employee {
private:
    double hourlyRate;      // Hourly rate of the nonprofessional employee
    int vacationHours;      // Number of vacation hours for the nonprofessional employee

public:
    Nonprofessional(const std::string& name, int age, double hourlyRate, int vacationHours);

    // Override base class virtual functions
    double calculateWeeklySalary() const override;
    double computeHealthCareContributions() const override;
    int computeVacationDays() const override;
};

#endif // EMPLOYEE_H
