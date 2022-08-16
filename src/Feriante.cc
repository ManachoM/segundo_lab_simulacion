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
        if(this->num_products < this->max_products)
        {
            if(this->agricultor->idle()) this->agricultor->activate();
            bool compraAgr = this->agricultor->compraFeriante();
            if(!compraAgr)
            {
                printf("No le pudo comprar al agricultor... Espera a que esté disponible para comprar...\n");
                this->passivate();
            }
            hold(TIEMPO_COMPRA_AGR);
            this->num_products++;
            this->dinero = this->dinero - PRECIO_COMPRA_AGR;
        }
        if(!this->pedidos.empty())
        {
            this->venderConsumidor();
        }
        else if(this->num_products == this->max_products)
        {
            this->passivate();
        }
    }
}

void Feriante::venderConsumidor()
{
    assert(!this->idle());
    if(this->num_products <= 0)
    {
        if(!this->agricultor->compraFeriante()) 
        {
            this->passivate();
            this->agricultor->activate();
            printf("No se pudo concretar la venta al consumidor... El agricultor no pudo abastecer\n");
            return;
        }
        this->dinero = this->dinero - PRECIO_COMPRA_AGR;
        this->num_products++;
    }
    printf("Aquí vamosss\n");
    this->hold(TIEMPO_VENTA);

    this->num_products--;
    this->dinero = this->dinero + PRECIO_VENTA_CONS;
    printf("Se concretó la venta al consumidor\n");
}

void Feriante::push(int x)
{
    this->pedidos.push_back(x);
    //this->venderConsumidor();
}