CPPFLAGS = -std=c++11 -g -fsanitize=leak,undefined,address

SRCS = main.cpp sheet.cpp excel.cpp
OBJS = $(SRCS:.cpp=.o)

all: lab6

lab6: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe lab6
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
