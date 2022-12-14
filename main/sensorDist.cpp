#include "sensorDist.hpp"
#include "serial.hpp"
#include <string>
#include <iostream>
#include "esp_timer.h"
#include "digital.h"
#include "delay.h"

gpio_num_t TRIGGER_PIN = PIN12;
gpio_num_t ECHO_PIN = PIN13;

using namespace std;
SensorDist::SensorDist(){
    digital.pinMode(TRIGGER_PIN, OUTPUT);
    digital.pinMode(ECHO_PIN, INPUT);
    digital.digitalWrite(TRIGGER_PIN, LOW);
    digital.digitalWrite(ECHO_PIN, LOW);
}

int calcDist(int t1, int t2){
    int dif = t2-t1;
    return dif*0.034/2;
}

int getDist(){
    digital.digitalWrite(TRIGGER_PIN, HIGH);
    delay_us(11);
    digital.digitalWrite(TRIGGER_PIN, LOW);
    int t1 = esp_timer_get_time();
    while(digital.digitalRead(ECHO_PIN) != 1){}
    int t2 = esp_timer_get_time();
    return calcDist(t1, t2);
}

void SensorDist::setDist(bool opt){
    if(opt) this->dist = getDist();
    else{
        char buffer[3];
        serial.readString((uint8_t*) buffer, 3);
        this->dist = stoi(buffer);
        printf("Insira a altura em cm: %d\n", this->dist);
        printf("Distancia configurada\n\n");
    }
}

void SensorDist::getAltura(){
    int dist = getDist();
    int altura = this->dist - dist;
    printf("A pessoa em questao tem %d cm de altura", altura);
}