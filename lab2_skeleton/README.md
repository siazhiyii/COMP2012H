# Instructions

Compile the numpy_lite code into a library file, and run the test code.

- For Linux:

```bash
cd src  # Change to the src directory

# Compile the code into libnumpylite.so dynamic library
g++ -g -fPIC --std=c++11  -shared numpy_lite.cpp -o libnumpylite.so

# Compile the test code into test executable, with proper linking
g++ -g numpy_lite_test.cpp -o test -L. -lnumpylite

# Run the test executable
./test
```

