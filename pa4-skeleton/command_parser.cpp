#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip> // for std::quoted
#include <functional>
#include "employee_system.h"

class CommandParser
{
public:
    class ParseException : public std::runtime_error
    {
    public:
        explicit ParseException(const std::string &msg) : std::runtime_error(msg) {}
    };

private:
    EmployeeManagementSystem &ems;
    std::map<std::string, std::function<void(const std::vector<std::string> &)>> commandMap;

    // Tokenizer for command input with quoted string support
    static std::vector<std::string> tokenize(const std::string &input)
    {
        std::istringstream stream(input);
        std::vector<std::string> tokens;
        std::string token;
        while (stream >> std::quoted(token))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

public:
    explicit CommandParser(EmployeeManagementSystem &system) : ems(system)
    {
        initializeCommands();
    }

    void executeCommand(const std::string &input)
    {
        auto tokens = tokenize(input);
        if (tokens.empty())
            throw ParseException("Empty command");

        std::string command = tokens[0];
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);

        auto it = commandMap.find(command);
        if (it == commandMap.end())
        {
            throw ParseException("Unknown command: " + command);
        }

        it->second(tokens);
    }

private:
    void initializeCommands()
    {
        // Add employee command
        commandMap["add"] = [this](const std::vector<std::string> &tokens)
        {
            if (tokens.size() < 6)
                throw ParseException("Usage: ADD <role> <name> <base_salary> <level> <bonus/stock_options or hours/rate>");

            std::string role = tokens[1];
            std::string name = tokens[2];
            double baseSalary = std::stod(tokens[3]);
            std::string level = tokens[4];
            // std::cout << "role: " << role << "zzz" << "\n";

            if (role == "fulltime")
            {
                if (tokens.size() < 7)
                    throw ParseException("Usage: ADD FullTime <name> <base_salary> <level> <bonus> <stock_options>");
                double bonus = std::stod(tokens[5]);
                double stockOptions = std::stod(tokens[6]);
                auto emp = ems.addEmployee(role, name, baseSalary, level, bonus, stockOptions);
                emp->displayInfo();
            }
            else if (role == "contract")
            {
                if (tokens.size() < 7)
                    throw ParseException("Usage: ADD Contract <name> <base_salary> <level> <hours_worked> <hourly_rate>");
                double hoursWorked = std::stod(tokens[5]);
                double hourlyRate = std::stod(tokens[6]);
                auto emp = ems.addEmployee(role, name, baseSalary, level, hoursWorked, hourlyRate); // Pass rate as the 6th parameter
                emp->displayInfo();
            }
            else
            {
                throw ParseException("Invalid employee role. Must be 'fulltime' or 'contract'.");
            }
        };

        // Find employee by id or name only
        commandMap["find"] = [this](const std::vector<std::string> &tokens)
        {
            if (tokens.size() < 3)
                throw ParseException("Usage: FIND id <value>");
            std::string criterion = tokens[1];

            if (criterion == "id")
            {
                int id = std::stoi(tokens[2]);
                auto emp = ems.findEmployeeById(id);
                if (emp)
                    emp->displayInfo();
                else
                    std::cout << "Employee not found.\n";
            }
            else
            {
                throw ParseException("Invalid criterion. Only 'id' is supported.");
            }
        };

        // Remove employee
        commandMap["remove"] = [this](const std::vector<std::string> &tokens)
        {
            if (tokens.size() < 2)
                throw ParseException("Usage: REMOVE <id>");
            int id = std::stoi(tokens[1]);
            if (ems.removeEmployee(id))
                std::cout << "Employee removed.\n";
            else
                std::cout << "Employee not found.\n";
        };

        // List employees
        commandMap["list"] = [this](const std::vector<std::string> &tokens)
        {
            if (tokens.size() > 1 && tokens[1] == "fulltime")
            {
                auto employees = ems.getEmployeesByRole("FullTime");
                for (const auto &emp : employees)
                    emp->displayInfo();
            }
            else if (tokens.size() > 1 && tokens[1] == "contract")
            {
                auto employees = ems.getEmployeesByRole("Contract");
                for (const auto &emp : employees)
                    emp->displayInfo();
            }
            else
            {
                ems.displayAllEmployees();
            }
        };

        // Stats
        commandMap["stats"] = [this](const std::vector<std::string> &)
        {
            std::cout << "Total Employees: " << ems.getEmployeeCount() << "\n";
        };

        // Help
        commandMap["help"] = [](const std::vector<std::string> &)
        {
            std::cout << "Commands:\nADD, FIND, REMOVE, LIST, STATS, HELP, EXIT\n";
        };

        // Exit
        commandMap["exit"] = [](const std::vector<std::string> &)
        {
            std::cout << "Exiting...\n";
            exit(0);
        };
    }
};
