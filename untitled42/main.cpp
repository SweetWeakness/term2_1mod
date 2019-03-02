#include "ListGraph.h"
#include "ArcGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

#include <iostream>

void _DFS(const IGraph &graph, int v, std::vector<int> &mark, std::vector<int> &in, std::vector<int> &out) {
    if (mark[v] != 0)
        return;
    mark[v] = 1;
    in.push_back(v);
    std::vector<int> next;
    graph.GetNextVertices(v, next);
    for (int n : next)
        _DFS(graph, n, mark, in, out);
    out.push_back(v);
}


void DFS(const IGraph &graph, std::vector<int> &in, std::vector<int> &out) {
    in.clear();
    out.clear();
    std::vector<int> mark(graph.VerticesCount(), 0);
    _DFS(graph, 0, mark, in, out);

}

int main() {
    ListGraph lg(4);
    lg.AddEdge(0, 1);
    lg.AddEdge(0, 2);
    lg.AddEdge(2, 1);
    lg.AddEdge(1, 3);
    lg.AddEdge(2, 3);
    std::vector<int> in, out;
    DFS(lg, in, out);

    std::cout << "LIN" << "\n";
    for (int v : in)
        std::cout << v << " ";

    std::cout << "LOUT" << "\n";
    for (int v : out)
        std::cout << v << " ";

    ArcGraph ag = &lg;
    DFS(ag, in, out);

    std::cout << "AIN" << "\n";
    for (int v : in)
        std::cout << v << " ";

    std::cout << "AOUT" << "\n";
    for (int v : out)
        std::cout << v << " ";

    MatrixGraph mg = &ag;
    DFS(lg, in, out);

    std::cout << "MIN" << "\n";
    for (int v : in)
        std::cout << v << " ";

    std::cout << "MOUT" << "\n";
    for (int v : out)
        std::cout << v << " ";

    SetGraph sg = &mg;
    DFS(sg, in, out);

    std::cout << "SIN" << "\n";
    for (int v : in)
        std::cout << v << " ";

    std::cout << "SOUT" << "\n";
    for (int v : out)
        std::cout << v << " ";



    return 0;
}