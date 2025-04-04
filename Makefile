CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# קבצי המקור
SRC = Graph.cpp Algorithms.cpp Queue.cpp PriorityQueue.cpp UnionFind.cpp
OBJ = $(SRC:.cpp=.o)

# קבצי קלט
MAIN = Main.cpp
TEST = test.cpp

# הפלטים
MAIN_OUT = graph_demo
TEST_OUT = graph_test

# ברירת מחדל: קומפילציה ל-Main
Main: $(OBJ) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $(MAIN_OUT) $(OBJ) $(MAIN)

test: $(OBJ) $(TEST)
	$(CXX) $(CXXFLAGS) -o $(TEST_OUT) $(OBJ) $(TEST)

valgrind: test Main
	-valgrind --leak-check=full --track-origins=yes ./$(TEST_OUT)
	-valgrind --leak-check=full --track-origins=yes ./$(MAIN_OUT)


clean:
	rm -f *.o $(MAIN_OUT) $(TEST_OUT)
