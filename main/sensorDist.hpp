#ifndef __SENSORDIST__
#define __SENSORDIST__

#include <inttypes.h> 

class SensorDist {
    public:
        uint8_t dist;
    public:
        SensorDist();
        void setDist(bool opt);
        void getAltura();
};

extern SensorDist sD;
#endif