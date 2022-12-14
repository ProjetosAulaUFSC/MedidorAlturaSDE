#include <stdio.h>
#include "sensorDist.hpp"
#include "serial.hpp"
#include "esp_timer.h"
#include "digital.h"
#include "delay.h"
#include "driver/gpio.h"

gpio_num_t TRIGGER_PIN = PIN12;
gpio_num_t ECHO_PIN = PIN13;

int calcDist(int t1, int t2){
    int dif = t2-t1;
    return dif*0.034/2; // Delta_T(us)*340(m/s)*100(m->cm)/2(ida e frida)/1000000(us->s)
}

int getDist(){
    digital.digitalWrite(TRIGGER_PIN, HIGH);
    delay_us(20);
    digital.digitalWrite(TRIGGER_PIN, LOW);
    while(digital.digitalRead(ECHO_PIN) == 0){}
    int t1 = esp_timer_get_time();
    while(digital.digitalRead(ECHO_PIN) == 1){}
    int t2 = esp_timer_get_time();
    return calcDist(t1, t2);
}

void SensorDist::setDist(bool opt){
    if(opt) this->distSensor = getDist();
    else{
        char buffer[3];
        serial.readString((uint8_t*) buffer, 3);
        this->distSensor = stoi(buffer);
        printf("Insira a altura em cm: %d\n", this->distSensor);
        printf("Distancia configurada\n\n");
    }
}

void SensorDist::getAltura(){
    int distCalc = getDist();
    int altura = this->distSensor - distCalc;
    printf("A pessoa em questao tem %d cm de altura", altura);
}