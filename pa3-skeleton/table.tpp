#include <iostream>
using namespace std;

// helper functions

void Table::setupColumnsBasedOnOrder(Table &differenceTable, const std::string *colKeyList, int sizeColKeyList) const
{

    for (int i = 0; i < getTotalNumCols(); ++i)
    {
        std::string key = colKeyList[i];
        if (this->getCol<std::string>(key) != nullptr)
        {
            differenceTable.setupColumn<std::string>(key, this->getCol<std::string>(key)->get_default_value());
        }
        else if (this->getCol<int>(key) != nullptr)
        {
            differenceTable.setupColumn<int>(key, this->getCol<int>(key)->get_default_value());
        }
        else if (this->getCol<double>(key) != nullptr)
        {
            differenceTable.setupColumn<double>(key, this->getCol<double>(key)->get_default_value());
        }
        else if (this->getCol<bool>(key) != nullptr)
        {
            differenceTable.setupColumn<bool>(key, this->getCol<bool>(key)->get_default_value());
        }
    }
}

int Table::getNumRecords() const
{
    return num_rows;
}

void Table::setNumRecords(int numRecords)
{
    num_rows = numRecords;
}

template <typename T>
bool Table::removeColTyped(std::string key)
{
    // get set of col and num of col for type T
    Column<T> **&cols = this->getColSet<T>();
    int &numCols = this->getNumCol<T>();

    for (int i = 0; i < numCols; ++i)
    {
        if (cols[i]->key() == key)
        { // find matching key
            // remove col and reduce num col
            delete cols[i];
            for (int j = i; j < numCols - 1; ++j)
            { // shift
                cols[j] = cols[j + 1];
            }
            --numCols;

            // resize the array
            Column<T> **newCols = new Column<T> *[numCols];
            for (int k = 0; k < numCols; ++k)
            {
                newCols[k] = cols[k];
            }
            delete[] cols;
            cols = newCols;

            // remove the key from colKeyList
            int totalCols = getTotalNumCols();
            int index = -1;
            for (int m = 0; m < totalCols + 1; ++m)
            {
                if (colKeyList[m] == key)
                {
                    index = m; // get the index of the key to remove
                    break;
                }
            }

            if (index != -1)
            {
                // create a new array with one less slot
                std::string *newColKeyList = new std::string[totalCols];
                for (int m = 0, n = 0; m < totalCols + 1; ++m)
                {
                    if (m != index)
                    {
                        newColKeyList[n++] = colKeyList[m];
                    }
                }

                delete[] colKeyList;
                colKeyList = newColKeyList;
            }

            return true;
        }
    }
    return false;
}

// end helper functions

// begin getColSet

// Specialization for int
template <>
Column<int> **&Table::getColSet<int>()
{
    return int_cols;
}

template <>
Column<int> **Table::getColSet<int>() const
{
    return int_cols;
}

// Specialization for double
template <>
Column<double> **&Table::getColSet<double>()
{
    return double_cols;
}

template <>
Column<double> **Table::getColSet<double>() const
{
    return double_cols;
}

// Specialization for bool
template <>
Column<bool> **&Table::getColSet<bool>()
{
    return bool_cols;
}

template <>
Column<bool> **Table::getColSet<bool>() const
{
    return bool_cols;
}

// Specialization for string
template <>
Column<std::string> **&Table::getColSet<std::string>()
{
    return str_cols;
}

template <>
Column<std::string> **Table::getColSet<std::string>() const
{
    return str_cols;
}

// end getColSet

// begin getNumCol

// Specialization for int
template <>
int &Table::getNumCol<int>()
{
    return num_int_cols;
}

template <>
int Table::getNumCol<int>() const
{
    return num_int_cols;
}

// Specialization for double
template <>
int &Table::getNumCol<double>()
{
    return num_double_cols;
}

template <>
int Table::getNumCol<double>() const
{
    return num_double_cols;
}

// Specialization for bool
template <>
int &Table::getNumCol<bool>()
{
    return num_bool_cols;
}

template <>
int Table::getNumCol<bool>() const
{
    return num_bool_cols;
}

// Specialization for string
template <>
int &Table::getNumCol<std::string>()
{
    return num_str_cols;
}

template <>
int Table::getNumCol<std::string>() const
{
    return num_str_cols;
}

// end getNumCol

template <typename T>
Column<T> *Table::getCol(std::string key) const
{
    // get set of cols of type T and get num of cols of type T
    Column<T> **cols = this->getColSet<T>();
    int numCols = this->getNumCol<T>();

    for (int i = 0; i < numCols; ++i) // find col matching key
    {
        if (cols[i]->key() == key)
        {
            return cols[i];
        }
    }
    return nullptr; // if no such key exists, return nullptr
}

// constructor
Table::Table(std::string name)
{
    this->name = name;
}

template <typename T>
void Table::setupColumn(std::string key, const T &default_value)
{
    // get the col set and num of col for type T
    Column<T> **&cols = this->getColSet<T>();
    int &numCols = this->getNumCol<T>();

    // create new col
    Column<T> *newCol = new Column<T>(key, default_value);

    // pad the new column with the default value
    int numRecords = getNumRecords();
    for (int i = 0; i < numRecords; ++i)
    {
        newCol->addEntry(default_value);
    }

    // make new col set with new col
    // this updates the col set
    Column<T> **newCols = new Column<T> *[numCols + 1];
    for (int i = 0; i < numCols; ++i)
    {
        newCols[i] = cols[i];
    }
    newCols[numCols] = newCol;

    // update the col num and col key list
    delete[] cols;
    cols = newCols;
    ++numCols;

    int totalCols = getTotalNumCols();
    std::string *newColKeyList = new std::string[totalCols];

    if (colKeyList != nullptr)
    {
        for (int i = 0; i < totalCols - 1; ++i)
        {
            newColKeyList[i] = colKeyList[i];
        }
    }
    delete[] colKeyList;
    newColKeyList[totalCols - 1] = key;
    colKeyList = newColKeyList;
}

