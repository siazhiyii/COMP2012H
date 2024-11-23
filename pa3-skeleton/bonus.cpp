#include <iostream>
#include "table.h"

using namespace std;

const string IDX = "Test Case ";
const string NAME = ": ";
const string LINE = "--------------------------------------------------";

int main() {

    int caseID;
    cin >> caseID;

    if (caseID == 31) {
        string name = "Part I - Testing bonus Table::sortBy";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;

        Table table("Courses");
        table.setupColumn("Name", (string) "");
        table.setupColumn("Room", (string) "N/A");
        table.setupColumn("Num. Of Enrollment", 0);
        table.setupColumn("Passing Rate", 0.0);
        table.setupColumn("Blended Mode", false);

        table.insertRecord({"Name", "Passing Rate"}, "COMP1021", 90.5);
        table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
            "COMP2012H", 28, "Rm 5583", 100.0);
        table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}
            , false, "COMP3711", 89.3, "LTL", 181);
        table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

        table.sortBy("Name").sortBy("Num. Of Enrollment").print();

    } else if (caseID == 32) {
        string name = "Part I - Testing bonus Table::operator-";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;

        Table table("Courses");
        table.setupColumn("Name", (string) "");
        table.setupColumn("Room", (string) "N/A");
        table.setupColumn("Num. Of Enrollment", 0);
        table.setupColumn("Passing Rate", 0.0);
        table.setupColumn("Blended Mode", false);

        table.insertRecord({"Name", "Passing Rate"}, "COMP1021 2024F", 90.5);
        table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
            "COMP2012H 2024F", 28, "Rm 5583", 100.0);
        table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}
            , false, "COMP3711 2024F", 89.3, "LTL", 181);
        table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111 2024F");
        table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
            "COMP2012H 2024F", 28, "Rm 5583", 100.0);
        table.insertRecord({"Name", "Num. Of Enrollment", "Passing Rate"},
            "COMP2012H 2023F", 66, 101.0);


        Table table2("Courses");
        table2.setupColumn("Name", (string) "");
        table2.setupColumn("Room", (string) "N/A");
        table2.setupColumn("Num. Of Enrollment", 0);
        table2.setupColumn("Passing Rate", 0.0);
        table2.setupColumn("Blended Mode", false);

        table2.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
            "COMP2012H 2024F", 28, "Rm 5583", 100.0);
        table2.insertRecord({"Blended Mode", "Name"}, true, "COMP3111 2024F");
        table2.insertRecord({"Blended Mode", "Name"}, true, "COMP3711 2024F");

        (table - table2).print();
        
    } else if (caseID == 33) {
        string name = "Part I - Testing bonus Table::operator*";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;

        Table table("Courses");
        table.setupColumn("Name", (string) "");
        table.setupColumn("Room", (string) "N/A");
        table.setupColumn("Num. Of Enrollment", 0);
        table.setupColumn("Passing Rate", 0.0);
        table.setupColumn("Blended Mode", false);

        table.insertRecord({"Name", "Passing Rate"}, "COMP1021 2024F", 90.5);
        table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
            "COMP2012H 2024F", 28, "Rm 5583", 100.0);
        table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}
            , false, "COMP3711 2024F", 89.3, "LTL", 181);
        table.insertRecord({"Name", "Num. Of Enrollment", "Passing Rate"},
            "COMP2012H 2023F", 66, 101.0);


        Table table2("Students");
        table2.setupColumn("Name", (string) "");
        table2.setupColumn("Student ID", (string) "");
        table2.setupColumn("Year", 1);

        table2.insertRecord({"Name", "Student ID", "Year"}, "Bob", "12345678", 3);
        table2.insertRecord({"Name", "Student ID", "Year"}, "Alice", "20766000", 5);

        (table * table2).print();
        
    } else if (caseID == 34) {
        string name = "Part I - Testing bonus integration test on Table";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        Table table("Courses");
        table.setupColumn("Name", (string) "");
        table.setupColumn("Room", (string) "N/A");
        table.setupColumn("Num. Of Enrollment", 0);
        table.setupColumn("Passing Rate", 0.0);
        table.setupColumn("Blended Mode", false);

        table.insertRecord({"Name", "Passing Rate"}, "COMP1021 2024F", 90.5);
        table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
            "COMP2012H 2024F", 28, "Rm 5583", 100.0);
        table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}
            , false, "COMP3711 2024F", 89.3, "LTL", 181);
        table.insertRecord({"Name", "Num. Of Enrollment", "Passing Rate"},
            "COMP2012H 2023F", 66, 101.0);


        Table table2("Students");
        table2.setupColumn("Name", (string) "");
        table2.setupColumn("Student ID", (string) "");
        table2.setupColumn("Year", 1);

        table2.insertRecord({"Name", "Student ID", "Year"}, "Bob", "12345678", 3);
        table2.insertRecord({"Name", "Student ID", "Year"}, "Alice", "20766000", 5);


        Table table3("Grades");
        table3.setupColumn("Student ID", (string) "");
        table3.setupColumn("Offering", (string) "");
        table3.setupColumn("Grade", (string) "");

        table3.insertRecord({"Student ID", "Offering", "Grade"}, "12345678", "COMP2012H 2023F", "A");
        table3.insertRecord({"Student ID", "Offering", "Grade"}, "12345678", "COMP3711 2024F", "B+");
        table3.insertRecord({"Student ID", "Offering", "Grade"}, "20766000", "COMP1021 2024F", "B-");


        Table crossedTable = (table * table2 * table3);
        crossedTable = crossedTable[crossedTable.get<string>("Grades.Student ID") == crossedTable.get<string>("Courses_Students.Students.Student ID")
        && crossedTable.get<string>("Grades.Offering") == crossedTable.get<string>("Courses_Students.Courses.Name")];

        // crossedTable.renameColumn({"Courses_Students.Courses.Name", "Courses_Students.Courses.Passing Rate", "Courses_Students.Students.Name", "Grades.Grade"}, {"Course Name", "Passing Rate", "Student Name", "Grade"})
        // .select({"Course Name", "Passing Rate", "Student Name", "Grade"}).sortBy("Grade").print();
        crossedTable = crossedTable.renameColumn({"Courses_Students.Courses.Name", "Courses_Students.Courses.Passing Rate", "Courses_Students.Students.Name", "Grades.Grade"}, {"Course Name", "Passing Rate", "Student Name", "Grade"});
        crossedTable.print();
        crossedTable = crossedTable.select({"Course Name", "Passing Rate", "Student Name", "Grade"});
        crossedTable.print();
        crossedTable= crossedTable.sortBy("Grade");
        crossedTable.print();

    }

}