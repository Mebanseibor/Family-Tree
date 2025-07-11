#include <iostream>
#include <vector>
#include "Headers\Graph.h"
#include "Headers\GraphNode.h"
#include "Headers\GraphEdge.h"

int ID_COUNTER = 0;

int assignID(){
    return ID_COUNTER++;
}

void testDisplayGraph(Graph& g){
    std::cout << "--- Test Display Graph (START) ---\n";

    g.displayDetails();

    std::cout << "--- Test Display Graph (END) ---\n\n\n";
}

void testPopulateFamilyTree(Graph& g){
    std::cout << "--- Test Populate Family Tree (START) ---\n";

    GraphNode* base = g.createMember("Barry", 'm');
    GraphNode* mother = g.createMember("Maria", 'f');
    GraphNode* father = g.createMember("Frank", 'm');
    GraphNode* daughter = g.createMember("Dakira", 'f');
    GraphNode* son = g.createMember("Sukani", 'm');
    GraphNode* wife = g.createMember("Wisa", 'f');
    GraphNode* dummy1 = g.createMember("Dummy", 'm');
    GraphNode* dummy2 = g.createMember("Dummy", 'f');
    GraphNode* dummy3 = g.createMember("Dummy");

    std::cout << "--- Test Populate Family Tree (END) ---\n\n\n";
}

void testCreateRelations(Graph& g){
    std::cout << "--- Test Create Relations (START) ---\n";

    std::cout << "Getting the objects:\n";
    GraphNode* base = g.findMember("Barry");
    GraphNode* mother = g.findMember("Maria");
    GraphNode* father = g.findMember("Frank");
    GraphNode* daughter = g.findMember("Dakira");
    GraphNode* son = g.findMember("Sukani");
    GraphNode* wife = g.findMember("Wisa");

    GraphNode* dummy = g.findMember("Dummy");

    std::cout << "\nCreating the relations:\n";
    g.assignParents(base, mother, father);
    std::cout << "\n";
    g.assignParents("Dakira", "Wisa", "Barry");
    std::cout << "\n";
    g.assignParents("Sukani", "Wisa", "Barry");
    std::cout << "\n";

    // should re errors
    g.assignParents("Sukani", "Wisa", "Dummy");
    std::cout << "\n";
    g.assignParents("Sukani", "Barry", "Wisa");
    std::cout << "\n";

    g.displayDetails();
    std::cout << "--- Test Create Relations (END) ---\n\n\n";
}

void testSearching(Graph& g){
    std::cout << "--- Test Searching (START) ---\n";

    GraphNode* base = g.findMember("Barry");
    GraphNode* mother = g.findMember("Maria");
    GraphNode* father = g.findMember("Frank");
    GraphNode* daughter = g.findMember("Dakira");
    GraphNode* son = g.findMember("Sukani");
    GraphNode* wife = g.findMember("Wisa");

    GraphNode* dummy = g.findMember("Dummy");

    std::cout << "--- Test Searching (END) ---\n\n\n";
}

void testInputChild(Graph& g){
    std::cout << "--- Test Input Child (START) ---\n";

    if(g.promptExit("Enter anything to continue, enter -1 to skip the test \"Input Child\": "))
        std::cout << "Skipping the test \"Input Child\"\n";
    else{
        do{
            if(!g.inputChild()) break;
            std::cout << "\n";

            if(g.promptExit("Enter anything to continue, enter -1 to exit to finish inputting children: ")) break;
        }while(true);

        g.displayDetails();
    };
    std::cout << "--- Test Input Child (END) ---\n\n\n";
}

// template test function
void test(Graph& g){
    std::cout << "--- Test (START) ---\n";



    std::cout << "--- Test (END) ---\n\n\n";
}

int main(){
    Graph g = Graph("Family Number 1");

    testPopulateFamilyTree(g);
    testDisplayGraph(g);
    testSearching(g);
    testCreateRelations(g);
    testInputChild(g);
    
    return 0;
}