void Table::removeColumn(std::string key)
{
    // remove the column for each type
    if (removeColTyped<int>(key))
        return;
    if (removeColTyped<double>(key))
        return;
    if (removeColTyped<bool>(key))
        return;
    if (removeColTyped<std::string>(key))
        return;
}

// If no such key exists, the function should throw the error by throw invalid_argument("Key \"" + key + "\" not found in table!")
template <typename T>
const Column<T> &Table::get(std::string key) const // retrieves col of specified key
{
    Column<T> **cols = this->getColSet<T>();
    int numCols = this->getNumCol<T>();

    for (int i = 0; i < numCols; ++i)
    {
        if (cols[i]->key() == key)
        {
            return *cols[i]; // return the column if key is found
        }
    }
    throw std::invalid_argument("Key \"" + key + "\" not found in table!");
}

Table &Table::operator=(const Table &other)
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < num_int_cols; ++i)
    {
        delete int_cols[i];
    }
    delete[] int_cols;

    for (int i = 0; i < num_double_cols; ++i)
    {
        delete double_cols[i];
    }
    delete[] double_cols;

    for (int i = 0; i < num_bool_cols; ++i)
    {
        delete bool_cols[i];
    }
    delete[] bool_cols;

    for (int i = 0; i < num_str_cols; ++i)
    {
        delete str_cols[i];
    }
    delete[] str_cols;

    name = other.name;
    num_int_cols = other.num_int_cols;
    num_double_cols = other.num_double_cols;
    num_bool_cols = other.num_bool_cols;
    num_str_cols = other.num_str_cols;
    num_rows = other.num_rows;

    int_cols = new Column<int> *[num_int_cols];
    for (int i = 0; i < num_int_cols; ++i)
    {
        int_cols[i] = new Column<int>(*other.int_cols[i]);
        for (int j = 0; j < num_rows; ++j)
        {
            (*int_cols[i])[j] = (*other.int_cols[i])[j];
        }
    }

    double_cols = new Column<double> *[num_double_cols];
    for (int i = 0; i < num_double_cols; ++i)
    {
        double_cols[i] = new Column<double>(*other.double_cols[i]);
        for (int j = 0; j < num_rows; ++j)
        {
            (*double_cols[i])[j] = (*other.double_cols[i])[j];
        }
    }

    bool_cols = new Column<bool> *[num_bool_cols];
    for (int i = 0; i < num_bool_cols; ++i)
    {
        bool_cols[i] = new Column<bool>(*other.bool_cols[i]);
        for (int j = 0; j < num_rows; ++j)
        {
            (*bool_cols[i])[j] = (*other.bool_cols[i])[j];
        }
    }

    str_cols = new Column<std::string> *[num_str_cols];
    for (int i = 0; i < num_str_cols; ++i)
    {
        str_cols[i] = new Column<std::string>(*other.str_cols[i]);
        for (int j = 0; j < num_rows; ++j)
        {
            (*str_cols[i])[j] = (*other.str_cols[i])[j];
        }
    }

    delete[] colKeyList;

    if (other.colKeyList)
    {
        colKeyList = new std::string[getTotalNumCols()];
        for (int i = 0; i < getTotalNumCols(); ++i)
        {
            colKeyList[i] = other.colKeyList[i];
        }
    }
    else
    {
        colKeyList = nullptr;
    }

    return *this;
}

Table::Table(const Table &other)
{
    for (int i = 0; i < num_int_cols; ++i)
    {
        delete int_cols[i];
    }
    delete[] int_cols;

    for (int i = 0; i < num_double_cols; ++i)
    {
        delete double_cols[i];
    }
    delete[] double_cols;

    for (int i = 0; i < num_bool_cols; ++i)
    {
        delete bool_cols[i];
    }
    delete[] bool_cols;

    for (int i = 0; i < num_str_cols; ++i)
    {
        delete str_cols[i];
    }
    delete[] str_cols;

    name = other.name;
    num_int_cols = other.num_int_cols;
    num_double_cols = other.num_double_cols;
    num_bool_cols = other.num_bool_cols;
    num_str_cols = other.num_str_cols;
    num_rows = other.num_rows;

    int_cols = new Column<int> *[num_int_cols];
    for (int i = 0; i < num_int_cols; ++i)
    {
        int_cols[i] = new Column<int>(*other.int_cols[i]);
        for (int j = 0; j < num_rows; ++j)
        {
            (*int_cols[i])[j] = (*other.int_cols[i])[j];
        }
    }

    double_cols = new Column<double> *[num_double_cols];
    for (int i = 0; i < num_double_cols; ++i)
    {
        double_cols[i] = new Column<double>(*other.double_cols[i]);
        for (int j = 0; j < num_rows; ++j)
        {
            (*double_cols[i])[j] = (*other.double_cols[i])[j];
        }
    }

    bool_cols = new Column<bool> *[num_bool_cols];
    for (int i = 0; i < num_bool_cols; ++i)
    {
        bool_cols[i] = new Column<bool>(*other.bool_cols[i]);
        for (int j = 0; j < num_rows; ++j)
        {
            (*bool_cols[i])[j] = (*other.bool_cols[i])[j];
        }
    }

    str_cols = new Column<std::string> *[num_str_cols];
    for (int i = 0; i < num_str_cols; ++i)
    {
        str_cols[i] = new Column<std::string>(*other.str_cols[i]);
        for (int j = 0; j < num_rows; ++j)
        {
            (*str_cols[i])[j] = (*other.str_cols[i])[j];
        }
    }

    delete[] colKeyList;

    if (other.colKeyList)
    {
        colKeyList = new std::string[getTotalNumCols()];
        for (int i = 0; i < getTotalNumCols(); ++i)
        {
            colKeyList[i] = other.colKeyList[i];
        }
    }
    else
    {
        colKeyList = nullptr;
    }
}

