#include "ArcGraph.h"

ArcGraph::ArcGraph(int ver) :
    vertNumb(ver) {}

ArcGraph::ArcGraph(const ArcGraph &other) :
    matrix(other.matrix) {}

ArcGraph::ArcGraph(const IGraph *other): ArcGraph(other->VerticesCount()){
    for (int i = 0; i < other->VerticesCount(); ++i) {
        std::vector<int> vertices;
        other->GetNextVertices(i, vertices);
        for (int j = 0; j < vertices.size(); ++j) {
            AddEdge(i, vertices[j]);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    for(int i=0; i<matrix.size();i++) {
        if (matrix[i].first == from && matrix[i].second == to) return;
    }
        matrix.push_back(std::pair<int,int>(from, to));
}

int ArcGraph::VerticesCount() const {
    return vertNumb;
}

void ArcGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i].first == vertex) vertices.push_back(matrix[i].second);
    }
}

void ArcGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i].second == vertex) vertices.push_back(matrix[i].first);
    }
}
