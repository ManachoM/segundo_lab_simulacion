#ifndef EVENTO_H
#define EVENTO_H

#include "glob.h"
#include <atomic>

class Evento{
    
    private:

        int event_id;

        static std::atomic<int> _curr_id;

        int caller_id;

        int caller_type;

        int event_type;
        
    public:
        Evento(int _caller_id, int _caller_type, int _event_type) : event_id(++_curr_id)
        {
            this->caller_id = _caller_id;
            this->caller_type = _caller_type;
            this->event_type = _event_type;
        }

        int getCallerId();

        int getCallerType();

        int getEventType();
    
};


#endif // !EVENTO_H


