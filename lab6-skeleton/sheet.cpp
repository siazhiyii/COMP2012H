/**
 * @file sheet.cpp
 * @brief Sheet class member functions definitions
 *
 * This file defines following member functions of Sheet:
 *   1. Sheet::Sheet:      the constructor.
 *   2. Sheet::~Sheet:     the destructor.
 *   3. Sheet::get_id:   return the id of sheet.
 *   4. Sheet::update:     update the sheet.
 *   5. Sheet::undo:  go to the next status after the current one.
 *   6. Sheet::redo:  go to the previous status before the current one.
 *
 *   TODO: You need to finish:
 *     1. Sheet::update
 *     2. Sheet::undo
 *     3. Sheet::redo
 */
#include "sheet.h"


Sheet::Sheet(int id) {
    string prefix = "Sheet_" + to_string(id) + " Create: ";
    cout << prefix << "Hello!" << endl; 

    this->id = id;
    history_stack.push_back("The sheet is set as an empty sheet.");
    current_status = prev(history_stack.end());
}


Sheet::~Sheet() {
    string prefix = "Sheet_" + to_string(id) + " Close: ";
    cout << prefix << "Goodbye" << endl;
}


/**
 * Update the sheet with a update message.
 * Add update message to your stack.
 *
 * TODO: Finish the code.
 * Remember: There is no way to redo after an new update has performed.
 */
void Sheet::update(History updateMessage) {
    string prefix = "Sheet_" + to_string(id) + " Update: ";
    cout << prefix << updateMessage << endl; 

    // =========== TODO =================
    

}

/**
 * Undo to the previous status.
 *
 * TODO: Finish the code.
 * Make sure that your function outputs the same format as the sample output.
 */
void Sheet::undo() {
    string prefix = "Sheet_" + to_string(id) + " Undo: ";

    //=========== TODO ================


}

/**
 * Redo to the next status.
 *
 * TODO: Finish the code.
 * Make sure that your function outputs the same format as the sample output.
 */
void Sheet::redo() {
    string prefix = "Sheet_" + to_string(id) + " Redo: ";

    //=========== TODO =================
    

}

int Sheet::get_id() const {
    return id;
}
