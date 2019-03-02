#ifndef UNTITLED42_SETGRAPH_H
#define UNTITLED42_SETGRAPH_H


#include "unordered_set"
#include "IGraph.h"
#include "iostream"
#include "vector"
#include "algorithm"

class SetGraph : public IGraph{
private:

    std::vector<std::unordered_set<int>> matrix;

public:

    SetGraph(const IGraph*);

    SetGraph(int ver);

    SetGraph(const SetGraph& other);

    ~SetGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
};


#endif //UNTITLED42_SETGRAPH_H
