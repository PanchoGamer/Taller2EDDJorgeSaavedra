#include "NodeAVL.h"

class AVL{
    private:
        NodeAVL* root;
        AVL* next;
    public:
        AVL(){
            this->root = nullptr;
            this->next = nullptr;
        }

        bool insert(NodeAVL* nodo){
            if(!exists(nodo)){
                this->root = nodo;
                return false;
            }

        }

        bool exists(NodeAVL* nodo){
            
        }

        bool remove(NodeAVL* nodo){

        }

        void clear(NodeAVL* nodo){

        }

        NodeAVL* getRoot(){
            return this->root;
        }

        AVL* getNext(){
            return this->next;
        }

        void setNext(AVL* next){
            this->next = next;
        }
};