#pragma once
#include <string>
using namespace std;

class Persona{
    private:
        string id;
        string nombre;
        int age;
        double temp;
        int presionArterial;
        int dolor;
        string tipoDolor;
        int trauma;
        int sintomasNeurologicos;
        int requiereCirugia;
        int diasHospitalizacion;
    public:
        Persona(string id, string nombre, int age, double temp, int presionArterial, int dolor,
                string tipoDolor, int trauma, int sintomasNeurologicos, int requiereCirugia,
                int diasHospitalizacion);
        string getId();
        string getNombre();
        int getAge();
        double getTemp();
        int getPresionArterial();
        int getDolor();
        string getTipoDolor();
        int getTrauma();
        int getSintomasNeurologicos();
        int getRequiereCirugia();
        int getDiasHospitalizacion();
        ~Persona();
};