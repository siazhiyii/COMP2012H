/**
 * @file excel.h
 * @brief Excel class and related constant declarations and definitions.
 *
 * This file declares and defines a Excel class.
 * TODO:
 *   This file is completed. You need to finish the member functions defined in
 *   excel.cpp
 */

#ifndef __EXCEL_H__
#define __EXCEL_H__
#include "sheet.h"
#include <vector>

/**
 * The Excel class with basic operations
 * you can do with a Excel workbook.
 */
class Excel {
    private:
        //All currently opened sheets.
        vector<Sheet*> sheets;
    
    public:
        //Constructor.
        Excel();

        //Destructor.
        ~Excel();                   //TODO: Finish definition.

        //Create a sheet, add to sheets and return its address.
        Sheet* open_sheet();               //TODO: Finish definition.

        //close the sheet pointed by sheet.
        void close_sheet(Sheet* sheet);

        //return the address of the sheet with specified id.
        //return nullptr if not find.
        Sheet* get_sheet(int id);          //TODO: Finish definition
};

#endif //__EXCEL_H__
