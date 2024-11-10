/**
 * @file excel.cpp
 * @brief Excel class member functions definitions
 *
 * This file defines following member functions of Excel:
 *   1. Excel::Excel:   the constructor.
 *   2. Excel::~Excel:  the destructor.
 *   3. Excel::open_sheet:  open a new sheet.
 *   4. Excel::close_sheet: close a sheet.
 *   5. Excel::get_sheet:   get the sheet by id.
 *
 *   TODO: You need to finish:
 *     1. Excel::~Excel
 *     2. Excel::open_sheet
 *     3. Excel::close_sheet
 *     4. Excel::get_sheet
 */

#include "excel.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

/**
 * Construct a Excel workbook.
 */
Excel::Excel() {
    cout << "Excel: You have opened a excel workbook." << endl; 
}

/**
 * Destruct the Excel workbook.
 *
 * TODO: Finish the code.
 * The function should output "Excel: You have closed the Excel workbook." in the end.
 */
Excel::~Excel() {

    // ========== TODO =========


}

/**
 * Create a new sheet.
 * Its id should be the number of sheets you currently have, start from 0.
 * Add a pointer of it to sheets.
 * Return this pointer for operations.
 *
 * TODO: Finish the code.
 */
Sheet* Excel::open_sheet() {
    
    // ========== TODO =========


}

/**
 * Close the sheet pointed by sheet.
 *
 * TODO: Finish the code.
 * If the function fails to find the sheet pointer in sheets, it should output "Excel: Cannot find this sheet for closing, something must be wrong!" and return
 * Otherwise, the function should output "Excel: Closing Sheet_ID", where ID is the id of the sheet.
 */
void Excel::close_sheet(Sheet* sheet) {

    // ========== TODO =========


}

/**
 * Get the sheet with specified id.
 * return its address if find.
 * return nullptr if not find.
 *
 * TODO: Finish the code.
 * If the function fails to find the sheet pointer in sheets, it should output "Excel: Cannot find the sheet during get, something must be wrong!" and return
 * Otherwise, the function should output "Excel: Getting Sheet_ID", where ID is the id of the sheet.
 */
Sheet* Excel::get_sheet(int id) {

    // ========== TODO =========

    
}
