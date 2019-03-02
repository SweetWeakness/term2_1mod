#include "SetGraph.h"
#include "algorithm"

SetGraph::SetGraph(const IGraph *other): SetGraph(other->VerticesCount()) {
    for (int i = 0; i < other->VerticesCount(); ++i) {
        std::vector<int> vertices;
        other->GetNextVertices(i, vertices);
        for (int j = 0; j < vertices.size(); ++j) {
            AddEdge(i, vertices[j]);
        }
    }
}

SetGraph::SetGraph(int ver) :
    matrix(ver) {}

SetGraph::SetGraph(const SetGraph &other) :
    matrix(other.matrix) {}

SetGraph::~SetGraph() {

}

void SetGraph::AddEdge(int from, int to) {
        matrix[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return matrix.size();
}

void SetGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    vertices = {matrix[vertex].begin(), matrix[vertex].end()};
}

void SetGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    for(int i=0; i<matrix.size();i++){
        if (matrix[i].find(vertex) != matrix[i].end()){
            vertices.push_back(i);
        }
    }
}
