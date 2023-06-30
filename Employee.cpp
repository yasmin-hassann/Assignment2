#include "Employee.h"

Employee::Employee(const std::string& name, int age)
    : name(name), age(age) {}

Professional::Professional(const std::string& name, int age, double monthlySalary, int vacationDays)
    : Employee(name, age), monthlySalary(monthlySalary), vacationDays(vacationDays) {}

double Professional::calculateWeeklySalary() const {
    // Assuming a month consists of 4 weeks
    return monthlySalary / 4;
}

double Professional::computeHealthCareContributions() const {
    // Example rule: 5% of monthly salary
    return monthlySalary * 0.05;
}

int Professional::computeVacationDays() const {
    // Assuming 5 working days in a week
    return vacationDays / 5;
}

Nonprofessional::Nonprofessional(const std::string& name, int age, double hourlyRate, int vacationHours)
    : Employee(name, age), hourlyRate(hourlyRate), vacationHours(vacationHours) {}

double Nonprofessional::calculateWeeklySalary() const {
    // Assuming 40 working hours in a week
    return hourlyRate * 40;
}

double Nonprofessional::computeHealthCareContributions() const {
    // Example rule: 2% of weekly salary
    return calculateWeeklySalary() * 0.02;
}

int Nonprofessional::computeVacationDays() const {
    // Assuming 8 working hours in a day
    return vacationHours / 8;
}