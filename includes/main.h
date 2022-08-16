#ifndef MAIN_H
#define MAIN_H

#include "glob.h"
#include "Feriante.h"
#include "Agricultor.h"
#include "Generador.h"

class Sistema : public process
{
    public:
        Sistema (const std::string& _name, double _simLen, int _numEventos) : process(_name)
        {
            this->simLen = _simLen;
            this->numEventos = _numEventos;
        }

    protected:
        void inner_body( void ) override;

    private:
        double simLen;
        int numEventos;
        handle<Agricultor> agr;
        handle<Feriante> fer;

};

#endif MAIN_H // !MAIN_H