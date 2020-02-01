
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string.h>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

typedef struct {
    string StartVertex;
    string EndVertex;
    int weight;
}Edge;

class EdgeListGraph
{
    private:
        unordered_map<string, int>  VertexList;
        vector<Edge> EdgeList;
        int numVertices, count;
    public:
        EdgeListGraph(int Max);
        void insert_edge(string startV, string endV, int cost);
        void Display_edges();
        void Find_adjacent(string vertex);
        int Get_numvertices();
};

class AdjMatrixGraph
{
    private:
        int numVertices, numedges;
        bool **adjMat;
        unordered_map<string, int>  VertexList;
    public:
        AdjMatrixGraph(const int Vertex_Count);
        ~AdjMatrixGraph();
        void Insert_edge(string startV, string endV);
        void Display();
};


class AdjListGraph
{
private:
    int numVertices, numedges;
    unordered_map< string, list <pair<string, int>> > AdjList;

public:
    AdjListGraph(int vcount, int ecount);
    //~AdjListGraph();

    void Insert_edge(string vs, string ve, int w);
    void Display();

};



#endif /*_GRAPH_H_ */