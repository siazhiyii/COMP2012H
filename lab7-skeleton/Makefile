CPPFLAGS = -std=c++11

all: lab7

lab7: order_item.o order.o main.cpp
	g++ -o $@ $(CPPFLAGS) order_item.o order.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -rf *.o *.exe lab7
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
