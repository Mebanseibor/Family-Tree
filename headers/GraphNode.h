extern int assignID();
#ifndef graphnode
    #define graphnode

    namespace graphnode
    {
        class GraphNode{
            public:
            int id = -1;
            int value = 0;
        
            GraphNode(){
                this->id = assignID();
            }
        
            GraphNode(int value){
                this->id = assignID();
                this->value = value;
            }
        };
    }
#endif