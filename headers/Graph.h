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
                std::cout << "Searching for member with name \"" << name << "\": \t";

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
                    std::cout << "Multiple members were found\n";
                    return nullptr;
                }

                std::cout << "Member was NOT found\n";
                return result;
            }

            bool assignParents(std::string child, std::string mother, std::string father){
                std::cout << "Attempting to assign \"" << child << "\"'s parents as \"" << mother << "\" and \"" << father << "\"\n";

                GraphNode* childNode = findMember(child);
                GraphNode* motherNode = findMember(mother);
                GraphNode* fatherNode = findMember(father);

                return assignParents(childNode, motherNode, fatherNode);
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

            bool inputChild(){
                // searching for the mother
                GraphNode* mother = nullptr;
                do{
                    std::cout << "\nEnter the mother's name (-1 to quit, 1 to display the graph's details): ";
                    std::string nameMother;
                    std::cin >> nameMother;

                    if(nameMother == "-1") return false;
                    if(nameMother == "1"){
                        displayDetails();
                        continue;
                    }

                    mother = findMember(nameMother);

                    if(mother){
                        if(mother->isFemale()) break;
                        std::cout << nameMother << " is not a female\n";
                    }
                }while(true);

                // searching for the father
                GraphNode* father = nullptr;
                do{
                    std::cout << "\nEnter the father's name (-1 to quit, 1 to display the graph's details): ";
                    std::string nameFather;
                    std::cin >> nameFather;

                    if(nameFather == "-1") return false;
                    if(nameFather == "1"){
                        displayDetails();
                        continue;
                    }

                    father = findMember(nameFather);

                    if(father){
                        if(father->isMale()) break;
                        std::cout << nameFather << " is not a male\n";
                    }
                }while(true);

                GraphNode* child = nullptr;
                do{
                    std::cout << "\nEnter the details of the children:\n";
                    std::string nameChild;
                    std::cout << "Name: ";
                    std::cin >> nameChild;

                    char genderChild;
                    std::cout << "Gender: ";
                    std::cin >> genderChild;

                    GraphNode* child = createMember(nameChild, genderChild);
                    if(child && child->addParents(*mother, *father)) break;
                    std::cout << "Cannot add parents to the child\n";

                    std::cout << "Enter -1 to quit: ";
                    std::string response;
                    std::cin >> response;
                    if(response == "-1") return false;
                }while(true);

                return true;
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

            bool promptExit(std::string text = ""){
                std::string input;
                if(text == "") text = "Enter -1 to exit: ";

                std::cout << text;
                std::cin >> input;
                return input == "-1" ? true : false;
            }
        };
    }
#endif