Table::~Table()
{
    for (int i = 0; i < num_str_cols; ++i)
    {
        delete str_cols[i];
    }
    delete[] str_cols;

    for (int i = 0; i < num_int_cols; ++i)
    {
        delete int_cols[i];
    }
    delete[] int_cols;

    for (int i = 0; i < num_double_cols; ++i)
    {
        delete double_cols[i];
    }
    delete[] double_cols;

    for (int i = 0; i < num_bool_cols; ++i)
    {
        delete bool_cols[i];
    }
    delete[] bool_cols;

    delete[] colKeyList;
}

template <typename T>
void Table::insertEntryForColumn(std::string key, const T &field)
{
    Column<T> *chosenCol = getCol<T>(key);
    chosenCol->addEntry(field);
    if (chosenCol->size() > this->getNumRecords())
    {
        this->setNumRecords(chosenCol->size());
    }
}

int Table::postInsertEntry()
{
    int numRecords = getNumRecords();

    for (int i = 0; i < num_int_cols; ++i)
    {
        while (int_cols[i]->size() < numRecords)
        {
            int_cols[i]->addEntry(int_cols[i]->get_default_value());
        }
    }

    for (int i = 0; i < num_double_cols; ++i)
    {
        while (double_cols[i]->size() < numRecords)
        {
            double_cols[i]->addEntry(double_cols[i]->get_default_value());
        }
    }

    for (int i = 0; i < num_bool_cols; ++i)
    {
        while (bool_cols[i]->size() < numRecords)
        {
            bool_cols[i]->addEntry(bool_cols[i]->get_default_value());
        }
    }

    for (int i = 0; i < num_str_cols; ++i)
    {
        while (str_cols[i]->size() < numRecords)
        {
            str_cols[i]->addEntry(str_cols[i]->get_default_value());
        }
    }

    return numRecords;
}

template <typename T>
void Table::updateRecords(const Column<bool> &filter, std::string key, const T &new_value)
{
    if (filter.size() != this->getNumRecords())
    {
        throw std::invalid_argument("Filter size does not match the number of records in the table.");
    }

    Column<T> *chosenCol = getCol<T>(key);
    if (!chosenCol)
    {
        return;
    }

    for (int j = 0; j < filter.size(); ++j)
    {
        if (filter[j])
        {
            chosenCol->updateEntry(j, new_value);
        }
    }
}

void Table::removeRecords(const Column<bool> &filter)
{
    if (filter.size() != getNumRecords())
    {
        throw std::invalid_argument("Filter size does not match the number of records in the table.");
    }

    int *indicesToRemove = new int[filter.size()];
    int count = 0;

    for (int i = 0; i < filter.size(); ++i)
    {
        if (filter[i])
        {
            indicesToRemove[count++] = i;
        }
    }

    for (int i = count - 1; i >= 0; --i)
    {
        int index = indicesToRemove[i];
        for (int j = 0; j < num_str_cols; ++j)
        {
            str_cols[j]->removeEntry(index);
        }

        for (int j = 0; j < num_int_cols; ++j)
        {
            int_cols[j]->removeEntry(index);
        }

        for (int j = 0; j < num_double_cols; ++j)
        {
            double_cols[j]->removeEntry(index);
        }

        for (int j = 0; j < num_bool_cols; ++j)
        {
            bool_cols[j]->removeEntry(index);
        }

        num_rows--;
    }

    delete[] indicesToRemove;
}

Table Table::operator[](const Column<bool> &filter) const
{
    if (filter.size() != getNumRecords())
    {
        throw std::invalid_argument("Filter size does not match the number of records in the table.");
    }

    Table newTable(this->name);

    setupColumnsBasedOnOrder(newTable, colKeyList, getTotalNumCols());

    // for (int i = 0; i < num_str_cols; ++i)
    // {
    //     newTable.setupColumn<std::string>(str_cols[i]->key(), str_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_int_cols; ++i)
    // {
    //     newTable.setupColumn<int>(int_cols[i]->key(), int_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_double_cols; ++i)
    // {
    //     newTable.setupColumn<double>(double_cols[i]->key(), double_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_bool_cols; ++i)
    // {
    //     newTable.setupColumn<bool>(bool_cols[i]->key(), bool_cols[i]->get_default_value());
    // }

    for (int i = 0; i < filter.size(); ++i)
    {
        if (filter[i])
        {
            for (int j = 0; j < num_str_cols; ++j)
            {
                newTable.insertEntryForColumn<std::string>(str_cols[j]->key(), (*str_cols[j])[i]);
            }
            for (int j = 0; j < num_int_cols; ++j)
            {
                newTable.insertEntryForColumn<int>(int_cols[j]->key(), (*int_cols[j])[i]);
            }
            for (int j = 0; j < num_double_cols; ++j)
            {
                newTable.insertEntryForColumn<double>(double_cols[j]->key(), (*double_cols[j])[i]);
            }
            for (int j = 0; j < num_bool_cols; ++j)
            {
                newTable.insertEntryForColumn<bool>(bool_cols[j]->key(), (*bool_cols[j])[i]);
            }
        }
    }

    return newTable;
}

