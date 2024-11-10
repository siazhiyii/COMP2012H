#include <iostream>
#include "excel.h"

using namespace std;

int main() {
    cout << "==== Part 1 Launch a Excel workbook ====" << endl;
    Excel excel;
    cout << endl;
    cout << "==== Part 2 Open a sheet ====" << endl;
    Sheet* sheet1 = excel.open_sheet();
    cout << endl;

    cout << "==== Part 3 Navigate on sheet history ====" << endl;
    sheet1->redo();
    sheet1->undo();
    sheet1->update("Set A1 to Haha");
    sheet1->update("Set D4 to Bobo");
    sheet1->undo();
    sheet1->undo();
    cout << endl;
    
    cout << "==== Part 4 Use another sheet ====" << endl;
    Sheet* sheet2 = excel.open_sheet();
    sheet2->update("Set H3 to Alice");
    sheet2->undo();
    cout << endl;
    
    cout << "==== Part 5 Continue use on the other sheet ====" << endl;
    sheet1->redo();
    sheet1->update("Set B10 to Bob");
    sheet1->redo();
    sheet1->undo();
    sheet1->redo();
    cout << endl;

    cout << "==== Part 6 Close sheet ====" << endl;
    excel.close_sheet(sheet2);
    cout << endl;
    
    cout << "==== Part 7 Close Excel workbook ====" << endl;
}
