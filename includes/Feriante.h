#ifndef FERIANTE_H
#define FERIANTE_H

#include "glob.h"
#include "Agricultor.h"

#define TIEMPO_VENTA 10.0
#define TIEMPO_COMPRA_AGR 15.0
#define PRECIO_COMPRA_AGR 5
#define PRECIO_VENTA_CONS 7


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

        int dinero = 100;

        list<int> pedidos;


    public:

        Feriante(const std::string&_name , int _id, handle<Agricultor> _agr); 

        int getId();

        Estado getEstado();

        handle<Agricultor> getAgricultor();

        void push(int x);

        

    protected:
        void venderConsumidor();

        void inner_body( void ) override;
        


};

#endif // !FERIANTE_H