Table Table::limit(int numLimit) const
{
    if (numLimit >= num_rows)
    {
        return Table(*this);
    }

    Table newTable(this->name);

    setupColumnsBasedOnOrder(newTable, colKeyList, getTotalNumCols());

    // for (int i = 0; i < num_str_cols; ++i)
    // {
    //     newTable.setupColumn<std::string>(str_cols[i]->key(), str_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_int_cols; ++i)
    // {
    //     newTable.setupColumn<int>(int_cols[i]->key(), int_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_double_cols; ++i)
    // {
    //     newTable.setupColumn<double>(double_cols[i]->key(), double_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_bool_cols; ++i)
    // {
    //     newTable.setupColumn<bool>(bool_cols[i]->key(), bool_cols[i]->get_default_value());
    // }

    for (int i = 0; i < numLimit; ++i)
    {

        for (int j = 0; j < num_str_cols; ++j)
        {
            newTable.insertEntryForColumn<std::string>(str_cols[j]->key(), (*str_cols[j])[i]);
        }
        for (int j = 0; j < num_int_cols; ++j)
        {
            newTable.insertEntryForColumn<int>(int_cols[j]->key(), (*int_cols[j])[i]);
        }
        for (int j = 0; j < num_double_cols; ++j)
        {
            newTable.insertEntryForColumn<double>(double_cols[j]->key(), (*double_cols[j])[i]);
        }
        for (int j = 0; j < num_bool_cols; ++j)
        {
            newTable.insertEntryForColumn<bool>(bool_cols[j]->key(), (*bool_cols[j])[i]);
        }
    }

    return newTable;
}

Table Table::skip(int numSkip) const
{
    if (numSkip >= num_rows)
    {
        return Table(this->name);
    }

    Table skippedTable(this->name);

    setupColumnsBasedOnOrder(skippedTable, colKeyList, getTotalNumCols());

    // for (int i = 0; i < num_str_cols; ++i)
    // {
    //     skippedTable.setupColumn<std::string>(str_cols[i]->key(), str_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_int_cols; ++i)
    // {
    //     skippedTable.setupColumn<int>(int_cols[i]->key(), int_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_double_cols; ++i)
    // {
    //     skippedTable.setupColumn<double>(double_cols[i]->key(), double_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_bool_cols; ++i)
    // {
    //     skippedTable.setupColumn<bool>(bool_cols[i]->key(), bool_cols[i]->get_default_value());
    // }

    for (int i = numSkip; i < num_rows; ++i)
    {
        for (int j = 0; j < num_str_cols; ++j)
        {
            skippedTable.insertEntryForColumn<std::string>(str_cols[j]->key(), (*str_cols[j])[i]);
        }
        for (int j = 0; j < num_int_cols; ++j)
        {
            skippedTable.insertEntryForColumn<int>(int_cols[j]->key(), (*int_cols[j])[i]);
        }
        for (int j = 0; j < num_double_cols; ++j)
        {
            skippedTable.insertEntryForColumn<double>(double_cols[j]->key(), (*double_cols[j])[i]);
        }
        for (int j = 0; j < num_bool_cols; ++j)
        {
            skippedTable.insertEntryForColumn<bool>(bool_cols[j]->key(), (*bool_cols[j])[i]);
        }
    }

    return skippedTable;
}

template <int arrSize>
Table Table::select(const std::string (&selectKeys)[arrSize]) const
{
    Table result(this->name);

    for (int i = 0; i < arrSize; ++i)
    {
        const std::string &key = selectKeys[i];

        for (int j = 0; j < num_str_cols; ++j)
        {
            if (str_cols[j]->key() == key)
            {
                result.setupColumn<std::string>(key, str_cols[j]->get_default_value());
                break;
            }
        }

        for (int j = 0; j < num_int_cols; ++j)
        {
            if (int_cols[j]->key() == key)
            {
                result.setupColumn<int>(key, int_cols[j]->get_default_value());
                break;
            }
        }

        for (int j = 0; j < num_bool_cols; ++j)
        {
            if (bool_cols[j]->key() == key)
            {
                result.setupColumn<bool>(key, bool_cols[j]->get_default_value());
                break;
            }
        }

        for (int j = 0; j < num_double_cols; ++j)
        {
            if (double_cols[j]->key() == key)
            {
                result.setupColumn<double>(key, double_cols[j]->get_default_value());
                break;
            }
        }
    }

    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < arrSize; ++j)
        {
            const std::string &key = selectKeys[j];

            for (int k = 0; k < num_str_cols; ++k)
            {
                if (str_cols[k]->key() == key)
                {
                    result.insertEntryForColumn<std::string>(key, (*str_cols[k])[i]);
                    break;
                }
            }

            for (int k = 0; k < num_int_cols; ++k)
            {
                if (int_cols[k]->key() == key)
                {
                    result.insertEntryForColumn<int>(key, (*int_cols[k])[i]);
                    break;
                }
            }

            // Copy bool column data
            for (int k = 0; k < num_bool_cols; ++k)
            {
                if (bool_cols[k]->key() == key)
                {
                    result.insertEntryForColumn<bool>(key, (*bool_cols[k])[i]);
                    break;
                }
            }

            for (int k = 0; k < num_double_cols; ++k)
            {
                if (double_cols[k]->key() == key)
                {
                    result.insertEntryForColumn<double>(key, (*double_cols[k])[i]);
                    break;
                }
            }
        }
    }

    delete[] result.colKeyList;

    result.colKeyList = new std::string[arrSize];
    for (int i = 0; i < arrSize; ++i)
    {
        result.colKeyList[i] = selectKeys[i];
    }

    return result;
}

