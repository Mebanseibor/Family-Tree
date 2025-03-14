#ifndef graph
    #define graph

    #include <iostream>
    #include <vector>
    #include "graphnode.h"
    #include "graphedge.h"

    namespace graph
    {
        class Graph{
            public:
            std::string name = "Default graph name";
            
            std::vector<GraphNode> nodes = {};
            std::vector<GraphEdge> edges = {};
        
            int countNodes(){return nodes.size();}
            int countEdges(){return edges.size();}
        
            Graph(std::string name){
                this->name = name;
            }
        
            void displayInfo(){
                std::cout << "-----Graph Info (Start)-----\n";
                std::cout << "Graph name:\t" << this->name << "\n";
                std::cout << "Number of nodes:\t" << this->countNodes() << "\n";
                std::cout << "Number of edges:\t" << this->countEdges() << "\n";
                
                std::cout << "\nNodeA\t\tNodeB\n";
                for(GraphEdge edge : edges){
                    edge.displayRelation();
                }
                std::cout << "-----Graph Info (End)-----\n";
            }
        
            void addNode(GraphNode node){nodes.push_back(node);}
            
            GraphNode addNode(){
                GraphNode node = GraphNode();
                nodes.push_back(node);
                return node;
            }
            
            void addEdge(GraphNode &nodeA, GraphNode &nodeB){
                if(nodeA.id == nodeB.id){
                    std::cout << "Error: Cannot have an edge between the same nodes\n";
                }
                
                
                GraphEdge newEdge = GraphEdge(&nodeA, &nodeB);
                edges.push_back(newEdge);
            }
        
            void searchRelation(GraphNode nodeA, GraphNode nodeB){
                for(GraphEdge edge : edges){
                    GraphNode enodeA = *(edge.nodeA);
                    GraphNode enodeB = *(edge.nodeB);
        
                    bool isBidirectional = ((enodeA.id == nodeA.id && enodeB.id == nodeB.id) ||
                                            (enodeA.id == nodeB.id && enodeB.id == nodeA.id)
                                            );
                    if(isBidirectional){
                        std::cout << "Relation: Bidirectional\n";
                        return;
                    };
                }
                
                std::cout << "Relation: No relation\n";
            }
        };
    }
#endif