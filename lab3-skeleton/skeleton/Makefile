# Definition of variables
CPPFLAGS = -std=c++11 -Wall
SRCS = main.cpp datatype.cpp kioskArray.cpp	kioskLinkedList.cpp # TODO: Modify this so that you can compile a version with kioskLinkedList.cpp
OBJS = main.o datatype.o		# TODO: Modify this so that you can compile a version with kioskLinkedList.cpp
DEPS = $(SRCS:.cpp=.d)

all: kioskArray kioskLinkedList	# TODO: Modify this so that you can compile kioskLinkedList

# Rules: 
# target: dependencies
#   command used to create the target
kioskArray: $(OBJS) kioskArray.o # TODO: Compile kioskLinkedList, either in a separate rule or by utilizing pattern rule
	g++ $(CPPFLAGS) -o $@ $^



# To include the .d dependency files
-include $(DEPS)

# -MMD -MP creates the .d dependency files
.cpp.o:; g++ $(CPPFLAGS) -MMD -MP -c $<

clean:;	rm -f kioskArray kioskLinkedList *.exe $(OBJS) $(DEPS) kioskArray.o kioskLinkedList.o

.PRECIOUS: $(OBJS) kioskArray.o kioskLinkedList.o