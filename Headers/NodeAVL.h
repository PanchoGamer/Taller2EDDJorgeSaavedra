#pragma once
#include "Persona.h"

class NodeAVL{
    private:
        Persona* value;
        int altura = 1;
        NodeAVL* left = nullptr;
        NodeAVL* right = nullptr;
    public:
        NodeAVL(Persona* p){
            this->value = p;
        }
        Persona* getPersona(){
            return this->value;
        }
        int getAltura(){
            return this->altura;
        }

        NodeAVL* getLeft(){
            return this->left;
        }

        NodeAVL* getRight(){
            return this->right;
        }

        void setAltura(int altura){
            this->altura = altura;
        }

        void setLeft(NodeAVL* izq){
            this->left = izq;
        }

        void setRight(NodeAVL* der){
            this->right = der;
        }

        ~NodeAVL(){}

};