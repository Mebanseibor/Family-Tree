#include <iostream>
#include <vector>
#include "Headers\Graph.h"
#include "Headers\GraphNode.h"
#include "Headers\GraphEdge.h"

int ID_COUNTER = 0;

int assignID(){
    std::cout << "assigned ID:\t" << ID_COUNTER << "\n";
    return ID_COUNTER++;
}

void test(){
    Graph g = Graph("Graph A");

    GraphNode node0 = g.addNode(2);
    GraphNode node1 = g.addNode(3);
    g.addEdge(node0, node1);
    
    g.displayInfo();

    g.searchRelation(node0, node1);
    
    
    GraphNode node2 = g.addNode(1);
    GraphNode node3 = g.addNode(2);
    g.searchRelation(node2, node3);


    g.addEdge(node1, node2);
    g.displayInfo();

    g.searchRelation(node0, node1);
    g.searchRelation(node1, node2);
    g.searchRelation(node2, node1);
}

int main(){
    test();
    
    return 0;
}