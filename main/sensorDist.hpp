#ifndef __SENSORDIST__
#define __SENSORDIST__

#include <stdio.h> 

class SensorDist {
    private:
        int distSensor;
    public:
        SensorDist(){distSensor = 300;};
        void setDist(bool opt);
        void getAltura();
};

#endif