Table Table::alias(std::string newName) const
{
    Table aliasedTable(newName);

    setupColumnsBasedOnOrder(aliasedTable, colKeyList, getTotalNumCols());

    // for (int i = 0; i < num_str_cols; ++i)
    // {
    //     aliasedTable.setupColumn<std::string>(str_cols[i]->key(), str_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_int_cols; ++i)
    // {
    //     aliasedTable.setupColumn<int>(int_cols[i]->key(), int_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_double_cols; ++i)
    // {
    //     aliasedTable.setupColumn<double>(double_cols[i]->key(), double_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_bool_cols; ++i)
    // {
    //     aliasedTable.setupColumn<bool>(bool_cols[i]->key(), bool_cols[i]->get_default_value());
    // }

    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_str_cols; ++j)
        {
            aliasedTable.insertEntryForColumn<std::string>(str_cols[j]->key(), (*str_cols[j])[i]);
        }
        for (int j = 0; j < num_int_cols; ++j)
        {
            aliasedTable.insertEntryForColumn<int>(int_cols[j]->key(), (*int_cols[j])[i]);
        }
        for (int j = 0; j < num_double_cols; ++j)
        {
            aliasedTable.insertEntryForColumn<double>(double_cols[j]->key(), (*double_cols[j])[i]);
        }
        for (int j = 0; j < num_bool_cols; ++j)
        {
            aliasedTable.insertEntryForColumn<bool>(bool_cols[j]->key(), (*bool_cols[j])[i]);
        }
    }

    return aliasedTable;
}

template <int arrSize>
Table Table::renameColumn(const std::string (&oriName)[arrSize], const std::string (&newName)[arrSize]) const
{
    Table result(this->name);

    std::string *oriNames = new std::string[arrSize];
    std::string *newNames = new std::string[arrSize];
    for (int i = 0; i < arrSize; ++i)
    {
        oriNames[i] = oriName[i];
        newNames[i] = newName[i];
    }

    for (int i = 0; i < num_str_cols; ++i)
    {
        std::string key = str_cols[i]->key();
        for (int j = 0; j < arrSize; ++j)
        {
            if (key == oriNames[j])
            {
                key = newNames[j];
                break;
            }
        }
        result.setupColumn<std::string>(key, str_cols[i]->get_default_value());
    }

    for (int i = 0; i < num_int_cols; ++i)
    {
        std::string key = int_cols[i]->key();
        for (int j = 0; j < arrSize; ++j)
        {
            if (key == oriNames[j])
            {
                key = newNames[j];
                break;
            }
        }
        result.setupColumn<int>(key, int_cols[i]->get_default_value());
    }

    for (int i = 0; i < num_bool_cols; ++i)
    {
        std::string key = bool_cols[i]->key();
        for (int j = 0; j < arrSize; ++j)
        {
            if (key == oriNames[j])
            {
                key = newNames[j];
                break;
            }
        }
        result.setupColumn<bool>(key, bool_cols[i]->get_default_value());
    }

    for (int i = 0; i < num_double_cols; ++i)
    {
        std::string key = double_cols[i]->key();
        for (int j = 0; j < arrSize; ++j)
        {
            if (key == oriNames[j])
            {
                key = newNames[j];
                break;
            }
        }
        result.setupColumn<double>(key, double_cols[i]->get_default_value());
    }

    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_str_cols; ++j)
        {
            std::string key = str_cols[j]->key();
            for (int k = 0; k < arrSize; ++k)
            {
                if (key == oriNames[k])
                {
                    key = newNames[k];
                    break;
                }
            }
            result.insertEntryForColumn<std::string>(key, (*str_cols[j])[i]);
        }

        for (int j = 0; j < num_int_cols; ++j)
        {
            std::string key = int_cols[j]->key();
            for (int k = 0; k < arrSize; ++k)
            {
                if (key == oriNames[k])
                {
                    key = newNames[k];
                    break;
                }
            }
            result.insertEntryForColumn<int>(key, (*int_cols[j])[i]);
        }

        for (int j = 0; j < num_bool_cols; ++j)
        {
            std::string key = bool_cols[j]->key();
            for (int k = 0; k < arrSize; ++k)
            {
                if (key == oriNames[k])
                {
                    key = newNames[k];
                    break;
                }
            }
            result.insertEntryForColumn<bool>(key, (*bool_cols[j])[i]);
        }

        for (int j = 0; j < num_double_cols; ++j)
        {
            std::string key = double_cols[j]->key();
            for (int k = 0; k < arrSize; ++k)
            {
                if (key == oriNames[k])
                {
                    key = newNames[k];
                    break;
                }
            }
            result.insertEntryForColumn<double>(key, (*double_cols[j])[i]);
        }
    }
    delete[] result.colKeyList;
    result.colKeyList = new std::string[getTotalNumCols()];
    for (int i = 0; i < getTotalNumCols(); ++i)
    {
        std::string key = colKeyList[i];
        for (int j = 0; j < arrSize; ++j)
        {
            if (key == oriNames[j])
            {
                key = newNames[j];
                break;
            }
        }
        result.colKeyList[i] = key;
    }

    delete[] oriNames;
    delete[] newNames;

    return result;
}

