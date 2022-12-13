#ifndef __SENSORDIST__
#define __SENSORDIST__

class SensorDist {
    private:
        float dist;
    public:
        sd(){this.dist = 0;};
        int calcDist(int t1, int t2);
        void getDist();
        void setDist(bool opt);
        void getAltura();
};

extern SensorDist SensorDist;
#endif