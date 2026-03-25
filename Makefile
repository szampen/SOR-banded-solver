CXX = g++
CXXFLAGS = -Wall -std=c++17 -O3 -Iinclude

TARGET = sol_solver
SRCS = src/main.cpp src/SORSolver.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

test: all
	./$(TARGET) < data/file1.in
	./$(TARGET) < data/file2.in

.PHONY: all clean test