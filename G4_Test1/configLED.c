#include "configLED.h"
#include "stm32g431xx.h"
#include <stdio.h>

void habilitar_clock(){
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN;
}

void config_joystick(){
    // Configurar los pines de entrada
    GPIOA -> MODER &= ~(3 << (2 * PIN_U));
    GPIOA -> MODER &= ~(3 << (2 * PIN_D));
    GPIOB -> MODER &= ~(3 << (2 * PIN_L));
    GPIOA -> MODER &= ~(3 << (2 * PIN_R));
    GPIOB -> MODER &= ~(3 << (2 * PIN_S));

    // Configurar pull-down, primero se limpia PUPDR y despues se pone en pull-down
    GPIOA -> PUPDR &= ~(3 << (2 * PIN_U));
    GPIOA -> PUPDR |=  (2 << (2 * PIN_U));

    GPIOA -> PUPDR &= ~(3 << (2 * PIN_D));
    GPIOA -> PUPDR |=  (2 << (2 * PIN_D));

    GPIOB -> PUPDR &= ~(3 << (2 * PIN_L));
    GPIOB -> PUPDR |=  (2 << (2 * PIN_L));

    GPIOA -> PUPDR &= ~(3 << (2 * PIN_R));
    GPIOA -> PUPDR |=  (2 << (2 * PIN_R));

    GPIOB -> PUPDR &= ~(3 << (2 * PIN_S));
    GPIOB -> PUPDR |=  (2 << (2 * PIN_S));
}

void config_LEDs(){
    // Configurar los pines de salida, primero se limpia y despues se pone en 01
    GPIOA -> MODER &= ~(3 << (2 * PIN_LD1));
    GPIOA -> MODER |= (1 << (2 * PIN_LD1));

    GPIOA -> MODER &= ~(3 << (2 * PIN_LD2));
    GPIOA -> MODER |= (1 << (2 * PIN_LD2));

    GPIOA -> MODER &= ~(3 << (2 * PIN_LD3));
    GPIOA -> MODER |= (1 << (2 * PIN_LD3));

    GPIOA -> MODER &= ~(3 << (2 * PIN_LD4));
    GPIOA -> MODER |= (1 << (2 * PIN_LD4));

    GPIOA -> MODER &= ~(3 << (2 * PIN_LD7));
    GPIOA -> MODER |= (1 << (2 * PIN_LD7));
}

int up(){
    if((GPIOA -> IDR & MASK(PIN_U))){
        return 1;
    }
    return 0;
}

int down(){
    if((GPIOA -> IDR & MASK(PIN_D))){
        return 1;
    }
    return 0;
}

int left(){
    if((GPIOB -> IDR & MASK(PIN_L))){
        return 1;
    }
    return 0;
}

int right(){
    if((GPIOA -> IDR & MASK(PIN_R))){
        return 1;
    }
    return 0;
}

int selection(){
    if((GPIOB -> IDR & MASK(PIN_S))){
        return 1;
    }
    return 0;
}

// Encender y apagar los LEDs

void encender(int pin){
    GPIOA -> ODR |= (MASK(pin));
}

void apagar_led(int pin){
    GPIOA -> ODR &= ~(MASK(pin));
}

void apagar(){
    apagar_led(PIN_LD1);
    apagar_led(PIN_LD2);
    apagar_led(PIN_LD3);
    apagar_led(PIN_LD4);
    apagar_led(PIN_LD7);
}