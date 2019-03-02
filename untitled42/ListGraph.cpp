#include "ListGraph.h"
#include "algorithm"

ListGraph::~ListGraph() {

}

void ListGraph::AddEdge(int from, int to) {
    if (std::find(matrix[from].begin(), matrix[from].end(), to) == matrix[from].end()){
        matrix[from].push_back(to);
    }
}

int ListGraph::VerticesCount() const {
    return matrix.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    vertices = {matrix[vertex].begin(), matrix[vertex].end()};
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    for(int i=0; i<matrix.size();i++){
        if (std::find(matrix[i].begin(), matrix[i].end(), vertex) != matrix[i].end()){
            vertices.push_back(i);
        }
    }
}

ListGraph::ListGraph(int ver) :
    matrix(ver) {}

ListGraph::ListGraph(const ListGraph &other) :
    matrix(other.matrix) {}

ListGraph::ListGraph(const IGraph *other): ListGraph(other->VerticesCount()) {
    for (int i = 0; i < other->VerticesCount(); ++i) {
        std::vector<int> vertices;
        other->GetNextVertices(i, vertices);
        for (int j = 0; j < vertices.size(); ++j) {
            AddEdge(i, vertices[j]);
        }
    }
}

