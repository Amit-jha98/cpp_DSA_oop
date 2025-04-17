# Compiler and Flags
CXX = g++
CXXFLAGS = -I"C:\Program Files\GCC\SFML-2.6.2\include" -std=c++17 -O2 -Wall -Wextra
LDFLAGS = -L"C:\Program Files\GCC\SFML-2.6.2\lib" -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lsfml-main

# Source and Output - Updated to point to the correct chess.cpp file
SRC = pong.cpp
OUT = pong.exe

# Default target
all: $(OUT)

# Build the executable
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

# Clean up generated files
.PHONY: clean
clean:
	del $(OUT)
