#ifndef MAIN_H
#define MAIN_H

#include "glob.h"
#include "Feriante.h"
#include "Agricultor.h"

class Sistema : public process
{
    public:
        Sistema (const std::string& _name, double _simLen) : process(_name)
        {
            this->simLen = _simLen;
        }

    protected:
        void inner_body( void ) override;

    private:
        double simLen;
        handle<Agricultor> agr;
        handle<Feriante> fer;

};

#endif MAIN_H // !MAIN_H