#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "serial.h"
#include "delay.h"
#include <inttypes.h> 
#include "digital.h"
#include "sensorDist.hpp"

extern "C" void app_main() ;
void menu(){
	printf("\n\t\t\t Menu");
	printf("\n[1] - Ajusta set point - Manual");
	printf("\n[2] - Ajusta set point - Automatico");
	printf("\n[3] - Mede altura pessoal");
}

void app_main(){
	sensorDist sD();
	serial.begin(9600);
	while(1){
		menu();
		char opt = serial.readChar();
		printf("Opcao: %c\n", opt);
		switch(opt){
			case 1:
				sD.setPoint(false);
				break;
			case 2:
				sD.setPoint(true);
				break;
			case 3:
				sD.getAltura();
				break;
			default:
				printf("Opcao invalida, selecione outro valor\n");
		}
	}
}
// void app_main(){
// 	delay_ms(2000);
// 	serial.begin(9600);
// 	printf("\n\nRODANDO\n\n");
// 	int64_t t1, t2, diferenca;
// 	while (1){
//   	t1 = esp_timer_get_time();
// 		delay_us(1000);  
// 		t2 = esp_timer_get_time();
// 		diferenca =(t2-t1);
// 		printf("t1 = %ld t2 = %ld Diferenca vale %ld \n",(long)t1, (long)t2, (long)diferenca);
//    		vTaskDelay(2000/portTICK_PERIOD_MS);
//    	}
// }