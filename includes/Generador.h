#ifndef GENERADOR_H
#define GENERADOR_H

#include "glob.h"
#include "Feriante.h"

class Generador: public process
{
    private:
        int numEventos; // Número de eventos a generar
        rng<double>* tiempoArribo; 
        Feriante* feriante; 
    protected:
        void inner_body( void ) override;
    public:
        Generador (const string& _name, int _numEventos);

        void setFeriante(Feriante * _fer);
};

#endif // !GENERADOR_H