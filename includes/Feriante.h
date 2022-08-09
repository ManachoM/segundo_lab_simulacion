#ifndef FERIANTE_H
#define FERIANTE_H

#include "glob.h"
#include "Agricultor.h"


enum Estado {COMPRANDO_AGR, VENDIENDO_CONSUMIDOR };

class Agricultor;

class Feriante : public process
{
    private:

        int id_feriante;

        const static int max_products = 100;

        handle<Agricultor> agricultor;

        Estado estado;

        int num_products = 0;

    public:

        Feriante(const std::string&_name , int _id, handle<Agricultor> _agr) : process(_name)
        {
            this->agricultor = _agr;
            this->estado = Estado::COMPRANDO_AGR;
        }

        int getId();

        Estado getEstado();

        handle<Agricultor> getAgricultor();

    protected:

        void inner_body( void ) override;
        


};

#endif // !FERIANTE_H