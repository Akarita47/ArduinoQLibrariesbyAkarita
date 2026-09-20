#ifndef BAREMETAL_GPIO_H
#define BAREMETAL_GPIO_H

#include "stm32u5xx.h"
#include <stdint.h>  // Para que reconozca uint8_t

// Macros de Configuración
#define OUTPUT      1U
#define INPUT       0U
#define ALTER_FUNC  2U
#define ANALOG      3U

#define PUSHPULL    0U
#define OPENDRAIN   1U

#define NO_PULL     0U
#define PULL_UP     1U
#define PULL_DOWN   2U

#define LOW         0U
#define HIGH        1U

// Prototipos de Funciones
void GPIOMode(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode);
void GPIOOutputMode(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t outmode, uint8_t selectmode);
void GPIOWrite(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t value);
uint8_t GPIORead(GPIO_TypeDef *GPIOx, uint8_t pin);
void GPIOToggle(GPIO_TypeDef *GPIOx, uint8_t pin);

#endif // BAREMETAL_GPIO_H