#ifndef UNTITLED42_LISTGRAPH_H
#define UNTITLED42_LISTGRAPH_H

#include "IGraph.h"
#include "iostream"
#include "vector"
#include <list>
#include "algorithm"

class ListGraph : public IGraph{
private:

    std::vector<std::list<int>> matrix;

public:

    ListGraph(const IGraph*);

    ListGraph(int ver);

    ListGraph(const ListGraph& other);

    ~ListGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
};


#endif //UNTITLED42_LISTGRAPH_H
