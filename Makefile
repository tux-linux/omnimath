CC=gcc
CXX=g++
CFLAGS="-Wall"
TARGET=omnimath
all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CXX) $(CFLAGS) -o $(TARGET) $(TARGET).cpp
