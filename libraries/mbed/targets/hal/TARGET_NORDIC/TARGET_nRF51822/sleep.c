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
#include "sleep_api.h"
#include "cmsis.h"
#include "mbed_interface.h"

void sleep(void) {
    // ensure debug is disconnected if semihost is enabled....
   // mbed_interface_disconnect();
    
    NRF_POWER->TASKS_LOWPWR=1;
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    
    // wait for interrupt
    __WFI();
}

void deepsleep(void) {
    
    // PCON[PD] set to deepsleep
   // sleep();
	NRF_POWER->TASKS_LOWPWR=1;
	SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
	__WFI();
}
