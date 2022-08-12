#include "../includes/Agricultor.h"


void Agricultor::inner_body( void )
{
    while(1){
        //SWITCH(this->estado)
        // Si tenemos la máxima cantidad de productos posible,
        // descansamos
        if(this->num_productos >= this->max_productos)
        {
            passivate();
        }
        // Si no, aumentamos el inventario
        this->num_productos++;
        // Hacemos un hold
        hold(10.0);
        // Si el feriante está durmiendo, lo despertamos
        if(this->feriante->idle()) feriante->activate();
    }
}

bool Agricultor::compraFeriante()
{
    if(this->num_productos < 0) return false;
    // hold(CANTIDAD)
    this->num_productos--;
    return true;
}

void Agricultor::setFeriante(handle<Feriante> _feriante)
{
    this->feriante = _feriante;
}

void Agricultor::setEstado(Agricultor::estado _estado)
{
    
}