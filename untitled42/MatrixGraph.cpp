#include "MatrixGraph.h"
#include "iostream"
#include "vector"

MatrixGraph::MatrixGraph(const IGraph *other): MatrixGraph(other->VerticesCount()) {
    for (int i = 0; i < other->VerticesCount(); ++i) {
        std::vector<int> vertices;
        other->GetNextVertices(i, vertices);
        for (int j = 0; j < vertices.size(); ++j) {
            AddEdge(i, vertices[j]);
        }
    }
}

MatrixGraph::MatrixGraph(int ver) :
        vertnumb(ver) , matrix(ver, std::vector<bool>( ver , false )){}

MatrixGraph::MatrixGraph(const MatrixGraph& other) :
        vertnumb(other.vertnumb) , matrix(other.matrix) {}

MatrixGraph::~MatrixGraph() {}

void MatrixGraph::AddEdge(int from, int to) {
    matrix[from][to]= true;
}

int MatrixGraph::VerticesCount() const {
    return vertnumb;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    for(int i=0; i<vertnumb;i++) {
        if(matrix[vertex][i] == true){
            vertices.push_back(i);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    for(int i=0; i<vertnumb;i++) {
        if(matrix[i][vertex] == true){
            vertices.push_back(i);
        }
    }
}
