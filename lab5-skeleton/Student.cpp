#include "Student.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// TODO: Implement the member functions of Student class,
// as well as the friend overloaded operator.
// Refer to the descriptions in Student.h for details

// Default constructor
// Set ID to 0, Name to empty string, and GPAs to 0.0
Student::Student() {
    ID = 0;
    Name = "";
    GPA_year1 = 0.0;
    GPA_year2 = 0.0;
}

// Constructor with parameters provided
Student::Student(int id, const string &name, double gpa_year1, double gpa_year2) {
    ID = id;
    Name = name;
    GPA_year1 = gpa_year1;
    GPA_year2 = gpa_year2;
}

// Set ID to provided parameter
// If input is negative, output "ERROR: Negative ID is not allowed" and return
void Student::setID(int id) {
    if (id < 0) {
        cout << "ERROR: Negative ID is not allowed" << endl;
        return;
    }
    ID = id;
}

// Return the ID of the student
int Student::getID() const {
    return ID;
}

// Set Name to provided parameter
void Student::setName(const string &name) {
    Name = name;
}

// Return the Name of the student
string Student::getName() const {
    return Name;
}

// Set GPA to provided parameter
// If input is negative, output "ERROR: Negative GPA is not allowed" and return
void Student::setGPA(double gpa_year1, double gpa_year2) {
    if (gpa_year1 < 0 || gpa_year2 < 0) {
        cout << "ERROR: Negative GPA is not allowed" << endl;
        return;
    }
    GPA_year1 = gpa_year1;
    GPA_year2 = gpa_year2;
}

// Return the average GPA of the student
double Student::getAverageGPA() const {
    return (GPA_year1 + GPA_year2) / 2;
}

// Set all attributes of the student
// If ID or GPA is negative, output "ERROR: Negative value is not allowed" and return
void Student::setAttributes(int id, const string &name, double gpa_year1, double gpa_year2) {
    if (id < 0 || gpa_year1 < 0 || gpa_year2 < 0) {
        cout << "ERROR: Negative value is not allowed" << endl;
        return;
    }
    ID = id;
    Name = name;
    GPA_year1 = gpa_year1;
    GPA_year2 = gpa_year2;
}

// The overloaded << operator for I/O printing
// You should refer to the expected output for the output format
ostream &operator<<(ostream &output, const Student &s) {
    output << "Student: ID = " << s.ID << ", Name = " << s.Name << ", GPA = " << s.getAverageGPA();
    return output;
}
