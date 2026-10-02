#ifndef configLED_H_
#define configLED_H_
#include "RTE_Components.h"
#include CMSIS_device_header

// Mascara
#define MASK(x) (1 << (x))

// Pines de entrada (joystick)
#define PIN_U 9
#define PIN_D 12
#define PIN_L 6
#define PIN_R 11
#define PIN_S 4

// Pines de salida (LEDs)
#define PIN_LD1 7
#define PIN_LD2 6
#define PIN_LD3 5
#define PIN_LD4 1
#define PIN_LD7 0

void habilitar_clock(); // Habilitar la señal de reloj de los GPIO A B

void config_joystick(); // Configurar los pines de JOYSTICK como entrada (MODER = 00) con pull-down (PUPDR = 10)

void config_LEDs(); // Configurar los pines LEDs como salida (MODER = 01)

// Leer inputs del joystick
int up();
int down();
int left();
int right();
int selection();

// Control de LEDs
void encender(int pin);
void apagar_led(int pin);

void apagar();


#endif /* configLED_H_ */