#include "Graph.h"
#include <iostream>
#include <stdexcept>

namespace graph {

//בנאי הגרף - מקצה מקום לזיכרון עבור רשימת שכנים ומערך גודל לכל קודקוד
Graph::Graph(int numVertices){
    this->numVertices = numVertices;
    adjacencyList = new Neighbor*[numVertices]; // שינוי כאן
    listSizes = new int[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjacencyList[i] = nullptr;
        listSizes[i] = 0;
    }
}

//דסטרקטור - משחרר את כל הזיכרון שהוקצה
Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i)
        delete[] adjacencyList[i];
    delete[] adjacencyList;
    delete[] listSizes;
}

//פונקציה להוספת קשת בין שני קודקודים (דו-כיוונית)
void Graph::addEdge(int src, int dst, int weight) {
    addToList(src, dst, weight);
    addToList(dst, src, weight); // כי הגרף לא מכוון
}

//פונקציה להסרת קשת בין שני קודקודים
void Graph::removeEdge(int src, int dst) {
    if (!edgeExists(src, dst))
        throw std::runtime_error("Edge does not exist.");
    removeFromList(src, dst);
    removeFromList(dst, src);
}

//פונקציה להדפסת מבנה הגרף (לצורך בדיקה)
void Graph::print_graph() const {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ": ";
        for (int j = 0; j < listSizes[i]; ++j)
            std::cout << "(" << adjacencyList[i][j].id << ", w=" << adjacencyList[i][j].weight << ") ";
        std::cout << std::endl;
    }
}

//inner methods - מעכשיו
void Graph::addToList(int vertex, int neighbor, int weight) {
    Neighbor* newList = new Neighbor[listSizes[vertex] + 1]; //מקצים עוד מקום בשביל ה neighbor
    for (int i = 0; i < listSizes[vertex]; ++i)
        newList[i] = adjacencyList[vertex][i];  //מעתיקים את השכנים הקיימים כבר למערך החדש
    newList[listSizes[vertex]].id = neighbor; //מוסיפים את neigbor - קודקוד נוסף - יעד
    newList[listSizes[vertex]].weight = weight; //מוסיפים את המשקל של הקשת
    delete[] adjacencyList[vertex]; //אין צורך במידע של הישן יותר
    adjacencyList[vertex] = newList; // מעדכנים את הישן במידע של החדש
    listSizes[vertex]++; //מעדכנים את מס' השכנים של הקודקוד
}

void Graph::removeFromList(int vertex, int neighbor) {
    int index = -1;
    for (int i = 0; i < listSizes[vertex]; ++i) {
        if (adjacencyList[vertex][i].id == neighbor) { // משווים לפי מזהה קודקוד
            index = i;
            break;
        }
    }
    if (index == -1) return;
    for (int i = index; i < listSizes[vertex] - 1; ++i)
        adjacencyList[vertex][i] = adjacencyList[vertex][i + 1]; // מזיזים את השכנים אחורה
    listSizes[vertex]--;
}

bool Graph::edgeExists(int vertex, int neighbor) const {
    for (int i = 0; i < listSizes[vertex]; ++i)
        if (adjacencyList[vertex][i].id == neighbor)
            return true;
    return false;
}

}
