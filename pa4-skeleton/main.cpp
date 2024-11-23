#include <iostream>
#include "employee_system.h"
#include "command_parser.cpp"

int main()
{
    EmployeeManagementSystem ems;
    CommandParser parser(ems);
    std::string input;

    std::cout << "Employee Management System - Type 'HELP' for a list of commands.\n";
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (!input.empty())
        {
            parser.executeCommand(input);
        }
    }

    return 0;
}
