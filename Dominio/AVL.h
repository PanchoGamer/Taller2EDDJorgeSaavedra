#include "NodeAVL.h"

class AVL{
    private:
        NodeAVL* root;
    public:
        AVL(){
            this->root = nullptr;
        }

        bool insert(NodeAVL* nodo){
            if(!exists(nodo)){
                this->root = nodo;
                return;
            }
            
        }

        bool exists(NodeAVL* nodo){
            
        }

        bool remove(NodeAVL* nodo){

        }

        void clear(NodeAVL* nodo){

        }
};