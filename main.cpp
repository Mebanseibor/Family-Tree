#include <iostream>
#include <vector>
#include "Headers\Graph.h"
#include "Headers\GraphNode.h"
#include "Headers\GraphEdge.h"

int ID_COUNTER = 0;

int assignID(){
    return ID_COUNTER++;
}

void testWithRelation(){
    Graph g = Graph("Family Tree");

    GraphNode me = GraphNode("Barry", 'm');
    GraphNode father = GraphNode("Frank", 'm');
    GraphNode mother = GraphNode("Maria", 'f');
    GraphNode daughter = GraphNode("Dakira", 'f');
    GraphNode son = GraphNode("Sukani", 'm');

    me.addMother(mother);
    me.addFather(father);

    me.addDaughter(daughter);
    me.addSon(son);
    me.displayInfo();
}

int main(){
    testWithRelation();
    
    return 0;
}