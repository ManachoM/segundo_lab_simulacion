#include "../includes/glob.h"
#include "../includes/main.h"

void Sistema::inner_body( void )
{
    agr = new Agricultor("Agricultor", 0);
    fer = new Feriante("Feriante", 0, this->agr);
    agr->setFeriante(this->fer);

    Generador* generador = new Generador("Generador", this->numEventos);
    generador->activate();
    generador->setFeriante(fer);
    agr->activate();
    fer->activate();

    hold(simLen);

    
}


int main(int argc, char* argv[])
{
    // Instanciamos la simulación
    simulation::instance()->begin_simulation( new sqsDll( ));

    handle<Sistema> sistema(new Sistema("Sistema principal", 10000, 1000));

    sistema->activate();

    simulation::instance()->run();

    simulation::instance()->end_simulation();
    return 0;
}