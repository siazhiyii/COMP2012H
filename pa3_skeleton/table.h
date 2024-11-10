#include "column.h"
#include <sstream>

class Table
{

private:
    // The name of the current Table
    std::string name;

    // Stores the key (i.e. name) of the columns in this Table
    // This list defines the order and the columns (left to right) being printed when print() is being called
    std::string *colKeyList = nullptr;

    // Dynamic sized arrays to store the columns of different type.
    // Where their capacity should exactly equal to the number of columns of that data type.
    // Here, we use double pointers but not single pointer because there is no default constructor for the Column class.
    // e.g. Column<int>* ptr = new Column<int>[10]; doesn't work since it requires the default constructor.
    Column<std::string> **str_cols = nullptr;
    Column<int> **int_cols = nullptr;
    Column<bool> **bool_cols = nullptr;
    Column<double> **double_cols = nullptr;

    // Number of columns of certain column type
    int num_str_cols = 0, num_int_cols = 0, num_bool_cols = 0, num_double_cols = 0;

    // Number of records in the table currently
    int num_rows = 0;

    inline int getTotalNumCols() const { return num_str_cols + num_int_cols + num_bool_cols + num_double_cols; }

    // ======= Feel free to add helper functions here =========

    int getNumRecords() const;

    std::string* addColKey(const std::string& key);

    std::string* removeColKey(const std::string& key);

    void setNumRecords(int numRecords);

    template <typename T>
    bool removeColTyped(std::string key);

    // =========== End of adding helper functions ================

    // ========= TODO ===========

    template <typename T>
    Column<T> **&getColSet();

    template <typename T>
    Column<T> **getColSet() const;

    template <typename T>
    int &getNumCol();

    template <typename T>
    int getNumCol() const;

    template <typename T>
    Column<T> *getCol(std::string key) const;

    template <typename T>
    void insertEntryForColumn(std::string key, const T &field);

    int postInsertEntry();

public:
    Table(std::string name);

    Table &operator=(const Table &other);

    Table(const Table &other);

    ~Table();

    template <typename T>
    void setupColumn(std::string key, const T &default_value);

    void removeColumn(std::string key);

    template <typename T>
    const Column<T> &get(std::string key) const;

    Table operator[](const Column<bool> &filter) const;

    template <typename T>
    void updateRecords(const Column<bool> &filter, std::string key, const T &new_value);

    void removeRecords(const Column<bool> &filter);

    Table limit(int numLimit) const;

    Table skip(int numSkip) const;

    template <int arrSize>
    Table select(const string (&selectKeys)[arrSize]) const;

    Table alias(string newName) const;

    template <int arrSize>
    Table renameColumn(const string (&oriName)[arrSize], const string (&newName)[arrSize]) const;

    Table operator+(const Table &other) const;

    // =========== Bonus Task ============

    Table sortBy(std::string key, bool descending = false) const;

    Table operator*(const Table &other) const;

    Table operator-(const Table &other) const;

    // =========== Helper functions given from now on =============

    template <typename T, typename... Ts>
    int insertRecord(const std::string *keys, T field, Ts... fs)
    {
        insertEntryForColumn(*keys, field);
        return insertRecord(keys + 1, fs...);
    }

    template <typename... Ts>
    int insertRecord(const std::string *keys, const char *field, Ts... fs)
    {
        insertEntryForColumn(*keys, (std::string)field);
        return insertRecord(keys + 1, fs...);
    }

    template <typename T>
    int insertRecord(const std::string *keys, T field)
    {
        insertEntryForColumn(*keys, field);
        return postInsertEntry();
    }

    int insertRecord(const std::string *keys, const char *field)
    {
        insertEntryForColumn(*keys, (std::string)field);
        return postInsertEntry();
    }

    template <typename... Ts>
    int insertRecord(const std::string (&keys)[], Ts... fs)
    {
        return insertRecord((const std::string *)keys, fs...);
    }

private:
    template <typename T>
    bool checkCompatibleTyped(const Table &other) const
    {
        int thisNumCols = this->getNumCol<T>();
        int otherNumCols = other.getNumCol<T>();
        if (thisNumCols != otherNumCols)
            return false;
        if (thisNumCols == 0)
            return true;

        Column<T> **thisCol = this->getColSet<T>();
        Column<T> **otherCol = other.getColSet<T>();
        string arr1[thisNumCols];
        string arr2[otherNumCols];

        for (int i = 0; i < thisNumCols; i++)
        {
            arr1[i] = thisCol[i]->key();
        }
        for (int i = 0; i < otherNumCols; i++)
        {
            arr2[i] = otherCol[i]->key();
        }

        for (int i = 0; i < thisNumCols - 1; ++i)
        {
            for (int j = 0; j < thisNumCols - i - 1; ++j)
            {
                if (arr1[j] > arr1[j + 1])
                {
                    swap(arr1[j], arr1[j + 1]);
                }
            }
        }
        for (int i = 0; i < otherNumCols - 1; ++i)
        {
            for (int j = 0; j < otherNumCols - i - 1; ++j)
            {
                if (arr2[j] > arr2[j + 1])
                {
                    swap(arr2[j], arr2[j + 1]);
                }
            }
        }

        for (int i = 0; i < thisNumCols; ++i)
        {
            if (arr1[i] != arr2[i])
                return false;
        }

        return true;
    }

