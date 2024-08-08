# Define the compiler and the compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/Cellar/sfml/2.6.1/include

# Define the linker flags
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

# Define the target executable
TARGET = main

# Define the source files
SRC = $(wildcard *.cpp)

# Define the object files
OBJ = $(SRC:.cpp=.o)

# The first rule is the default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Rule to clean the build
clean:
	rm -f $(OBJ) $(TARGET)
