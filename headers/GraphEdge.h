#ifndef graphedge
    #define graphedge
    
    #include <iostream>
    #include "graphnode.h"
    
    namespace graphedge
    {
        class GraphEdge{
            public:
            int weight;
            GraphNode* nodeA;
            GraphNode* nodeB;

            GraphEdge(GraphNode *nodeA, GraphNode *nodeB){
                this->nodeA = nodeA;
                this->nodeB = nodeB;
            }

            void displayRelation(){
                std::cout << nodeA->id << "\t<--->\t" << nodeB->id << "\n";
            }
        };
    }
#endif