Table Table::operator+(const Table &other) const
{
    if (!this->checkCompatible(other))
    {
        throw std::invalid_argument("Table not compatible during concatenation!");
    }

    Table concatenatedTable(this->name);

    setupColumnsBasedOnOrder(concatenatedTable, colKeyList, getTotalNumCols());

    // for (int i = 0; i < num_str_cols; ++i)
    // {
    //     concatenatedTable.setupColumn<std::string>(str_cols[i]->key(), str_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_int_cols; ++i)
    // {
    //     concatenatedTable.setupColumn<int>(int_cols[i]->key(), int_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_double_cols; ++i)
    // {
    //     concatenatedTable.setupColumn<double>(double_cols[i]->key(), double_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_bool_cols; ++i)
    // {
    //     concatenatedTable.setupColumn<bool>(bool_cols[i]->key(), bool_cols[i]->get_default_value());
    // }

    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_str_cols; ++j)
        {
            concatenatedTable.insertEntryForColumn<std::string>(str_cols[j]->key(), (*str_cols[j])[i]);
        }
        for (int j = 0; j < num_int_cols; ++j)
        {
            concatenatedTable.insertEntryForColumn<int>(int_cols[j]->key(), (*int_cols[j])[i]);
        }
        for (int j = 0; j < num_double_cols; ++j)
        {
            concatenatedTable.insertEntryForColumn<double>(double_cols[j]->key(), (*double_cols[j])[i]);
        }
        for (int j = 0; j < num_bool_cols; ++j)
        {
            concatenatedTable.insertEntryForColumn<bool>(bool_cols[j]->key(), (*bool_cols[j])[i]);
        }
    }

    for (int i = 0; i < other.num_rows; ++i)
    {
        for (int j = 0; j < other.num_str_cols; ++j)
        {
            concatenatedTable.insertEntryForColumn<std::string>(other.str_cols[j]->key(), (*other.str_cols[j])[i]);
        }
        for (int j = 0; j < other.num_int_cols; ++j)
        {
            concatenatedTable.insertEntryForColumn<int>(other.int_cols[j]->key(), (*other.int_cols[j])[i]);
        }
        for (int j = 0; j < other.num_double_cols; ++j)
        {
            concatenatedTable.insertEntryForColumn<double>(other.double_cols[j]->key(), (*other.double_cols[j])[i]);
        }
        for (int j = 0; j < other.num_bool_cols; ++j)
        {
            concatenatedTable.insertEntryForColumn<bool>(other.bool_cols[j]->key(), (*other.bool_cols[j])[i]);
        }
    }

    return concatenatedTable;
}

bool Table::compare(int a, int b, const std::string &key, bool descending) const
{
    if (this->getCol<int>(key) != nullptr)
    {
        return descending ? (*this->getCol<int>(key))[a] > (*this->getCol<int>(key))[b]
                          : (*this->getCol<int>(key))[a] <= (*this->getCol<int>(key))[b];
    }
    else if (this->getCol<double>(key) != nullptr)
    {
        return descending ? (*this->getCol<double>(key))[a] > (*this->getCol<double>(key))[b]
                          : (*this->getCol<double>(key))[a] <= (*this->getCol<double>(key))[b];
    }
    else if (this->getCol<bool>(key) != nullptr)
    {
        return descending ? (*this->getCol<bool>(key))[a] > (*this->getCol<bool>(key))[b]
                          : (*this->getCol<bool>(key))[a] <= (*this->getCol<bool>(key))[b];
    }
    else if (this->getCol<std::string>(key) != nullptr)
    {
        return descending ? (*this->getCol<std::string>(key))[a] > (*this->getCol<std::string>(key))[b]
                          : (*this->getCol<std::string>(key))[a] <= (*this->getCol<std::string>(key))[b];
    }
    return false;
}
int Table::partition(int *indices, int low, int high, const std::string &key, bool descending) const
{
    int pivot = indices[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (compare(indices[j], pivot, key, descending))
        {
            ++i;
            int temp = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;
        }
    }
    int temp = indices[i + 1];
    indices[i + 1] = indices[high];
    indices[high] = temp;
    return i + 1;
}

void Table::quicksort(int *indices, int low, int high, const std::string &key, bool descending) const
{
    if (low < high)
    {
        int pi = partition(indices, low, high, key, descending);
        quicksort(indices, low, pi - 1, key, descending);
        quicksort(indices, pi + 1, high, key, descending);
    }
}
Table Table::sortBy(std::string key, bool descending) const
{
    if (this->getCol<int>(key) == nullptr && this->getCol<double>(key) == nullptr &&
        this->getCol<bool>(key) == nullptr && this->getCol<std::string>(key) == nullptr)
    {
        return *this;
    }

    Table sortedTable(this->name);

    setupColumnsBasedOnOrder(sortedTable, colKeyList, getTotalNumCols());

    int *indices = new int[num_rows];
    for (int i = 0; i < num_rows; ++i)
    {
        indices[i] = i;
    }

    quicksort(indices, 0, num_rows - 1, key, descending);

    for (int i = 0; i < num_rows; ++i)
    {
        int index = indices[i];
        for (int j = 0; j < num_str_cols; ++j)
        {
            sortedTable.insertEntryForColumn<std::string>(str_cols[j]->key(), (*str_cols[j])[index]);
        }
        for (int j = 0; j < num_int_cols; ++j)
        {
            sortedTable.insertEntryForColumn<int>(int_cols[j]->key(), (*int_cols[j])[index]);
        }
        for (int j = 0; j < num_double_cols; ++j)
        {
            sortedTable.insertEntryForColumn<double>(double_cols[j]->key(), (*double_cols[j])[index]);
        }
        for (int j = 0; j < num_bool_cols; ++j)
        {
            sortedTable.insertEntryForColumn<bool>(bool_cols[j]->key(), (*bool_cols[j])[index]);
        }
    }

    delete[] indices;
    return sortedTable;
}

