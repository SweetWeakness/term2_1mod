#ifndef UNTITLED42_ARCGRAPH_H
#define UNTITLED42_ARCGRAPH_H

#include "IGraph.h"

class ArcGraph : public IGraph{
private:

    std::vector<std::pair<int, int>> matrix;

    int vertNumb;

public:

    ArcGraph(int ver);

    ArcGraph(const ArcGraph &other);

    ArcGraph(const IGraph *other);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

};


#endif //UNTITLED42_ARCGRAPH_H
