# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# Source files and object files
SRCS = Tree.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Tree.h Student.h TreeNode.h

# Binary name
BIN = tree

# Default target
all: $(BIN)

# Build binary
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(BIN)

# Build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and binary
clean:
	rm -f $(OBJS) $(BIN)
