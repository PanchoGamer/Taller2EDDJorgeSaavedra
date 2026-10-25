#pragma once
#include <string>
using namespace std;

class Servicio{
    public:
        static const int urgencias = 0;
        static const int medicinaGeneral = 1;
        static const int cardiologia = 2;
        static const int neurologia = 3;
        static const int traumatologia = 4;
        static const int cirugia = 5;
        static const int pediatria = 6;
        static const int hospitalizacion = 7;

        static const int total = 8;


        static string nombre(int s){
            switch(s){
                case urgencias: return "Urgencias";
                case medicinaGeneral: return "Medicina General";
                case cardiologia: return "Cardiologia";
                case neurologia: return "Neurologia";
                case traumatologia: return "Traumatologia";
                case cirugia: return "Cirugia";
                case pediatria: return "Pediatria";
                case hospitalizacion: return "Hospitalizacion";
            }
            return "Desconocido";
        }
};