Table Table::operator-(const Table &other) const
{
    if (!this->checkCompatible(other))
    {
        throw std::invalid_argument("Table not compatible during difference!");
    }

    Table differenceTable(this->name);

    setupColumnsBasedOnOrder(differenceTable, colKeyList, getTotalNumCols());

    // for (int i = 0; i < num_str_cols; ++i)
    // {
    //     differenceTable.setupColumn<std::string>(str_cols[i]->key(), str_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_int_cols; ++i)
    // {
    //     differenceTable.setupColumn<int>(int_cols[i]->key(), int_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_double_cols; ++i)
    // {
    //     differenceTable.setupColumn<double>(double_cols[i]->key(), double_cols[i]->get_default_value());
    // }
    // for (int i = 0; i < num_bool_cols; ++i)
    // {
    //     differenceTable.setupColumn<bool>(bool_cols[i]->key(), bool_cols[i]->get_default_value());
    // }

    for (int i = 0; i < num_rows; ++i)
    {
        bool existsInOther = false;
        for (int j = 0; j < other.num_rows; ++j)
        {
            bool match = true;
            for (int k = 0; k < num_str_cols; ++k)
            {
                if ((*str_cols[k])[i] != (*other.str_cols[k])[j])
                {
                    match = false;
                    break;
                }
            }
            for (int k = 0; k < num_int_cols; ++k)
            {
                if ((*int_cols[k])[i] != (*other.int_cols[k])[j])
                {
                    match = false;
                    break;
                }
            }
            for (int k = 0; k < num_double_cols; ++k)
            {
                if ((*double_cols[k])[i] != (*other.double_cols[k])[j])
                {
                    match = false;
                    break;
                }
            }
            for (int k = 0; k < num_bool_cols; ++k)
            {
                if ((*bool_cols[k])[i] != (*other.bool_cols[k])[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                existsInOther = true;
                break;
            }
        }
        if (!existsInOther)
        {
            for (int k = 0; k < num_str_cols; ++k)
            {
                differenceTable.insertEntryForColumn<std::string>(str_cols[k]->key(), (*str_cols[k])[i]);
            }
            for (int k = 0; k < num_int_cols; ++k)
            {
                differenceTable.insertEntryForColumn<int>(int_cols[k]->key(), (*int_cols[k])[i]);
            }
            for (int k = 0; k < num_double_cols; ++k)
            {
                differenceTable.insertEntryForColumn<double>(double_cols[k]->key(), (*double_cols[k])[i]);
            }
            for (int k = 0; k < num_bool_cols; ++k)
            {
                differenceTable.insertEntryForColumn<bool>(bool_cols[k]->key(), (*bool_cols[k])[i]);
            }
        }
    }

    return differenceTable;
}

Table Table::operator*(const Table &other) const
{
    if (this->name == other.name)
    {
        throw std::invalid_argument("Tables having same name while product!");
    }

    std::string newTableName = this->name + "_" + other.name;
    Table productTable(newTableName);

    // setupColumnsBasedOnOrder(productTable, colKeyList, getTotalNumCols());

    for (int i = 0; i < num_str_cols; ++i)
    {
        productTable.setupColumn<std::string>(this->name + "." + str_cols[i]->key(), str_cols[i]->get_default_value());
    }
    for (int i = 0; i < num_int_cols; ++i)
    {
        productTable.setupColumn<int>(this->name + "." + int_cols[i]->key(), int_cols[i]->get_default_value());
    }
    for (int i = 0; i < num_double_cols; ++i)
    {
        productTable.setupColumn<double>(this->name + "." + double_cols[i]->key(), double_cols[i]->get_default_value());
    }
    for (int i = 0; i < num_bool_cols; ++i)
    {
        productTable.setupColumn<bool>(this->name + "." + bool_cols[i]->key(), bool_cols[i]->get_default_value());
    }

    for (int i = 0; i < other.num_str_cols; ++i)
    {
        productTable.setupColumn<std::string>(other.name + "." + other.str_cols[i]->key(), other.str_cols[i]->get_default_value());
    }
    for (int i = 0; i < other.num_int_cols; ++i)
    {
        productTable.setupColumn<int>(other.name + "." + other.int_cols[i]->key(), other.int_cols[i]->get_default_value());
    }
    for (int i = 0; i < other.num_double_cols; ++i)
    {
        productTable.setupColumn<double>(other.name + "." + other.double_cols[i]->key(), other.double_cols[i]->get_default_value());
    }
    for (int i = 0; i < other.num_bool_cols; ++i)
    {
        productTable.setupColumn<bool>(other.name + "." + other.bool_cols[i]->key(), other.bool_cols[i]->get_default_value());
    }

    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < other.num_rows; ++j)
        {
            for (int k = 0; k < num_str_cols; ++k)
            {
                productTable.insertEntryForColumn<std::string>(this->name + "." + str_cols[k]->key(), (*str_cols[k])[i]);
            }
            for (int k = 0; k < num_int_cols; ++k)
            {
                productTable.insertEntryForColumn<int>(this->name + "." + int_cols[k]->key(), (*int_cols[k])[i]);
            }
            for (int k = 0; k < num_double_cols; ++k)
            {
                productTable.insertEntryForColumn<double>(this->name + "." + double_cols[k]->key(), (*double_cols[k])[i]);
            }
            for (int k = 0; k < num_bool_cols; ++k)
            {
                productTable.insertEntryForColumn<bool>(this->name + "." + bool_cols[k]->key(), (*bool_cols[k])[i]);
            }

            for (int k = 0; k < other.num_str_cols; ++k)
            {
                productTable.insertEntryForColumn<std::string>(other.name + "." + other.str_cols[k]->key(), (*other.str_cols[k])[j]);
            }
            for (int k = 0; k < other.num_int_cols; ++k)
            {
                productTable.insertEntryForColumn<int>(other.name + "." + other.int_cols[k]->key(), (*other.int_cols[k])[j]);
            }
            for (int k = 0; k < other.num_double_cols; ++k)
            {
                productTable.insertEntryForColumn<double>(other.name + "." + other.double_cols[k]->key(), (*other.double_cols[k])[j]);
            }
            for (int k = 0; k < other.num_bool_cols; ++k)
            {
                productTable.insertEntryForColumn<bool>(other.name + "." + other.bool_cols[k]->key(), (*other.bool_cols[k])[j]);
            }
        }
    }

    return productTable;
}

