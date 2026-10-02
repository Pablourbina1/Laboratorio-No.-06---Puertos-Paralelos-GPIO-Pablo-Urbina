#include "RTE_Components.h"
#include CMSIS_device_header
#include "stm32g431xx.h"

#include "configLED.h"

int main() {
    habilitar_clock();
    config_joystick();
    config_LEDs();

    while (1){
        if (up()){
            encender(PIN_LD1);
        } else if (down()){
            encender(PIN_LD2);
        } else if (left()){
            encender(PIN_LD3);
        } else if (right()){
            encender(PIN_LD4);
        } else if (selection()){
            encender(PIN_LD7);
        } else {
            apagar();
        }
    }
}
