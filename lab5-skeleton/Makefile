CPPFLAGS = -std=c++11 -g

# List all your object files here
SRCS = main.cpp Student.cpp
OBJS = $(SRCS:.cpp=.o)

all: lab5

lab5: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

# This pattern will create a .o file for each .cpp file
%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
