# Definition of variables
CPPFLAGS = -std=c++11 -Wall
SRCS = main.cpp coffee.cpp ingredient.cpp shop.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
EXE = lab4

# Rules: 
# target: dependencies
#   command used to create the target
$(EXE): $(OBJS) 
	g++ $(CPPFLAGS) -o $@ $(OBJS)

# To include the .d dependency files
-include $(DEPS)

# -MMD -MP creates the .d dependency files
.cpp.o:; g++ $(CPPFLAGS) -MMD -MP -c $<

clean:;	rm -f *.exe $(EXE) $(OBJS) $(DEPS)