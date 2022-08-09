/*!
    @author: Manuel Ignacio Manríquez - @ManachoM


*/

#ifndef AGRICULTOR_H
#define AGRICULTOR_H


#include <string.h>
#include <vector>
#include "glob.h"
#include "utils/Stock.h"
#include "utils/Terreno.h"
#include "utils/Almacenamiento.h"
#include "utils/Transaccion.h"
#include "Event.h"

class Agricultor : public process
{
    private:
        int id_agricultor;

        std::map<int, Terreno> terrenos;

        std::map<int, Stock> stock;

        bool tiene_almacenamiento;

        std::map<int, Almacenamiento> almacenamientos;

        std::map<int, int> vendidas;

        std::map<int, int> perdidas;

        std::map<int, Transaccion> historial;

        std::vector<Evento> eventos;

        enum estado {INICIO, SIEMBRA, COSECHA, VENTA, PREPARACION_TERRENO};





    public:
        Agricultor(const std::string& _name, int _id) : process(_name){};

        int getId() { return this->id_agricultor; };

        std::map<int, Terreno> getTerrenos() { return this->terrenos; }

        std::map<int, Stock> getStocks() { return this->stock; }

        std::map<int, int> getVendidas() { return this->vendidas; }

        std::map<int, int> getPerdidas() { return this->perdidas; }

        std::map<int, Transaccion> getHistorial() { return this->historial; }

        void setTerrenos(std::map<int, Terreno> _terrenos);

        void setStock(std::map<int, Stock> _stock);

        void setVendidas(std::map<int, int> _vendidas);

        void setPerdidas(std::map<int, int> _perdidas);

        void setHistorial(std::map<int, Transaccion> _historial);

        void setEstado(estado _state);

    protected:
        void inner_body( void ) override;


};


#endif AGRICULTOR_H // !AGRICULTOR_H