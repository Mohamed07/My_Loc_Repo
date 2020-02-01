
#include "graph.h"
#include <iostream>

EdgeListGraph::EdgeListGraph(int max)
{
    this->EdgeList.assign(max, {"0","0",0});
    this->numVertices = 0;
    this->count = 0;
}
void EdgeListGraph::insert_edge(string startV, string endV, int cost)
{
    //Check if startV or endV do not exist in VertixList
    if(VertexList.find(startV) == VertexList.end())
    {
        VertexList[startV] = numVertices;
        numVertices += 1;
    }

    if (VertexList.find(endV) == VertexList.end())
    {
        VertexList[endV] = numVertices;
        numVertices += 1;
    }
    
    EdgeList[count].StartVertex = startV;
    EdgeList[count].EndVertex = endV;
    EdgeList[count].weight = cost;
    count += 1;
}

int EdgeListGraph::Get_numvertices()
{
    return this->numVertices;
}
void EdgeListGraph::Display_edges()
{
    for(auto e : EdgeList)
        cout << e.StartVertex << " --- " << e.EndVertex << "( " << e.weight << " )"<<"\n"; 
}

void EdgeListGraph::Find_adjacent(string vertex)
{
    if(VertexList.find(vertex) != VertexList.end())
    {
        for(auto v: EdgeList)
        {
            if(v.EndVertex == vertex)
                cout << vertex << " ---- " << v.StartVertex <<" ( " << v.weight <<" )\n";
            else if(v.StartVertex == vertex)
                cout << vertex << " ---- " << v.EndVertex <<" ( " << v.weight <<" )\n";
        }

    }
    else
    {
        cout << "Vertex not in Graph\n";
    }
    
}

AdjMatrixGraph::AdjMatrixGraph(const int V_count)
{
    this->numVertices = V_count;
    this->numedges = 0;
    this->adjMat = new bool*[V_count];

    for(auto i=0; i < V_count; i++)
    {
        this->adjMat[i] = new bool[V_count];

        memset(this->adjMat[i], false, V_count*sizeof(bool));
    }
}

void AdjMatrixGraph::Insert_edge(string startV, string endV)
{

    if(this->VertexList[startV] == 0)
        this->VertexList[startV] += 1 + this->numedges++;
    
    if(this->VertexList[endV] == 0)
        this->VertexList[endV] += 1 + this->numedges++;

    this->adjMat[this->VertexList[startV]-1][this->VertexList[endV]-1] = true;
    this->adjMat[this->VertexList[endV]-1][this->VertexList[startV]-1] = true;    
}


void AdjMatrixGraph::Display()
{
    cout << " ";
    for(auto v : this->VertexList)
        cout << " " << v.first;

    for(auto vs: this->VertexList)
    {
        cout << "\n" << vs.first << " ";
        for(auto ve: this->VertexList)
            if(this->adjMat[vs.second-1][ve.second-1])
                cout << "1 ";
            else

                cout << "0 ";
            
    }
}

AdjMatrixGraph::~AdjMatrixGraph()
{
    for(auto v: this->VertexList)
        delete this->adjMat[v.second-1];
    
    delete[] this->adjMat;
}

AdjListGraph::AdjListGraph(int vcount, int ecount)
{
    this->numVertices = vcount;
    this->numedges = ecount;        
}

void AdjListGraph::Insert_edge(string startV, string endV, int cost)
{
        this->AdjList[startV].push_front(make_pair(endV,cost));
}

void AdjListGraph::Display()
{
    for(auto vs: this->AdjList)
    {
        cout << "\n" << vs.first ;

         for(list<pair<string,int>>::iterator ve = vs.second.begin(); ve != vs.second.end(); ve++)
             cout << "-->(" << ve->first << ", " << ve->second << ")";
    }
}