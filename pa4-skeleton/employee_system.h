#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_H
#define EMPLOYEE_MANAGEMENT_SYSTEM_H

#include "employee.h"
#include "bst.h"

using namespace std;

// Maximum number of employees the system can store
const int MAX_EMPLOYEES = 1000;

class EmployeeManagementSystem
{
private:
    BSTree<Employee *, CompareById> employeesByIdTree;
    BSTree<Employee *, CompareByName> employeesByNameTree;
    int nextEmployeeId;

public:
    // Constructor
    EmployeeManagementSystem() : nextEmployeeId(1) {}

    // Destructor to clean up allocated memory
    ~EmployeeManagementSystem();

    // Creates and adds a new employee to the system
    // Returns pointer to the created employee, or nullptr if creation fails
    Employee *addEmployee(const string &role,
                          const string &name,
                          double salary,
                          const string &level,
                          double bonus = 0,
                          double rate = 0);

    // Removes an employee by their ID
    // Returns true if employee was found and removed, false otherwise
    bool removeEmployee(int empId);

    // Finds and returns pointer to employee with given ID
    // Returns nullptr if employee not found
    Employee *findEmployeeById(int empId) const;

    // Finds and returns pointer to employee with given name. You may assume name is unique.
    // Returns nullptr if employee not found
    Employee *findEmployeeByName(const string &name) const;

    // Gets all employees of a specific role (e.g., "FullTime" or "Contract")
    // employeeList: array to store the found employees
    // maxSize: size of the provided array
    // Returns: number of employees found
    std::vector<Employee *> getEmployeesByRole(const string &role) const;

    // Displays information about all employees
    void displayAllEmployees() const;

    // Returns the total number of employees in the system
    int getEmployeeCount() const;
};

#endif // EMPLOYEE_MANAGEMENT_SYSTEM_H