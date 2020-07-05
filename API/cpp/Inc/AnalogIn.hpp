#pragma once

typedef struct ADCPinName {
    PinName pin_name;
    ADC_TypeDef* adc;
    uint32_t channel;
} ADCPinName;

class AnalogIn {
  private:

      ADC_HandleTypeDef ADC_InitStruct = {0};
      uint32_t readValue;
      uint16_t unsignedReadValue;
      void ADC_Init(ADCPinName pin);

   public:
      AnalogIn(ADCPinName pin);
      ~AnalogIn();

      uint32_t read();
      uint16_t read_u16();
      float getVoltage();
      float getPercent();
};
