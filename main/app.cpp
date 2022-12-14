#include <stdio.h>
#include <string>
#include <time.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "serial.hpp"
#include "delay.h"
#include <inttypes.h> 
#include "digital.h"
#include "sensorDist.hpp"

extern "C" void app_main() ;
void app_main(){
	digital.pinMode(PIN16, OUTPUT);
    digital.pinMode(PIN5, INPUT);
    digital.digitalWrite(PIN16, LOW);
    digital.digitalWrite(PIN5, LOW);
	delay_ms(2000);
	SensorDist sensor;
	serial.begin(9600);
	while(1){
		printf("\n      Menu      ");
		printf("\n[1] - Ajusta set point - Manual");
		printf("\n[2] - Ajusta set point - Automatico");
		printf("\n[3] - Mede altura pessoal\n");
		char opt[1];
		serial.readString((uint8_t*)opt, 1);
		switch(opt[0]){
			case '1':
				printf("Caso 1\n");
				sensor.setDist(false);
				break;
			case '2':
				printf("Caso 2\n");
				sensor.setDist(true);
				printf("Altura settada em %d cm\n", sensor.distSensor);
				break;
			case '3':
				printf("Caso 3\n");
				sensor.getAltura();
				break;
			default:
				printf("Opcao invalida, selecione outro valor\n");
		}
	}
}