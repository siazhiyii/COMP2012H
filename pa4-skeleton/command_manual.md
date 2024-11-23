# Employee Management System - Command Tutorial

## Basic Commands Overview
* ADD - Add new employees (Full-time or Contract)
* FIND - Search for employees by ID
* REMOVE - Remove an employee
* LIST - Display employee information
* STATS - Show system statistics
* HELP - Display available commands
* EXIT - Quit the program

## Detailed Command Usage

### 1. Adding Employees (ADD)

#### Adding Full-time Employees:
```
ADD fulltime "John Smith" 75000 "L3" 10000 5000
```
Parameters:
- fulltime: Employee type
- "John Smith": Employee name (use quotes for names with spaces)
- 75000: Base salary
- "L3": Level
- 10000: Bonus amount
- 5000: Stock options value

#### Adding Contract Employees:
```
ADD contract "Jane Doe" 0 "L2" 160 50
```
Parameters:
- contract: Employee type
- "Jane Doe": Employee name
- 0: Base salary (typically 0 for contractors)
- "L2": Level
- 160: Hours worked
- 50: Hourly rate

### 2. Finding Employees (FIND)
```
FIND id 1001
```
- Searches for an employee with ID 1001
- Displays employee information if found

### 3. Removing Employees (REMOVE)
```
REMOVE 1001
```
- Removes employee with ID 1001
- Confirms if removal was successful

### 4. Listing Employees (LIST)
```
LIST              # Lists all employees
LIST fulltime    # Lists only full-time employees
LIST contract    # Lists only contract employees
```

### 5. Viewing Statistics (STATS)
```
STATS
```
- Shows total number of employees in the system

### 6. Getting Help (HELP)
```
HELP
```
- Displays available commands

### 7. Exiting the Program (EXIT)
```
EXIT
```
- Safely exits the program

## Examples

1. Adding a full-time software engineer:
```
ADD fulltime "Alice Johnson" 85000 "L4" 15000 7500
```

2. Adding a contract developer:
```
ADD contract "Bob Wilson" 0 "L3" 120 65
```

3. Finding an employee:
```
FIND id 1
```

4. Viewing all contract employees:
```
LIST contract
```

## Important Notes

1. Use quotes around names that contain spaces
2. Salary and monetary values should be entered as numbers without currency symbols
3. Hours worked must be between 0 and 744 (max hours in a month)
4. All monetary values (salary, bonus, rate) must be non-negative
5. Employee IDs are automatically assigned by the system