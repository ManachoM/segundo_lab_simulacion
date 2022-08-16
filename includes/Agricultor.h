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
#include "Feriante.h"

#define TIEMPO_PREPARAR_TERRENO 3
#define TIEMPO_SIEMBRA 20
#define TIEMPO_COSECHA 15

class Feriante;

 enum EstadoAgricultor {INICIO, SIEMBRA, COSECHA, VENTA, PREPARACION_TERRENO};

class Agricultor : public process
{
    private:
        int id_agricultor;

        int num_productos;
        
        const static int max_productos = 1000;

        std::map<int, Terreno> terrenos;

        std::map<int, Stock> stock;

        bool tiene_almacenamiento;

        std::map<int, Almacenamiento> almacenamientos;

        std::map<int, int> vendidas;

        std::map<int, int> perdidas;

        std::map<int, Transaccion> historial;

        std::vector<Evento> eventos;

        EstadoAgricultor estado;

        handle<Feriante> feriante;

        void prepararTerreno();

        void sembrar();

        void cosechar();





    public:
        Agricultor(const std::string& _name, int _id): process(_name)
        {
            this->id_agricultor = _id;
            this->tiene_almacenamiento = false;
            this->setEstado(EstadoAgricultor::INICIO);
        };

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

        void setEstado(EstadoAgricultor _state);

        bool compraFeriante();

        void setFeriante(handle<Feriante> _feriante);

       
    protected:

        void inner_body( void ) override;


};


#endif AGRICULTOR_H // !AGRICULTOR_H