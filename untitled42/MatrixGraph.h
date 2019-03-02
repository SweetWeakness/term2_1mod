#ifndef UNTITLED42_MATRIXGRAPH_H
#define UNTITLED42_MATRIXGRAPH_H

#include "IGraph.h"
class MatrixGraph : public IGraph {
private:

    int vertnumb;

    std::vector<std::vector<bool>> matrix;

public:

    MatrixGraph(const IGraph*);

    MatrixGraph(int ver);

    MatrixGraph(const MatrixGraph& other);

    ~MatrixGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
};


#endif //UNTITLED42_MATRIXGRAPH_H
