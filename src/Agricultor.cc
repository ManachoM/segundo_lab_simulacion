#include "../includes/Agricultor.h"


void Agricultor::inner_body( void )
{
    while(1){
        //SWITCH(this->estado)
        // Si tenemos la máxima cantidad de productos posible,
        // descansamos
        switch(this->estado)
        {
            case EstadoAgricultor::INICIO:
            {
                this->setEstado(EstadoAgricultor::PREPARACION_TERRENO);
                break;
            }
            case EstadoAgricultor::PREPARACION_TERRENO:
            {
                this->prepararTerreno();
                break;
            }
            case EstadoAgricultor::SIEMBRA:
            {
                this->sembrar();
                break;
            }
            case EstadoAgricultor::COSECHA:
            {
                this->cosechar();
                break;
            }
            case EstadoAgricultor::VENTA:
            {
                if(this->num_productos == 0)
                { 
                    this->setEstado(EstadoAgricultor::PREPARACION_TERRENO);
                    break;
                }
                if(this->feriante->idle()) this->feriante->activate();
                this->passivate();
                break;
            }

        }
    }
}

bool Agricultor::compraFeriante()
{
    if(this->num_productos <= 0 || this->estado != EstadoAgricultor::VENTA) return false;
    // hold(CANTIDAD)
    this->num_productos--;
    return true;
}

void Agricultor::setFeriante(handle<Feriante> _feriante)
{
    this->feriante = _feriante;
}

void Agricultor::setEstado(EstadoAgricultor _estado)
{
    this->estado = _estado;
}

void Agricultor::prepararTerreno()
{
    hold(TIEMPO_PREPARAR_TERRENO);
    printf("Preparando el terreno...\n");
    this->setEstado(EstadoAgricultor::SIEMBRA);
}

void Agricultor::sembrar()
{
    hold(TIEMPO_SIEMBRA);
    printf("Sembrando...\n");
    this->setEstado(EstadoAgricultor::COSECHA);
}

void Agricultor::cosechar()
{
    hold(TIEMPO_COSECHA);
    printf("Cosechando y preparado la venta...\n");
    this->num_productos = this->max_productos;
    this->setEstado(EstadoAgricultor::VENTA);
}