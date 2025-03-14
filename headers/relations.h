#ifndef relations
    #define relations

    #include <iostream>
    #include <vector>
    #include "GraphNode.h"

    namespace relations
    {
        class Relation{
            std::string relation = "Default relation";
            int level = 0;

            Relation(std::string relation){
                // [#TODO] if not a valid relation, cancel creation of object
                this->relation = relation;
                
                // [#TODO] change the level accordingly to the relation
                this->level = level;
            }
        };

        int getLevelByRelation(std::string relation){
            if (relation == "base") return 0;
            else if (relation == "spouse") return 0;
            else if (relation == "sister") return 0;
            else if (relation == "brother") return 0;
            else if (relation == "mother") return -1;
            else if (relation == "father") return -1;
            else if (relation == "son") return +1;
            else if (relation == "daughter") return +1;
            
            std::cout << "NO RELATION " << relation << " WAS FOUND!!!\n";
            return INT_MIN;
        }
    }

#endif