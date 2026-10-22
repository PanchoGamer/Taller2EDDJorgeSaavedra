#pragma once
#include "Persona.h"
#include "Servicio.h"
using namespace std;

int pUrgente = 0;
int pTrauma = 1;
int pCirugia = 2;
int pPecho = 3;
int pNeuro = 4;
int pNiño = 5;
int pHospital = 6;

class DecisionNode{
    private:
        string descripcion;
        int pregunta;
        int servicio;
        bool hoja;
        DecisionNode* si = nullptr;
        DecisionNode* no = nullptr;
    public:
        DecisionNode(string descripcion, int pregunta){
            this->descripcion = descripcion;
            this->pregunta = pregunta;
            this->servicio = 0;
            this->hoja = false;
            this->si = nullptr;
            this->no = nullptr;
        }

        DecisionNode(int servicio){
            this->descripcion = Servicio::nombre(servicio);
            this->pregunta = -1;
            this->servicio = servicio;
            this->hoja = true;
            this->si = nullptr;
            this->no = nullptr;
        }

        bool esHoja(){
            return this->hoja;
        }

        int getPregunta(){
            return this->pregunta;
        }

        string getDescripcion(){
            return this->descripcion;
        }

        int getServicio(){
            return this->servicio;
        }

        DecisionNode* getSi(){
            return this->si;
        }

        DecisionNode* getNo(){
            return this->no;
        }

        void setSi(DecisionNode* nodo){
            this->si = nodo;
        }

        void setNo(DecisionNode* nodo){
            this->no = nodo;
        }
};