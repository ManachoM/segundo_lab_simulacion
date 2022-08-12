#include "../includes/Feriante.h"

Feriante::Feriante(const std::string&_name , int _id, handle<Agricultor> _agr): process(_name)
{
    this->agricultor = _agr;
    this->estado = Estado::COMPRANDO_AGR;
}

int Feriante::getId()
{
    return this->id_feriante;
}

Estado Feriante::getEstado()
{
    return this->estado;
}

handle<Agricultor> Feriante::getAgricultor()
{
    return this->agricultor;
}

void Feriante::inner_body( void )
{
    while(1)
    {
        switch(this->estado)
        {
            case Estado::COMPRANDO_AGR:
            {
                // Si tenemos la mayor cantidad de productos posibles,
                // dejamos de comprar y solamente vendemos
                if(this->num_products == this->max_products)
                {
                    this->estado = Estado::VENDIENDO_CONSUMIDOR;
                }
                printf("Comprandole a agricultor...");
                this->num_products++;
                hold(5.0);
                this->agricultor->compraFeriante();
                if(this->agricultor->idle()) this->agricultor->activate();
                break;
            }

            case Estado::VENDIENDO_CONSUMIDOR:
            {
                if(this->num_products == 0)
                {
                    this->estado = Estado::COMPRANDO_AGR;
                    
                }
                printf("Vendiendo a consumidor :D");
                this->num_products--;
                hold(5.0);
                break;
            }

        }
    }
}