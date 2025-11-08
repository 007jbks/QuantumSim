CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2


SRCS = qbit.cpp  main.cpp multistate.cpp gate.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = quantum_sim

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
