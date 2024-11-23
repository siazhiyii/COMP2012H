#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
protected:
    int id;
    std::string name;
    double baseSalary;
    std::string level;

public:
    Employee(int id, const std::string &name, double salary, const std::string &level);
    virtual ~Employee() = default;

    virtual double calculateSalary() const = 0;
    virtual std::string getRole() const = 0;
    virtual void displayInfo() const = 0;
    
    int getId() const;
    const std::string &getName() const;
    double getBaseSalary() const;
    const std::string &getLevel() const;
};

class FullTimeEmployee : public Employee
{
private:
    double bonus;
    double stockOptions;

public:
    FullTimeEmployee(int id, const std::string &name, double salary,
                     const std::string &level, double bonus, double stockOptions);

    double calculateSalary() const override;
    std::string getRole() const override;
    void displayInfo() const override;

    double getBonus() const;
    double getStockOptions() const;

    std::string toString() const;
    void adjustSalary(double percentage);
    void adjustBonus(double newBonus);
};

class ContractEmployee : public Employee
{
private:
    double hoursWorked;
    double hourlyRate;

public:
    ContractEmployee(int id, const std::string &name, double baseSalary,
                     const std::string &level, double hours, double rate);

    double calculateSalary() const override;
    std::string getRole() const override;
    void displayInfo() const override;

    int getHoursWorked() const;
    double getHourlyRate() const;

    std::string toString() const;
    void adjustHourlyRate(double newRate);
    void setHoursWorked(int hours);
};

struct CompareById
{
    bool operator()(const Employee* a, const Employee* b) const {
        return a->getId() < b->getId();
    }
};

struct CompareByName
{
    bool operator()(const Employee* a, const Employee* b) const {
        return a->getName() < b->getName();
    }
};

#endif