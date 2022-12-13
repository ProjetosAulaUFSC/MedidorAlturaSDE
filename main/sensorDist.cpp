#include "sensorDist.hpp"
#include "serial.hpp"
#include <string>
#include <iostream>
#include "esp_timer.h"

// #define TRIGGER_PIN = 

using namespace std;

int calcDist(int t1, int t2){
    int dif = t2-t1;
    float dist = dif*0.034/2
    return dist;
}

int getDist(){
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(11);
    digitalWrite(TRIGGER_PIN, LOW);
    int t1 = esp_timer_get_time();
    while(digitalRead(ECHO_PIN) != 1){}
    int t2 = esp_timer_get_time();
    return calcDist(t1, t2);
}

void setDist(bool opt){
    if(opt) this->dist = getDist();
    else{
        string temp = serial.readString();
        this->dist = stoi(temp);
        printf("Insira a altura em cm: %d\n", a);
        printf("Distancia configurada\n\n");
    }
}

void getAltura(){
    int dist = getDist();
    altura = this->dist - dist;
    printf("A pessoa em questao tem %d cm de altura", altura);
}