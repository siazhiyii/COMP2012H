#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int ID;
    string Name;
    double GPA_year1;
    double GPA_year2;

public:
    // Default constructor
    // Set ID to 0, Name to empty string, and GPAs to 0.0
    Student();

    // Constructor with parameters provided
    Student(int id, const string &name, double gpa_year1, double gpa_year2);

    // Set ID to provided parameter
    // If input is negative, output "ERROR: Negative ID is not allowed" and return
    void setID(int id);

    // Return the ID of the student
    int getID() const;

    // Set Name to provided parameter
    void setName(const string &name);

    // Return the Name of the student
    string getName() const;

    // Set GPA to provided parameter
    // If input is negative, output "ERROR: Negative GPA is not allowed" and return
    void setGPA(double gpa_year1, double gpa_year2);

    // Return the average GPA of the student
    double getAverageGPA() const;

    // Set all attributes of the student
    // If ID or GPA is negative, output "ERROR: Negative value is not allowed" and return
    void setAttributes(int id, const string &name, double gpa_year1, double gpa_year2);

    // The overloaded << operator for I/O printing
    // You should refer to the expected output for the output format
    friend ostream &operator<<(ostream &output, const Student &s);
};

#endif // STUDENT_H