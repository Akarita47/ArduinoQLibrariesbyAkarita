#include "stm32u5xx.h"

void GPIOMode(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode) {
  // Configuramos PB4 como el mode q queremos
  GPIOx->MODER &= ~(3U << (pin * 2));  // Limpiamos los bits del registro
  GPIOx->MODER |= (mode << (pin * 2)); // Ponemos el binario del mode que deseamos
}

void GPIOOutputMode (GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t outmode,uint8_t selectmode){
  GPIOx->OTYPER &= ~(1U << pin); //Limpiamos el bit del registro
  GPIOx->OTYPER |= (outmode << pin); //Colocamos el valor del bit del OTYPE

  GPIOx->PUPDR &= ~(3U << (pin*2)); //Limpiamos los dos bits del registro
  GPIOx->PUPDR |= (selectmode << (pin*2));//Colocamos el valor de los dos bits de PUPDR
}

void GPIOWrite(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t value){
  GPIOx->BSRR = (1U << (pin + (!value * 16)));
}

uint8_t GPIORead (GPIO_TypeDef *GPIOx, uint8_t pin){
  if(GPIOx->IDR & (1U << pin)){
    return HIGH;
  }else{
    return LOW;
  }
}

void GPIOToggle(GPIO_TypeDef *GPIOx, uint8_t pin) {
    GPIOx->ODR ^= (1U << pin);
}