// //
// Table Table::operator*(const Table &other) const
// {
//     if (this->name == other.name)
//     {
//         throw std::invalid_argument("Tables having same name while product!");
//     }

//     std::string newTableName = this->name + "_" + other.name;
//     Table productTable(newTableName);

//     for (int i = 0; i < num_str_cols; ++i)
//     {
//         productTable.setupColumn<std::string>(this->name + "." + str_cols[i]->key(), str_cols[i]->get_default_value());
//     }
//     for (int i = 0; i < num_int_cols; ++i)
//     {
//         productTable.setupColumn<int>(this->name + "." + int_cols[i]->key(), int_cols[i]->get_default_value());
//     }
//     for (int i = 0; i < num_double_cols; ++i)
//     {
//         productTable.setupColumn<double>(this->name + "." + double_cols[i]->key(), double_cols[i]->get_default_value());
//     }
//     for (int i = 0; i < num_bool_cols; ++i)
//     {
//         productTable.setupColumn<bool>(this->name + "." + bool_cols[i]->key(), bool_cols[i]->get_default_value());
//     }

//     for (int i = 0; i < other.num_str_cols; ++i)
//     {
//         productTable.setupColumn<std::string>(other.name + "." + other.str_cols[i]->key(), other.str_cols[i]->get_default_value());
//     }
//     for (int i = 0; i < other.num_int_cols; ++i)
//     {
//         productTable.setupColumn<int>(other.name + "." + other.int_cols[i]->key(), other.int_cols[i]->get_default_value());
//     }
//     for (int i = 0; i < other.num_double_cols; ++i)
//     {
//         productTable.setupColumn<double>(other.name + "." + other.double_cols[i]->key(), other.double_cols[i]->get_default_value());
//     }
//     for (int i = 0; i < other.num_bool_cols; ++i)
//     {
//         productTable.setupColumn<bool>(other.name + "." + other.bool_cols[i]->key(), other.bool_cols[i]->get_default_value());
//     }

//     for (int i = 0; i < num_rows; ++i)
//     {
//         for (int j = 0; j < other.num_rows; ++j)
//         {
//             for (int k = 0; k < num_str_cols; ++k)
//             {
//                 productTable.insertEntryForColumn<std::string>(this->name + "." + str_cols[k]->key(), (*str_cols[k])[i]);
//             }
//             for (int k = 0; k < num_int_cols; ++k)
//             {
//                 productTable.insertEntryForColumn<int>(this->name + "." + int_cols[k]->key(), (*int_cols[k])[i]);
//             }
//             for (int k = 0; k < num_double_cols; ++k)
//             {
//                 productTable.insertEntryForColumn<double>(this->name + "." + double_cols[k]->key(), (*double_cols[k])[i]);
//             }
//             for (int k = 0; k < num_bool_cols; ++k)
//             {
//                 productTable.insertEntryForColumn<bool>(this->name + "." + bool_cols[k]->key(), (*bool_cols[k])[i]);
//             }

//             for (int k = 0; k < other.num_str_cols; ++k)
//             {
//                 productTable.insertEntryForColumn<std::string>(other.name + "." + other.str_cols[k]->key(), (*other.str_cols[k])[j]);
//             }
//             for (int k = 0; k < other.num_int_cols; ++k)
//             {
//                 productTable.insertEntryForColumn<int>(other.name + "." + other.int_cols[k]->key(), (*other.int_cols[k])[j]);
//             }
//             for (int k = 0; k < other.num_double_cols; ++k)
//             {
//                 productTable.insertEntryForColumn<double>(other.name + "." + other.double_cols[k]->key(), (*other.double_cols[k])[j]);
//             }
//             for (int k = 0; k < other.num_bool_cols; ++k)
//             {
//                 productTable.insertEntryForColumn<bool>(other.name + "." + other.bool_cols[k]->key(), (*other.bool_cols[k])[j]);
//             }
//         }
//     }

//     return productTable;
// }
