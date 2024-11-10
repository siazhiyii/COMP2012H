/**
 * @file sheet.h
 * @brief Sheet class and related alias declarations and definitions.
 *
 * This file declares and defines a Sheet class and aliases string as History type.
 * TODO:
 *   This file is completed. You need to finish the member functions defined in sheet.cpp
 */
#ifndef __SHEET_H__
#define __SHEET_H__
#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

using History = string;

/**
 * The Sheet class.
 */
class Sheet {
    private:
        //The id indicate this sheet.
        int id;

        //History stack keeps update history records in order allowing you to go
        //foward and backward on your history on this sheet.
        //Using list to support forward rather than actual stack.
        list<History> history_stack;

        //Iterator indicates position of your current history location in stack.
        list<History>::iterator current_status;

    public:
        //Construct a sheet with id.
        Sheet(int id);

        //Destructor
        ~Sheet();

        //return its id.
        int get_id() const;

        //Update a cell with the updateMessage given
        void update(History updateMessage);

        //Go to the next status you have since current one.
        void undo();

        //Go to the previous status you have before current one.
        void redo();
};

#endif //__SHEET_H__
