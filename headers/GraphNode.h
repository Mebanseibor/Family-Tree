extern int assignID();
#ifndef graphnode
    #define graphnode

    namespace graphnode
    {
        class GraphNode{
            private:
            bool addDaughter(GraphNode &daughter){
                if(!daughter.isFemale() & !canBeParentToChild(daughter)) return false;

                daughters.push_back(daughter);

                return true;
            }

            bool addSon(GraphNode &son){
                if(!son.isMale() && !canBeParentToChild(son)) return false;

                sons.push_back(son);

                return true;
            }

            bool addChild(GraphNode *child){
                if (child->isUndefinedGender()) return false;
                
                if (child->isMale()) this->addSon(*child);
                else this->addDaughter(*child);
                
                return true;
            }

            public:
            unsigned int id;
            std::string name = "Default Name";
            char gender = 'U';

            GraphNode* mother = nullptr;
            GraphNode* father = nullptr;
            std::vector<GraphNode> daughters = {};
            std::vector<GraphNode> sons = {};
        
            GraphNode(){
                this->id = assignID();
            }

            GraphNode(std::string name){
                this->id = assignID();
                this->name = name;
            }

            GraphNode(std::string name, char gender){
                this->id = assignID();
                this->name = name;
                
                // [#TODO] cancel the creation of the node if gender is invalid
                this->gender = gender;
            }

            void displayInfo(){
                std::cout << "-----Info: " << name << " (Start) -----\n";

                std::cout << "ID:\t" << id << "\n";
                std::cout << "Name:\t" << name << "\n";
                std::cout << "Gender:\t" << gender << "\n";

                std::string nameMother = "undefined";
                std::string nameFather = "undefined";
                std::string nameDaughters = "undefined";
                std::string nameSons = "undefined";

                if(isMotherAssigned()) nameMother = mother->name;
                if(isFatherAssigned()) nameFather = father->name;
                if(hasAnyDaughters()){
                    nameDaughters = "";
                    for(GraphNode daughter : daughters) nameDaughters += daughter.name + ", ";;
                };
                if(hasAnySons()){
                    nameSons = "";
                    for(GraphNode son : sons) nameSons += son.name + ", ";;
                };
                
                std::cout << "Mother:\t" << nameMother << "\n";
                std::cout << "Father:\t" << nameFather << "\n";
                std::cout << "Daughters:\t" << nameDaughters << "\n";
                std::cout << "Sons:\t" << nameSons << "\n";
                std::cout << "-----Info: " << name << " (END) -----\n";
            }

            bool addParents(GraphNode &mother, GraphNode &father){
                if(this->isUndefinedGender() || this->isMotherAssigned() || this->isFatherAssigned()) return false;

                if(!this->isMotherAssigned()){
                    this->mother = &mother;
                    mother.addChild(this);
                };
                
                if(!this->isFatherAssigned()){
                    this->father = &father;
                    father.addChild(this);
                }

                return true;
            }

            std::string getStringGender() {
                return isFemale() ? "Female" : isMale() ? "Male" : "NULL";
            }

            std::string getStringFather(){ return isFatherAssigned() ? father->name : "NULL"; }
            std::string getStringMother(){ return isMotherAssigned() ? mother->name : "NULL"; }

            bool isFemale(){ return (gender == 'f' || gender == 'F') ? true : false; }
            bool isMale(){ return (gender == 'm' || gender == 'M') ? true : false; }
            bool isUndefinedGender(){ return (gender == 'u' || gender == 'U') ? true : false; }

            bool isMotherAssigned(){return (mother != NULL) ?  true : false;}
            bool isFatherAssigned(){return (father != NULL) ?  true : false;}
            bool hasAnyDaughters(){return (daughters.size() > 0) ? true : false;}
            bool hasAnySons(){return (sons.size() > 0) ? true : false;}
            bool canBeParentToChild(GraphNode &child){
                if(this->isMale()){
                    return (child.isFatherAssigned() && child.father->id != this->id) ? false : true;
                }
                else if(this->isFemale()){
                    return (child.isMotherAssigned() && child.mother->id != this->id) ? false : true;
                }

                return false;
            }
        };
    }
#endif
