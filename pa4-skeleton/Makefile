CC = g++
CPPFLAGS = -std=c++14 -g
SRCS = main.cpp employee.cpp employee_system.cpp command_parser.cpp
SRCS_TST = main_test.cpp employee.cpp employee_system.cpp
OBJS = $(SRCS:.cpp=.o)
OBJS_TST = $(SRCS_TST:.cpp=.o)
DEPS = $(OBJS:.o=.d)
DEPS_TST = $(OBJS_TST:.o=.d)

ifneq ($(OS), Windows_NT)
RM = -rm
ifeq ($(shell uname), Linux)
# Enable AddressSanitizer and UndefinedBehaviorSanitizer on Linux
CPPFLAGS += -fsanitize=address,undefined
endif
else
RM = -del
endif

pa4: $(OBJS)
	$(CC) -o $@ $^ $(CPPFLAGS)

pa4_test: $(OBJS_TST)
	$(CC) -o $@ $^ $(CPPFLAGS)

# To include the .d dependency files
-include $(DEPS) $(DEPS_TST)

%.o: %.cpp
	$(CC) -MMD -MP -c -o $@ $< $(CPPFLAGS)

clean:
	$(RM) -f *.o *.d pa4 pa4_test pa4.exe pa4_test.exe