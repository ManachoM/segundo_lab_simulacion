#include "../includes/Event.h"

std::atomic<int> Evento::_curr_id(0);

int Evento::getCallerId()
{
    return this->caller_id;
}

int Evento::getCallerType()
{
    return this->caller_type;
}

int Evento::getEventType()
{
    return this->event_type;
}