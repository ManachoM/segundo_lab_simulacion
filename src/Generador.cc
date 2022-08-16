#include "../includes/Generador.h"

Generador::Generador(const string& _name, int _numEventos) : process(_name)
{
    this->numEventos = _numEventos;
    this->tiempoArribo = new rngExp("Arrive Time", 100.0);
    this->tiempoArribo->reset();
}

void Generador::setFeriante(Feriante *_fer)
{
    this->feriante = _fer;
}

void Generador::inner_body( void )
{
    printf("Comenzando generador...\n");
    int random = 0;

    double cte;

    for(int i = 0; i<this->numEventos; ++i)
    {
        random = rand() % 1000;

        printf("Valor generador %d\n", random);

        cte = this->tiempoArribo->value();

        if(this->feriante->idle()) this->feriante->activate();
        assert(!this->feriante->idle());
        this->feriante->push(random);
        hold(cte);

    }
}