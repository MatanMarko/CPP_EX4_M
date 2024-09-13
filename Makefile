
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -g -I.

# SFML libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
MAIN_SRC = Main.cpp Complex.cpp
TEST_SRC = Test.cpp Complex.cpp

# Object files
MAIN_OBJ = Main.o Complex.o
TEST_OBJ = Test.o Complex.o

# Output executables
TARGET = tree
TEST_TARGET = test

# Default target to build both main executable and test executable
all: $(TARGET) $(TEST_TARGET)

# Rule to link object files to create the main executable
$(TARGET): $(MAIN_OBJ)
	$(CXX) $(MAIN_OBJ) -o $(TARGET) $(SFML_LIBS)

# Rule to link object files to create the test executable
$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(TEST_OBJ) -o $(TEST_TARGET) $(SFML_LIBS)

# Rule to compile Main.cpp to Main.o
Main.o: Main.cpp Tree.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

# Rule to compile Complex.cpp to Complex.o
Complex.o: Complex.cpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Complex.cpp -o Complex.o

# Rule to compile Test.cpp to Test.o
Test.o: Test.cpp Tree.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Test.cpp -o Test.o

# Clean up build files
clean:
	rm -f $(MAIN_OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)

# Declare 'all' and 'clean' as phony targets
.PHONY: all clean
