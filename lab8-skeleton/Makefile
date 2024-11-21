CPPFLAGS = -std=c++11

# List all your object files here
OBJECTS = main.o

all: main.exe

main.exe: $(OBJECTS)
	g++ -o $@ $(CPPFLAGS) $(OBJECTS)

# This pattern will create a .o file for each .cpp file
%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

AVLTree.h: AVLTree.tpp

HashTable.h: HashTable.tpp

clean:
	del *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
