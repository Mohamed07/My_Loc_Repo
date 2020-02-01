#include "graph.h"
#include "iostream"

using namespace std;
int main()
{
    ////////////////////////////////////////////
    //                Edge List               //
    ////////////////////////////////////////////
    EdgeListGraph mygraph(10);

    mygraph.insert_edge("A", "B", 1);
    mygraph.insert_edge("C", "A", 2);
    mygraph.insert_edge("B", "F", 3);
    mygraph.insert_edge("D", "A", 4);
    mygraph.insert_edge("E", "B", 5);
    mygraph.insert_edge("H", "E", 6);
    mygraph.insert_edge("H", "D", 7);
    mygraph.insert_edge("G", "C", 8);        

    //mygraph.Display_edges();

    //mygraph.Find_adjacent("D");

    //cout << mygraph.Get_numvertices() << "\n";

    ////////////////////////////////////////////
    //           Adjacency Matrix             //
    ////////////////////////////////////////////

    AdjMatrixGraph mygraph2(8);
    mygraph2.Insert_edge("A", "B");
    mygraph2.Insert_edge("C", "A");
    mygraph2.Insert_edge("B", "F");
    mygraph2.Insert_edge("D", "A");
    mygraph2.Insert_edge("E", "B");
    mygraph2.Insert_edge("H", "E");
    mygraph2.Insert_edge("H", "D");
    mygraph2.Insert_edge("G", "C");    

    //mygraph2.Display();

    ////////////////////////////////////////////
    //           Adjacency Matrix             //
    ////////////////////////////////////////////
    AdjListGraph mygraph3(8,8);
    mygraph3.Insert_edge("A", "B", 5);
    mygraph3.Insert_edge("C", "A", 4);
    mygraph3.Insert_edge("A", "D", 2);
    mygraph3.Insert_edge("A", "E", 1);    

    mygraph3.Display();
    return 0;
}