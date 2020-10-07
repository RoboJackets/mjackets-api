#pragma once

#include "mJackets.hpp"

/**
 * @brief Configuration struct to initialize a pin as an analog input
 * 
 */
typedef struct {
    PinName pin_name;
    ADC_TypeDef* adc;
    uint32_t channel;
} ADCPinName;

class AnalogIn {
  private:
      /**
       * @brief ADC_HandleTypeDef struct containing the ADC config parameters
       * 
       */
      ADC_HandleTypeDef ADC_InitStruct = {0};
      
      /**
       * @brief Raw ADC value
       * 
       */
      uint32_t readValue;

      /**
       * @brief Unsigned 16-bit ADC value
       * 
       */
      uint16_t unsignedReadValue;

      /**
       * @brief Initializes the GPIO pin as an analog input
       * 
       * @param pin 
       */
      void ADC_Init(ADCPinName pin);

   public:
      /**
       * @brief Construct a new Analog In object
       * 
       * @param pin 
       */
      AnalogIn(ADCPinName pin);

      /**
       * @brief Destroy the Analog In object
       * 
       */
      ~AnalogIn();

      /**
       * @brief Returns the current ADC register value
       * 
       * @return uint32_t 
       */
      uint32_t read();

      /**
       * @brief Returns the current 16-bit ADC register value
       * 
       * @return uint16_t 
       */
      uint16_t read_u16();

      /**
       * @brief Returns the current voltage applied to the pin
       * 
       * @return float 
       */
      float getVoltage();

      /**
       * @brief Returns the current ADC value scaled 0-100%
       * 
       * @return float 
       */
      float getPercent();
};
