#include "../Headers/Persona.h"
#include <string>

Persona::Persona(string id, string nombre, int age, double temp, int presionArterial, int dolor, string tipoDolor, int trauma, int sintomasNeurologicos, int requiereCirugia, int diasHospitalizacion){
    this->id = id;
    this->nombre = nombre;
    this->age = age;
    this->temp = temp;
    this->presionArterial = presionArterial;
    this->dolor = dolor;
    this->tipoDolor = tipoDolor;
    this->trauma = trauma;
    this->sintomasNeurologicos = sintomasNeurologicos;
    this->requiereCirugia = requiereCirugia;
    this->diasHospitalizacion = diasHospitalizacion;
}

string Persona::getId(){
    return this->id;
}

string Persona::getNombre(){
    return this->nombre;
}

int Persona::getAge(){
    return this->age;
}

double Persona::getTemp(){
    return this->temp;
}

int Persona::getPresionArterial(){
    return this->presionArterial;
}

int Persona::getDolor(){
    return this->dolor;
}

string Persona::getTipoDolor(){
    return this->tipoDolor;
}

int Persona::getTrauma(){
    return this->trauma;
}

int Persona::getSintomasNeurologicos(){
    return this->sintomasNeurologicos;
}

int Persona::getRequiereCirugia(){
    return this->requiereCirugia;
}

int Persona::getDiasHospitalizacion(){
    return this->diasHospitalizacion;
}

Persona::~Persona(){}