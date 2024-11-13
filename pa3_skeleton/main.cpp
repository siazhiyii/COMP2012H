#include <iostream>
#include "table.h"

using namespace std;

const string IDX = "Test Case ";
const string NAME = ": ";
const string LINE = "--------------------------------------------------";

int main()
{

    int game_over = 1;
    while (game_over)
    {

        int caseID;
        cout << "Enter the test case ID (1-30): ";
        cin >> caseID;
        game_over = caseID;

        if (caseID == 1)
        {
            cout << "yes" << endl;
            string name = "Part I - Testing default constructor of Column";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", 2);
            cout << "Key: " << column.key() << endl;
            cout << "Default value: " << column.get_default_value() << endl;
            cout << "Size: " << column.size() << endl;
        }
        else if (caseID == 2)
        {
            string name = "Part I - Testing copy constructor of Column";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", 10);
            Column<int> column2(column);

            cout << "Key: " << column2.key() << endl;
            cout << "Default value: " << column2.get_default_value() << endl;
            cout << "Size: " << column2.size() << endl;
        }
        else if (caseID == 3)
        {
            string name = "Part I - Testing Column::operator=";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", 10);
            Column<int> column2("My Another Column", 10, 100);

            column2 = column;

            cout << "Key: " << column2.key() << endl;
            cout << "Default value: " << column2.get_default_value() << endl;
            cout << "Size: " << column2.size() << endl;
        }
        else if (caseID == 31)
        {
            string name = "Part I - Testing Column::operator=";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", 10);
            column.addEntry(1);
            column.addEntry(2);
            column.addEntry(3);
            Column<int> column2("My Another Column", 10, 100);

            column2 = column;

            cout << "Key: " << column2.key() << endl;
            cout << "Default value: " << column2.get_default_value() << endl;
            cout << "Size: " << column2.size() << endl;
            for (int i = 0; i < column2.size(); i++)
            {
                cout << column2[i] << " ";
            }
        }
        else if (caseID == 4)
        {
            string name = "Part I - Testing Column::addEntry";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", -1);
            cout << "Contents in the column: " << endl;
            for (int i = 0; i < 10; i++)
            {
                column.addEntry(i * 2);
            }
            for (int i = 0; i < column.size(); i++)
            {
                cout << column[i] << " ";
            }
        }
        else if (caseID == 5)
        {
            string name = "Part I - Testing Column::addDefault";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", 0);
            cout << "Contents in the column: " << endl;
            for (int i = 0; i < 10; i++)
            {
                if (i % 2)
                    column.addEntry(i * 2);
                else
                    column.addDefault(i);
            }
            for (int i = 0; i < column.size(); i++)
            {
                cout << column[i] << " ";
            }
        }
        else if (caseID == 6)
        {
            string name = "Part I - Testing Column::operator[] const of index";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", 0);
            cout << "Contents in the column: " << endl;
            for (int i = 0; i < 10; i++)
            {
                column.addEntry(i * 3);
            }
            for (int i = 0; i < column.size(); i++)
            {
                cout << column[i] << " ";
            }
        }
        else if (caseID == 7)
        {
            string name = "Part I - Testing Column::operator[] of index";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", 0);
            cout << "Contents in the column: " << endl;
            for (int i = 0; i < 10; i++)
            {
                column.addEntry(i * 3);
            }
            column[3] = 500;
            column[-3] = 1000;
            for (int i = 0; i < column.size(); i++)
            {
                cout << column[i] << " ";
            }
        }
        else if (caseID == 8)
        {
            string name = "Part I - Testing Column::removeEntry";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", 100);
            cout << "Contents in the column: " << endl;
            for (int i = 0; i < 10; i++)
            {
                column.addEntry(-i);
            }
            column.removeEntry(2);
            column.removeEntry(6);
            for (int i = 0; i < column.size(); i++)
            {
                cout << column[i] << " ";
            }
        }
        else if (caseID == 9)
        {
            string name = "Part I - Testing Column::removeEntry";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column", 100);
            cout << "Contents in the column: " << endl;
            for (int i = 0; i < 10; i++)
            {
                column.addEntry(i);
            }
            column.updateEntry(-2, 20);
            column.updateEntry(6, 60);
            for (int i = 0; i < column.size(); i++)
            {
                cout << column[i] << " ";
            }
        }
        else if (caseID == 10)
        {
            string name = "Part I - Testing Column::concat";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column 1", 2012);
            Column<int> column2("My Column 2", 9999);

            for (int i = 10; i < 20; i++)
            {
                column.addEntry(i);
            }

            for (int i = -10; i < 0; i++)
            {
                column2.addEntry(i);
            }

            Column<int> column3 = column.concat(column2);

            cout << "Key: " << column3.key() << endl;
            cout << "Default value: " << column3.get_default_value() << endl;
            cout << "Size: " << column3.size() << endl;
            cout << "Contents in the column: " << endl;

            for (int i = 0; i < column3.size(); i++)
            {
                cout << column3[i] << " ";
            }
        }
        else if (caseID == 11)
        {
            string name = "Part I - Testing Column::operator of boolean operations";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column 1", 2012);
            Column<int> column2("My Column 2", 9999);

            for (int i = 10; i < 20; i++)
            {
                column.addEntry(i);
            }

            for (int i = -10; i < 0; i++)
            {
                column2.addEntry(i);
            }

            Column<bool> column3 = (column > 14) && (column2 <= -4) || !(column > column2);

            cout << "Key: " << column3.key() << endl;
            cout << "Default value: " << column3.get_default_value() << endl;
            cout << "Size: " << column3.size() << endl;
            cout << "Contents in the column: " << endl;

            for (int i = 0; i < column3.size(); i++)
            {
                cout << column3[i] << " ";
            }
        }
        else if (caseID == 12)
        {
            string name = "Part I - Testing Column::operator[] of filter";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Column<int> column("My Column 1", 2012);
            for (int i = 10; i < 20; i++)
            {
                column.addEntry(i);
            }

            Column<bool> column2("Boolean column", 0);
            for (int i = 0; i < 10; i++)
            {
                column2.addEntry(i % 2);
            }

            Column<int> column3 = column[column2];
            cout << "Key: " << column3.key() << endl;
            cout << "Default value: " << column3.get_default_value() << endl;
            cout << "Size: " << column3.size() << endl;
            cout << "Contents in the column: " << endl;

            for (int i = 0; i < column3.size(); i++)
            {
                cout << column3[i] << " ";
            }
        }
        else if (caseID == 13)
        {
            string name = "Part II - Testing default constructor of Table";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.print();
        }
        else if (caseID == 14)
        {
            string name = "Part II - Testing Table::setupColumn";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            table.print();
        }
        else if (caseID == 15)
        {
            string name = "Part II - Testing Table::removeColumn";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            table.removeColumn("Passing Rate");

            table.print();
        }
        else if (caseID == 16)
        {
            string name = "Part II - Testing Table::get";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            cout << "Testing get Name key work? " << boolalpha << (table.get<string>("Name").key() == "Name");
        }
        else if (caseID == 17)
        {
            string name = "Part II - Testing copy constructor of Table";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            Table table2(table);

            table2.print();
        }
        else if (caseID == 18)
        {
            string name = "Part II - Testing Table::operator=";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            Table table2("People");
            table2.setupColumn("Name", (string) "No Name");

            table2 = table;

            table2.print();
        }
        else if (caseID == 19)
        {
            string name = "Part II - Testing Table::insertEntryForColumn & postInsertEntry";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
                               "COMP2012H", 28, "Rm 5583", 100.0);
            table.insertRecord({"Name"}, "COMP1021");
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

            table.print();
        }
        else if (caseID == 20)
        {
            string name = "Part II - Testing Table::setupColumn after insert";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
                               "COMP2012H", 28, "Rm 5583", 100.0);
            table.insertRecord({"Name"}, "COMP1021");
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

            table.setupColumn("Description", (string) "");

            table.print();
        }
        else if (caseID == 21)
        {
            string name = "Part II - Testing Table::removeColumn after insert";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
                               "COMP2012H", 28, "Rm 5583", 100.0);
            table.insertRecord({"Name"}, "COMP1021");
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

            table.removeColumn("Passing Rate");

            table.print();
        }
        else if (caseID == 22)
        {
            string name = "Part II - Testing Table::updateRecords";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
                               "COMP2012H", 28, "Rm 5583", 100.0);
            table.insertRecord({"Name"}, "COMP1021");
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

            table.updateRecords(table.get<string>("Name") != "COMP2012H", "Blended Mode", true);
            table.updateRecords(table.get<string>("Name") == "COMP1021", "Num. Of Enrollment", 1200);

            table.print();
        }
        else if (caseID == 23)
        {
            string name = "Part II - Testing Table::removeRecords";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            table.insertRecord({"Name", "Passing Rate"}, "COMP1021", 90.5);
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");
            table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
                               "COMP2012H", 28, "Rm 5583", 100.0);

            table.removeRecords(table.get<double>("Passing Rate") < 95.5);

            table.print();
        }
        else if (caseID == 24)
        {
            string name = "Part II - Testing Table::operator[]";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("Courses");
            table.setupColumn("Name", (string) "");
            table.setupColumn("Room", (string) "N/A");
            table.setupColumn("Num. Of Enrollment", 0);
            table.setupColumn("Passing Rate", 0.0);
            table.setupColumn("Blended Mode", false);

            table.insertRecord({"Name", "Passing Rate"}, "COMP1021", 90.5);
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");
            table.insertRecord({"Name", "Num. Of Enrollment", "Room", "Passing Rate"},
                               "COMP2012H", 28, "Rm 5583", 100.0);
            table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room"}, false, "COMP3711", 89.3, "LTL");

            table[!table.get<bool>("Blended Mode") && table.get<double>("Passing Rate") > 90.0].print();
        }
        else if (caseID == 25)
        {
            string name = "Part II - Testing Table::limit";
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
            table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}, false, "COMP3711", 89.3, "LTL", 181);
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");
            table.limit(3).print();
            Table table2 = table;
            table2.limit(10).print();
        }
        else if (caseID == 26)
        {
            string name = "Part II - Testing Table::limit";
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
            table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}, false, "COMP3711", 89.3, "LTL", 181);
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

            table.skip(2).print();
        }
        else if (caseID == 27)
        {
            string name = "Part II - Testing Table::limit";
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
            table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}, false, "COMP3711", 89.3, "LTL", 181);
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

            table.select({"Passing Rate", "Name"}).print();
        }
        else if (caseID == 28)
        {
            string name = "Part II - Testing Table::alias";
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
            table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}, false, "COMP3711", 89.3, "LTL", 181);
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

            table.alias("More Courses").print();
        }
        else if (caseID == 29)
        {
            string name = "Part II - Testing Table::renameColumn";
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
            table.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}, false, "COMP3711", 89.3, "LTL", 181);
            table.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

            table.renameColumn({"Name", "Blended Mode"}, {"Course Code", "Mixed Mode"}).print();
        }
        else if (caseID == 30)
        {
            string name = "Part II - Testing Table::operator+";
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

            Table table2("More Courses");
            table2.setupColumn("Name", (string) "");
            table2.setupColumn("Room", (string) "N/A");
            table2.setupColumn("Num. Of Enrollment", 0);
            table2.setupColumn("Passing Rate", 0.0);
            table2.setupColumn("Blended Mode", false);

            table2.insertRecord({"Blended Mode", "Name", "Passing Rate", "Room", "Num. Of Enrollment"}, false, "COMP3711", 89.3, "LTL", 181);
            table2.insertRecord({"Blended Mode", "Name"}, true, "COMP3111");

            (table2 + table).print();
        }
        else if (caseID == 99)
        {
            string name = "TEST TEST TEST";
            cout << IDX << caseID << NAME << name << endl
                 << LINE << endl;

            Table table("TESTER");
            cout << LINE << endl;
            table.print();
            cout << "empty table printed" << endl;

            table.setupColumn("string", (string) "N/A");
            table.setupColumn("bool", true);
            table.setupColumn("double", 0.123);
            table.setupColumn("int", 0);
            cout << LINE << endl;
            table.print();
            cout << "table with 4 columns printed" << endl;

            table.insertRecord({"string", "bool", "double", "int"}, "COMP2012H", false, 100.0, 28);
            table.insertRecord({"string", "bool", "double", "int"}, "COMP1021", true, 90.5, 1200);
            table.insertRecord({"string", "bool", "double", "int"}, "COMP3111", false, 89.3, 181);

            cout << LINE << endl;
            table.print();

            table.updateRecords(table.get<string>("string") == "COMP1021", "int", 10000);
            table.updateRecords(table.get<double>("double") < 90.0, "bool", false);
            table.updateRecords(table.get<double>("double") > 90.0, "bool", true);
            table.print();

            table.sortBy("int").print();
            table.sortBy("string").print();
        }
    }
}