    bool checkCompatible(const Table &other) const
    {
        return checkCompatibleTyped<int>(other) && checkCompatibleTyped<double>(other) &&
               checkCompatibleTyped<string>(other) && checkCompatibleTyped<bool>(other);
    }

public:
    void print() const
    {

        using namespace std;

        cout << "Table: " << this->name << endl;

        if (getTotalNumCols() == 0)
        {
            cout << "+--+" << endl;
            cout << "|  |" << endl;
            cout << "+--+" << endl;
            return;
        }

        enum TYPE
        {
            STRING,
            INT,
            BOOL,
            DOUBLE
        };
        TYPE t_arr[getTotalNumCols()];
        void *t_ptr[getTotalNumCols()];
        int maxPrintLen[getTotalNumCols()];
        for (int i = 0; i < getTotalNumCols(); i++)
        {
            if (t_ptr[i] = getCol<string>(colKeyList[i]))
            {
                t_arr[i] = STRING;
                Column<string> *curCol = getCol<string>(colKeyList[i]);
                maxPrintLen[i] = curCol->key().length();
                for (int j = 0; j < curCol->size(); j++)
                {
                    stringstream ss;
                    ss << (*curCol)[j];
                    maxPrintLen[i] = maxPrintLen[i] > ss.str().length() ? maxPrintLen[i] : ss.str().length();
                }
            }
            else if (t_ptr[i] = getCol<int>(colKeyList[i]))
            {
                t_arr[i] = INT;
                Column<int> *curCol = getCol<int>(colKeyList[i]);
                maxPrintLen[i] = curCol->key().length();
                for (int j = 0; j < curCol->size(); j++)
                {
                    stringstream ss;
                    ss << (*curCol)[j];
                    maxPrintLen[i] = maxPrintLen[i] > ss.str().length() ? maxPrintLen[i] : ss.str().length();
                }
            }
            else if (t_ptr[i] = getCol<bool>(colKeyList[i]))
            {
                t_arr[i] = BOOL;
                maxPrintLen[i] = getCol<bool>(colKeyList[i])->key().length();
                if (maxPrintLen[i] < 5)
                    maxPrintLen[i] = 5;
            }
            else if (t_ptr[i] = getCol<double>(colKeyList[i]))
            {
                t_arr[i] = DOUBLE;
                Column<double> *curCol = getCol<double>(colKeyList[i]);
                maxPrintLen[i] = curCol->key().length();
                for (int j = 0; j < curCol->size(); j++)
                {
                    stringstream ss;
                    ss << (*curCol)[j];
                    maxPrintLen[i] = maxPrintLen[i] > ss.str().length() ? maxPrintLen[i] : ss.str().length();
                }
            }
        }

        int barLen = 0;
        for (int i = 0; i < getTotalNumCols(); i++)
            barLen += maxPrintLen[i];
        barLen += getTotalNumCols() * 2;     // left/right space
        barLen += getTotalNumCols() + 1 - 2; // vertical bars - 2 vertices

        string hBar = string(barLen, '-');
        cout << "+" << hBar << "+" << endl;

        cout << "|";
        for (int i = 0; i < getTotalNumCols(); i++)
        {
            stringstream ss;
            ss << colKeyList[i];
            cout << " " << ss.str() << string(maxPrintLen[i] + 1 - ss.str().length(), ' ') << "|";
            cout.flush();
        }
        cout << endl;
        cout << "+" << hBar << "+" << endl;

        for (int i = 0; i < num_rows; i++)
        {
            cout << "|";
            for (int j = 0; j < getTotalNumCols(); j++)
            {
                stringstream ss;
                if (t_arr[j] == STRING)
                {
                    ss << (*((Column<string> *)t_ptr[j]))[i];
                }
                else if (t_arr[j] == INT)
                {
                    ss << (*((Column<int> *)t_ptr[j]))[i];
                }
                else if (t_arr[j] == DOUBLE)
                {
                    ss << (*((Column<double> *)t_ptr[j]))[i];
                }
                else if (t_arr[j] == BOOL)
                {
                    ss << boolalpha << (*((Column<bool> *)t_ptr[j]))[i];
                }
                cout << " " << ss.str() << string(maxPrintLen[j] + 1 - ss.str().length(), ' ') << "|";
            }
            cout << endl;
            cout << "+" << hBar << "+" << endl;
        }
    }
};

#include "table.tpp"