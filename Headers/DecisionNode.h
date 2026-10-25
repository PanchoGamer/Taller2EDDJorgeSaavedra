#pragma once
#include "Persona.h"
#include "Servicio.h"
using namespace std;

const int pUrgente = 0;
const int pTrauma = 1;
const int pCirugia = 2;
const int pPecho = 3;
const int pNeuro = 4;
const int pNiño = 5;
const int pHospital = 6;

class DecisionNode{
    private:
        string descripcion;
        string textoSi;
        string textoNo;
        int pregunta;
        int servicio;
        bool hoja;
        DecisionNode* si = nullptr;
        DecisionNode* no = nullptr;
    public:
        DecisionNode(string textoSi, string textoNo, int pregunta){
            this->descripcion = textoSi;
            this->textoSi = textoSi;
            this->textoNo = textoNo;
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

        string getTextoSi(){
            return this->textoSi;
        }

        string getTextoNo(){
            return this->textoNo;
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