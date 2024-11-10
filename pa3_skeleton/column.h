#include <string>

template <typename T>
class Column {

    private:
        T* data;           // The dynamically allocated array to store the data
        int _size;         // The current size (i.e. num of elements) of this column
        int capacity;      // The capacity (i.e. max size possible) of this column
        T default_value;   // The default value of this column
        std::string _key;  // The key (i.e. name) of this column

    public:
        Column(std::string key, const T& default_value, int capacity = 2);

        Column<T>& operator=(const Column<T>& other);

        Column(const Column& other);

        ~Column();

        void addEntry(T field);

        void addDefault(int numOfEntry = 1);

        const T& operator[](int idx) const;

        T& operator[](int idx);

        void removeEntry(int idx);

        void updateEntry(int idx, const T& value);

        // Set the capacity as the sum of size
        Column<T> concat(const Column<T>& other) const;

        // Just set the capacity as the current size
        // May assume T || T / T && T must exist and it returns bool
        Column<bool> operator==(const T& comp) const;
        Column<bool> operator!=(const T& comp) const;
        Column<bool> operator<(const T& comp) const;
        Column<bool> operator<=(const T& comp) const;
        Column<bool> operator>(const T& comp) const;
        Column<bool> operator>=(const T& comp) const;
        
        Column<bool> operator==(const Column<T>& other) const;
        Column<bool> operator!=(const Column<T>& other) const;
        Column<bool> operator<(const Column<T>& other) const;
        Column<bool> operator<=(const Column<T>& other) const;
        Column<bool> operator>(const Column<T>& other) const;
        Column<bool> operator>=(const Column<T>& other) const;

        Column<bool> operator!() const;
        Column<bool> operator||(const Column<T>& other) const;
        Column<bool> operator&&(const Column<T>& other) const;

        Column<T> operator[](const Column<bool>& filter) const;
        

        // ======= Helper =========

        int size() const {return _size;}

        std::string key() const {return _key;}

        void rename(std::string newKey) {this->_key = newKey;}

        T get_default_value() const {return default_value;}

};

#include "column.tpp"