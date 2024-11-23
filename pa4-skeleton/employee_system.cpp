#include "employee_system.h"
#include <iostream>
#include <stdexcept>

Employee *EmployeeManagementSystem::addEmployee(
    const std::string &role, const std::string &name, double salary, const std::string &level,
    double hours_or_bonus, double rate_or_stock_option)
{
    // Please implement this function
    Employee *newEmployee = nullptr;
    if (role == "FullTime")
    {
        newEmployee = new FullTimeEmployee(nextEmployeeId++, name, salary, level, hours_or_bonus, rate_or_stock_option);
    }
    else if (role == "Contract")
    {
        newEmployee = new ContractEmployee(nextEmployeeId++, name, salary, level, static_cast<int>(hours_or_bonus), rate_or_stock_option);
    }
    else
    {
        throw std::invalid_argument("Invalid employee role");
    }

    if (newEmployee)
    {
        employeesByIdTree.insert(newEmployee);
        employeesByNameTree.insert(newEmployee);
    }
    return newEmployee;
}

bool EmployeeManagementSystem::removeEmployee(int empId)
{
    // Please implement this function
    Employee *employee = findEmployeeById(empId);
    if (employee)
    {
        employeesByIdTree.remove(employee);
        employeesByNameTree.remove(employee);
        delete employee;
        return true;
    }
    return false;
}

Employee *EmployeeManagementSystem::findEmployeeById(int empId) const
{
    // Please implement this function
    CompareById compareById;
    std::vector<Employee *> allEmployees = employeesByIdTree.inorderTraversal();
    for (Employee *employee : allEmployees)
    {
        if (employee->getId() == empId)
        {
            return employee;
        }
    }
    return nullptr;
}

Employee *EmployeeManagementSystem::findEmployeeByName(const std::string &name) const
{
    // Please implement this function
    CompareByName compareByName;
    std::vector<Employee *> allEmployees = employeesByNameTree.inorderTraversal();
    for (Employee *employee : allEmployees)
    {
        if (employee->getName() == name)
        {
            return employee;
        }
    }
    return nullptr;
}

std::vector<Employee *> EmployeeManagementSystem::getEmployeesByRole(const std::string &role) const
{
    // Please implement this function
    std::vector<Employee *> result;
    std::vector<Employee *> allEmployees = employeesByIdTree.inorderTraversal();
    for (Employee *emp : allEmployees)
    {
        if ((role == "FullTime" && dynamic_cast<FullTimeEmployee *>(emp)) ||
            (role == "Contract" && dynamic_cast<ContractEmployee *>(emp)))
        {
            result.push_back(emp);
        }
    }
    return result;
}

void EmployeeManagementSystem::displayAllEmployees() const
{
    std::vector<Employee *> employees = employeesByIdTree.inorderTraversal();
    for (Employee *emp : employees)
    {
        emp->displayInfo();
        std::cout << "------------------------\n";
    }
}

int EmployeeManagementSystem::getEmployeeCount() const
{
    return employeesByIdTree.getSize();
}

EmployeeManagementSystem::~EmployeeManagementSystem()
{
    // Please implement this function
    std::vector<Employee *> allEmployees = employeesByIdTree.inorderTraversal();
    for (Employee *employee : allEmployees)
    {
        delete employee;
    }
}
