#include "employee.h"
#include <iostream>
#include <iomanip>

// === Employee Class Definitions ===
Employee::Employee(int id, const std::string &name, double salary, const std::string &level)
    : id(id), name(name), baseSalary(salary), level(level) {}

int Employee::getId() const { return id; }
const std::string &Employee::getName() const { return name; }
double Employee::getBaseSalary() const { return baseSalary; }
const std::string &Employee::getLevel() const { return level; }

// === FullTimeEmployee Class Definitions ===
FullTimeEmployee::FullTimeEmployee(int id, const std::string &name, double salary,
                                   const std::string &level, double bonus, double stockOptions)
    : Employee(id, name, salary, level), bonus(bonus), stockOptions(stockOptions) {}

double FullTimeEmployee::calculateSalary() const
{
    // Please implement this function
    // base salary plus bonus and stock options
    return baseSalary + bonus + stockOptions;
}

std::string FullTimeEmployee::getRole() const { return "FullTime"; }

void FullTimeEmployee::displayInfo() const
{
    std::cout << "\n=== Full Time Employee Details ===\n"
              << "ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Level: " << level << "\n"
              << "Base Salary: $" << std::fixed << std::setprecision(2) << baseSalary << "\n"
              << "Bonus: $" << bonus << "\n"
              << "Stock Options: $" << stockOptions << "\n"
              << "Total Compensation: $" << calculateSalary() << "\n"
              << "===============================\n";
}


double FullTimeEmployee::getBonus() const { return bonus; }
double FullTimeEmployee::getStockOptions() const { return stockOptions; }

std::string FullTimeEmployee::toString() const
{
    std::ostringstream oss;
    oss << "FullTimeEmployee[ID=" << getId()
        << ", Name=" << getName()
        << ", Level=" << getLevel()
        << ", Base=" << getBaseSalary()
        << ", Bonus=" << getBonus()
        << ", Stock=" << getStockOptions()
        << ", Total=" << calculateSalary() << "]";
    return oss.str();
}

void FullTimeEmployee::adjustSalary(double percentage)
{
    if (percentage < -50 || percentage > 100)
    {
        throw std::invalid_argument("Salary adjustment must be between -50% and +100%");
    }
    baseSalary *= (1 + percentage / 100);
}

void FullTimeEmployee::adjustBonus(double newBonus)
{
    if (newBonus < 0)
    {
        throw std::invalid_argument("Bonus cannot be negative");
    }
    bonus = newBonus;
}

// === ContractEmployee Class Definitions ===
ContractEmployee::ContractEmployee(int id, const std::string &name, double baseSalary,
                                   const std::string &level, double hours, double rate)
    : Employee(id, name, baseSalary, level), hoursWorked(hours), hourlyRate(rate) {}

double ContractEmployee::calculateSalary() const
{
    // Please implement this function
    // Multiplying the number of hours they work by the hourly wage.
    return hoursWorked * hourlyRate;
}

std::string ContractEmployee::getRole() const { return "Contract"; }

void ContractEmployee::displayInfo() const
{
    std::cout << "\n=== Contract Employee Details ===\n"
              << "ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Level: " << level << "\n"
              << "Hours Worked: " << hoursWorked << "\n"
              << "Hourly Rate: $" << std::fixed << std::setprecision(2) << hourlyRate << "\n"
              << "Total Compensation: $" << calculateSalary() << "\n"
              << "===============================\n";
}

int ContractEmployee::getHoursWorked() const { return hoursWorked; }
double ContractEmployee::getHourlyRate() const { return hourlyRate; }

std::string ContractEmployee::toString() const
{
    std::ostringstream oss;
    oss << "ContractEmployee[ID=" << getId()
        << ", Name=" << getName()
        << ", Level=" << getLevel()
        << ", Hours=" << getHoursWorked()
        << ", Rate=" << getHourlyRate()
        << ", Total=" << calculateSalary() << "]";
    return oss.str();
}

void ContractEmployee::adjustHourlyRate(double newRate)
{
    if (newRate < 0)
    {
        throw std::invalid_argument("Hourly rate cannot be negative");
    }
    hourlyRate = newRate;
}

void ContractEmployee::setHoursWorked(int hours)
{
    if (hours < 0 || hours > 744)
    { // Max hours in a month
        throw std::invalid_argument("Hours must be between 0 and 744");
    }
    hoursWorked = hours;
}

