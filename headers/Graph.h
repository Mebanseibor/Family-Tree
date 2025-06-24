#ifndef graph
    #define graph

    #include <iostream>
    #include <vector>
    #include "graphnode.h"

    namespace graph
    {
        class Graph{
            private:
            void createParents(GraphNode& child){
                std::string nameMother;
                std::cout << "Enter name for the mother: ";
                std::cin >> nameMother;

                std::string nameFather;
                std::cout << "Enter the name for the father: ";
                std::cin >> nameFather;

                nodes.push_back(createMember(nameMother, 'f'));
                nodes.push_back(createMember(nameFather, 'm'));
            }

            public:
            std::string name = "default graph name";
            
            std::vector<GraphNode*> nodes = {};
        
            int countNodes(){ return nodes.size(); }
        
            Graph(std::string name){ this->name = name; }

            GraphNode* createMember(std::string name, char gender='u'){
                GraphNode* g = new GraphNode(name, gender);
                nodes.push_back(g);
                std::cout << "Created a new member for the graph " << this->name << ":\t" << name << "\n";
                return g;
            }

            GraphNode* findMember(std::string name){
                std::cout << "Searching for member " << name << ": \t";

                int counter = 0;
                GraphNode* result = nullptr;
                for(GraphNode* node : nodes){
                    if(node->name == name){
                        counter++;
                        result = node;
                    }
                }
                if(counter == 1){
                    std::cout << "Member was found\n";
                    return result;
                }
                else if(counter>1){
                    std::cout << "Multiple members was found\n";
                    return nullptr;
                }

                std::cout << "Member was NOT found\n";
                return result;
            }

            bool assignParents(GraphNode* child, GraphNode* mother, GraphNode* father){
                if(!child || !mother || !father){
                    std::cout << "Failed to assign parents: Some for the provided nodes are nullptr\n";
                    return false;
                }
                if(child->addParents(*mother, *father)){
                    std::cout << "\"" << child->name << "\" now have \"" << mother->name << "\" and \"" << father->name << "\" as parents\n";
                    return true;
                }
                std::cout << "Failed to assign parents: addParents() returned false\n";
                return false;
            }

            void displayDetails(){
                std::cout << "Graph name:\t" << this->name << "\n";
                std::cout << "Number of nodes:\t" << this->countNodes() << "\n";
                std::cout << "Nodes of the graph:\n";
                std::cout << "\t(id) name\tgender\tmother\tfather\tn(sons)\tn(daughters)\n";
                for(GraphNode* node : nodes){
                    std::cout << "\t(" << node->id << ") " << node->name << "\t" << node->getStringGender() << "\t";
                    std::cout << node->getStringMother() << "\t" << node->getStringFather() << "\t";
                    std::cout << node->sons.size() << "\t" << node->daughters.size() << "\n";
                }
            }
        };
    }
#endif
