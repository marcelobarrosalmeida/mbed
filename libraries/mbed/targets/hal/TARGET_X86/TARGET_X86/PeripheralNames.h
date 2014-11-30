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
#ifndef MBED_PERIPHERALNAMES_H
#define MBED_PERIPHERALNAMES_H

//#include "cmsis.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    OSC32KCLK = 0,
    RTC_CLKIN = 2
} RTCName;

typedef enum {
    UART_0 = 0,
    UART_1 = 1,
    UART_2 = 2,
} UARTName;

typedef enum {
    I2C_0 = 0,
    I2C_1 = 1,
} I2CName;

typedef enum {
    PWM_1  = 1,
    PWM_2  = 2,
    PWM_3  = 3,
    PWM_4  = 4,
} PWMName;

typedef enum {
    ADC0_SE0  =  0,
    ADC0_SE3  =  3,
} ADCName;

typedef enum {
    DAC_0 = 0
} DACName;


typedef enum {
    SPI_0 = 0,
    SPI_1 = 1,
} SPIName;

#ifdef __cplusplus
}
#endif

#endif
