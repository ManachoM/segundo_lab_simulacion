#include "../includes/Agricultor.h"

Agricultor::Agricultor(const std::string& _name, int _id) : process(_name)
{
    this->id_agricultor = _id;
    this->tiene_almacenamiento = false;
    this->setEstado(Agricultor::estado::INICIO);
}

void Agricultor::inner_body( void )
{
    while(1){
        printf("Dentro del inner body :D!");
    }
}