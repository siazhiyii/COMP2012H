#include <iostream>
#include "employee_system.h"

using namespace std;

const string IDX = "Test Case ";
const string NAME = ": ";
const string LINE = "--------------------------------------------------";

int main() {
    int testId;
    cin >> testId;
    
    if (testId == 1) {
        string name = "Part I - Testing calculateEmployee";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        FullTimeEmployee employee(1, "John Doe", 80000, "Senior", 5000, 1000);
        employee.displayInfo();

    } else if (testId == 2) {
        string name = "Part I - Testing calculateEmployee";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        ContractEmployee employee(2, "Jane Smith", 60000, "Mid", 40, 75);
        employee.displayInfo();

    } else if (testId == 3) {
        string name = "Part II - Testing insert";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        BSTree<int> bst;
        bst.insert(10);
        cout << "Root value: " << *bst.find(10) << endl;
        cout << "Tree size: " << bst.getSize() << endl;
        
    } else if (testId == 4) {
        string name = "Part II - Testing insert";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        BSTree<int> bst;
        bst.insert(10);
        cout << "Root value: " << *bst.find(10) << endl;
        cout << "Tree size: " << bst.getSize() << endl;
        
    } else if (testId == 5) {
        string name = "Part II - Testing insert";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        BSTree<int> bst;
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        cout << "Can find 5? " << boolalpha << (*bst.find(5) == 5) << endl;
        cout << "Can find 15? " << boolalpha << (*bst.find(15) == 5) << endl;
        cout << "Tree is balanced with size: " << bst.getSize() << endl;
        cout << "Height of tree: " << bst.getHeight() << endl;
        
    } else if (testId == 6) {
        string name = "Part II - Testing insert";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        BSTree<int> bst;
        bst.insert(10);
        bst.insert(10);
        cout << "Tree is with size: " << bst.getSize() << endl;
        
    } else if (testId == 7) {
        string name = "Part II - Testing remove";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        BSTree<int> bst;
        cout << "Remove from empty tree result: " << boolalpha << bst.remove(5) << endl;
        
    } else if (testId == 8) {
        string name = "Part II - Testing remove";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        BSTree<int> bst;
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        cout << "Original tree size: " << bst.getSize() << endl;
        cout << "Remove 5 from tree: " << boolalpha << bst.remove(5) << endl;
        cout << "5 exist in tree: " << boolalpha << (bool) bst.find(5) << endl;
        cout << "New tree size: " << bst.getSize() << endl;
        
    } else if (testId == 9) {
        string name = "Part II - Testing remove";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        BSTree<int> bst;
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        cout << "Original tree size: " << bst.getSize() << endl;
        cout << "Remove 10 from tree: " << boolalpha << bst.remove(10) << endl;
        cout << "New tree size: " << bst.getSize() << endl;
        
    } else if (testId == 10) {
        string name = "Part II - Testing inorderTraversal";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        BSTree<int> bst;
        vector<int> result = bst.inorderTraversal();
        cout << "Empty tree traversal size: " << result.size() << endl;
        
    } else if (testId == 11) {
        string name = "Part II - Testing inorderTraversal";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        BSTree<int> bst;
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(3);
        bst.insert(7);
        vector<int> result = bst.inorderTraversal();
        cout << "Inorder tree traversal size: " << result.size() << endl;
        cout << "Inorder traversal: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
        
    } else if (testId == 12) {
        string name = "Part III - Testing addEmployee";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        EmployeeManagementSystem system;
        Employee* emp = system.addEmployee("FullTime", "John Doe", 80000, "Senior", 5000, 1000);
        cout << "Employee Count: " << system.getEmployeeCount() << endl;
        emp->displayInfo();
        
    } else if (testId == 13) {
        string name = "Part III - Testing addEmployee";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        EmployeeManagementSystem system;
        Employee* emp = system.addEmployee("Contract", "Jane Smith", 60000, "Mid", 40, 75);
        cout << "Employee Count: " << system.getEmployeeCount() << endl;
        emp->displayInfo();
        
    } else if (testId == 14) {
        string name = "Part III - Testing findEmployeeById";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        EmployeeManagementSystem system;
        Employee* emp = system.addEmployee("FullTime", "John Doe", 80000, "Senior", 5000, 1000);
        system.addEmployee("Contract", "Jane Smith", 60000, "Mid", 40, 75);
        system.findEmployeeById(emp->getId())->displayInfo();
        
    } else if (testId == 15) {
        string name = "Part III - Testing getEmployeesByRole";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        EmployeeManagementSystem system;
        system.addEmployee("FullTime", "John Doe", 80000, "Senior", 5000, 1000);
        system.addEmployee("Contract", "Jane Smith", 60000, "Mid", 40, 75);
        vector<Employee*> emps = system.getEmployeesByRole("FullTime");
        cout << "Number of query results: " << emps.size() << endl;
        for (Employee* emp : emps) {
            emp->displayInfo();
        }

    } else if (testId == 16) {
        string name = "Part III - Testing findEmployeeByName";
        cout << IDX << testId << NAME << name << endl
             << LINE << endl;
        
        EmployeeManagementSystem system;
        system.addEmployee("FullTime", "John Doe", 80000, "Senior", 5000, 1000);
        system.addEmployee("Contract", "Jane Smith", 60000, "Mid", 40, 75);
        system.findEmployeeByName("Jane Smith")->displayInfo();
        
    } 

    return 0;
}