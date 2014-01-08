/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "analogin_api.h"
#include "cmsis.h"
#include "pinmap.h"
#include "error.h"

#define ANALOGIN_MEDIAN_FILTER      1

#define ADC_10BIT_RANGE             0x3FF

#define ADC_RANGE    ADC_10BIT_RANGE

static const PinMap PinMap_ADC[] = {
   // {p26, ADC0_0, 1},
  //  {p27, ADC0_0, 2},
    {p1, ADC0_0, 4},
    {p2, ADC0_0, 8},
    {p3, ADC0_0, 16},
    {p4, ADC0_0, 32},
    {p5, ADC0_0, 64},
    {p6, ADC0_0, 128},
    {NC   , NC    , 0}
};

void analogin_init(analogin_t *obj, PinName pin) {
    obj->adc = (ADCName)((NRF_ADC_Type            *)pinmap_peripheral(pin, PinMap_ADC));
    if (obj->adc == (ADCName)NC) {
        error("ADC pin mapping failed");
    }
	
    int analogInputPin=0;
	const PinMap *map = PinMap_ADC;
	while (map->pin != NC) {
        if (map->pin == pin){
			analogInputPin = map->function;
			break;
		}
        map++;
    }
	
	NRF_ADC->ENABLE = ADC_ENABLE_ENABLE_Enabled; 
	NRF_ADC->CONFIG = (ADC_CONFIG_RES_10bit << ADC_CONFIG_RES_Pos) |
					  (ADC_CONFIG_INPSEL_AnalogInputOneThirdPrescaling<< ADC_CONFIG_INPSEL_Pos) |
					  (ADC_CONFIG_REFSEL_SupplyOneThirdPrescaling << ADC_CONFIG_REFSEL_Pos) |
					  (analogInputPin << ADC_CONFIG_PSEL_Pos) |
					  (ADC_CONFIG_EXTREFSEL_None << ADC_CONFIG_EXTREFSEL_Pos);	
}

uint16_t analogin_read_u16(analogin_t *obj) {
    NRF_ADC->TASKS_START = 1;
	while (((NRF_ADC->BUSY & ADC_BUSY_BUSY_Msk) >> ADC_BUSY_BUSY_Pos) == ADC_BUSY_BUSY_Busy)
	{
	}
	
    return (uint16_t)NRF_ADC->RESULT; // 10 bit
}

float analogin_read(analogin_t *obj) {
    uint16_t value = analogin_read_u16(obj);
    return (float)value * (1.0f / (float)ADC_RANGE);
}
