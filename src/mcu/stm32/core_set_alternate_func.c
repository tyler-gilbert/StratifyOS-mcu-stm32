/* Copyright 2011-2016 Tyler Gilbert; 
 * This file is part of Stratify OS.
 *
 * Stratify OS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Stratify OS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Stratify OS.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * 
 */

#include "hal.h"

#include <mcu/core.h>
#include <mcu/debug.h>

#if defined __stm32f446xx

#define TOTAL_ENTRIES 16

typedef struct {
	u16 entry[TOTAL_ENTRIES];
} alternate_function_entry_t;

#define ENTRY(function, port) (port<<8|function)
#define RESERVED_ (ENTRY(CORE_PERIPH_RESERVED, 0))
#define ENTRY_GET_FUNCTION(entry) (entry & 0xFF)
#define ENTRY_GET_PORT(entry) ( entry >> 8)

#define E_TMR_(port) ENTRY(CORE_PERIPH_TMR,(port-1))
#define E_TMR(port) ENTRY(CORE_PERIPH_TMR,(port-1))
#define E_UART(port) ENTRY(CORE_PERIPH_UART,(port-1))
#define E_USRT(port) ENTRY(CORE_PERIPH_UART,(port-1))
#define E_I2S_(port) ENTRY(CORE_PERIPH_I2S,(port-1))
#define E_SYS_(port) ENTRY(CORE_PERIPH_SYS,(port-1))
#define E_QSPI(port) ENTRY(CORE_PERIPH_QSPI,(port-1))
#define E_SPI_(port) ENTRY(CORE_PERIPH_SPI,(port-1))
#define E_USB_(port) ENTRY(CORE_PERIPH_USB,(port-1))
#define E_LCD_(port) ENTRY(CORE_PERIPH_LCD,(port-1))
#define E_FMC_(port) ENTRY(CORE_PERIPH_LCD,(port-1))
#define E_MCO_(port) ENTRY(CORE_PERIPH_LCD,(port-1))
#define E_I2C_(port) ENTRY(CORE_PERIPH_I2C,(port-1))
#define E_HDMI(port) ENTRY(CORE_PERIPH_I2C,(port-1))
#define E_CAN_(port) ENTRY(CORE_PERIPH_CAN,(port-1))
#define E_JTAG(port) ENTRY(CORE_PERIPH_JTAG,(port-1))
#define E_RTC_(port) ENTRY(CORE_PERIPH_RTC,(port-1))
#define E_SPDF(port) ENTRY(CORE_PERIPH_RTC,(port-1))
#define E_SDIO(port) ENTRY(CORE_PERIPH_RTC,(port-1))
#define E_TRAC(port) ENTRY(CORE_PERIPH_TRACE,(port-1))
#define E_FMP_(port) ENTRY(CORE_PERIPH_I2C,(port-1))


#define TOTAL_PINS (7*16+2)

const alternate_function_entry_t alternate_function_table[TOTAL_PINS] = {
		//   0           1          2          3          4         5           6         7          8           9          10        11         12          13        14          15
		{{ RESERVED_, E_TMR_(2), E_TMR_(5), E_TMR_(8), RESERVED_, RESERVED_, RESERVED_, E_USRT(2), E_USRT(4), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA0
		{{ RESERVED_, E_TMR_(2), E_TMR_(5), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(2), E_USRT(4), E_QSPI(4), E_I2S_(4), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA1
		{{ RESERVED_, E_TMR_(2), E_TMR_(5), E_TMR_(9), RESERVED_, RESERVED_, RESERVED_, E_USRT(2), E_I2S_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA2
		{{ RESERVED_, E_TMR_(2), E_TMR_(5), E_TMR_(8), RESERVED_, RESERVED_, E_I2S_(1), E_USRT(2), RESERVED_, RESERVED_, E_USB_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA3
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(1), RESERVED_, E_SPI_(3), E_USRT(4), E_QSPI(4), E_I2S_(4), RESERVED_, E_USB_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PA4
		{{ RESERVED_, E_TMR_(2), RESERVED_, E_TMR_(8), RESERVED_, E_SPI_(1), RESERVED_, E_USRT(2), E_I2S_(2), RESERVED_, E_USB_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA5
		{{ RESERVED_, E_TMR_(1), E_TMR_(3), E_TMR_(8), RESERVED_, E_SPI_(1), E_I2S_(2), RESERVED_, RESERVED_, E_TMR(13), RESERVED_, RESERVED_, RESERVED_, E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PA6
		{{ RESERVED_, E_TMR_(1), E_TMR_(3), E_TMR_(8), RESERVED_, E_SPI_(1), RESERVED_, RESERVED_, RESERVED_, E_TMR(14), RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PA7
		{{ E_MCO_(1), E_TMR_(1), RESERVED_, RESERVED_, E_I2C_(3), RESERVED_, RESERVED_, E_USRT(1), RESERVED_, RESERVED_, E_USB_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA8
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, E_I2C_(3), E_SPI_(2), E_I2S_(1), E_USRT(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PA9
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(1), RESERVED_, RESERVED_, E_USB_(1), RESERVED_, RESERVED_, E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PA10
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(1), RESERVED_, E_CAN_(1), E_USB_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA11
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(1), E_I2S_(2), E_CAN_(1), E_USB_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA12
		{{ E_JTAG(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA13
		{{ E_JTAG(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA14
		{{ E_JTAG(1), E_TMR_(2), RESERVED_, RESERVED_, E_HDMI(1), E_SPI_(1), E_SPI_(3), RESERVED_, E_UART(4), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PA15

		//   0           1          2          3          4         5           6         7          8           9          10        11         12          13        14          15
		{{ RESERVED_, E_TMR_(1), E_TMR_(3), E_TMR_(8), RESERVED_, RESERVED_, RESERVED_, E_SPI_(3), E_UART(4), RESERVED_, E_USB_(1), RESERVED_, E_SDIO(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PB0
		{{ RESERVED_, E_TMR_(1), E_TMR_(3), E_TMR_(8), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USB_(1), RESERVED_, E_SDIO(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PB1
		{{ RESERVED_, E_TMR_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(1), E_SPI_(3), RESERVED_, E_QSPI(1), E_USB_(1), RESERVED_, E_SDIO(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PB2
		{{ E_JTAG(1), E_TMR_(2), RESERVED_, RESERVED_, E_I2C_(2), E_SPI_(1), E_SPI_(3), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PB3
		{{ E_JTAG(1), RESERVED_, E_TMR_(3), RESERVED_, E_I2C_(2), E_SPI_(1), E_SPI_(3), E_SPI_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PB4
		{{ RESERVED_, RESERVED_, E_TMR_(3), RESERVED_, E_I2C_(1), E_SPI_(1), E_SPI_(3), RESERVED_, RESERVED_, E_CAN_(2), E_USB_(1), RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PB5
		{{ RESERVED_, RESERVED_, E_TMR_(4), E_HDMI(1), E_I2C_(1), RESERVED_, RESERVED_, E_USRT(1), RESERVED_, E_CAN_(2), E_USB_(1), RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PB6
		{{ RESERVED_, RESERVED_, E_TMR_(4), RESERVED_, E_I2C_(1), RESERVED_, RESERVED_, E_USRT(1), E_SPDF(1), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PB7
		{{ RESERVED_, E_TMR_(2), E_TMR_(4), E_TMR(10), E_I2C_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_CAN_(1), RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PB8
		{{ RESERVED_, E_TMR_(2), E_TMR_(4), E_TMR(11), E_I2C_(1), E_SPI_(2), E_I2S_(1), RESERVED_, RESERVED_, E_CAN_(1), RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PB9
		{{ RESERVED_, E_TMR_(2), RESERVED_, RESERVED_, E_I2C_(2), E_SPI_(2), E_I2S_(1), E_USRT(3), RESERVED_, RESERVED_, E_USB_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PB10
		{{ RESERVED_, E_TMR_(2), RESERVED_, RESERVED_, E_I2C_(2), RESERVED_, RESERVED_, E_USRT(3), E_I2S_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PB11
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, E_I2C_(2), E_SPI_(2), E_I2S_(1), E_USRT(3), RESERVED_, E_CAN_(2), E_USB_(1), RESERVED_, E_USB_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PB12
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, E_SPI_(2), RESERVED_, E_USRT(3), RESERVED_, E_CAN_(2), E_USB_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PB13
		{{ RESERVED_, E_TMR_(1), RESERVED_, E_TMR_(8), RESERVED_, E_SPI_(2), RESERVED_, E_USRT(3), RESERVED_, E_TMR(12), RESERVED_, RESERVED_, E_USB_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PB14
		{{ E_RTC_(1), E_TMR_(1), RESERVED_, E_TMR_(8), RESERVED_, E_SPI_(2), RESERVED_, RESERVED_, RESERVED_, E_TMR(12), RESERVED_, RESERVED_, E_USB_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PB15

		//   0           1          2          3          4         5           6         7          8           9          10        11         12          13        14          15
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(1), RESERVED_, RESERVED_, RESERVED_, E_USB_(1), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PC0
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(3), E_I2S_(1), E_SPI_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PC1
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USB_(1), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PC2
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USB_(1), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PC3
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(1), RESERVED_, RESERVED_, E_SPDF(1), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PC4
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(3), E_SPDF(1), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PC5
		{{ RESERVED_, RESERVED_, E_TMR_(3), E_TMR_(8), E_FMP_(1), E_I2S_(2), RESERVED_, RESERVED_, E_USRT(6), RESERVED_, RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PC6
		{{ RESERVED_, RESERVED_, E_TMR_(3), E_TMR_(8), E_FMP_(1), E_SPI_(2), E_I2S_(3), E_SPDF(1), E_USRT(6), RESERVED_, RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PC7
		{{ E_TRAC(1), RESERVED_, E_TMR_(3), E_TMR_(8), RESERVED_, RESERVED_, RESERVED_, E_UART(5), E_USRT(6), RESERVED_, RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PC8
		{{ E_MCO_(2), RESERVED_, E_TMR_(3), E_TMR_(8), E_I2C_(3), E_I2S_(1), RESERVED_, E_UART(5), RESERVED_, E_QSPI(1), RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PC9
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(3), E_USRT(3), E_UART(4), E_QSPI(1), RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PC10
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(3), E_USRT(3), E_UART(4), E_QSPI(1), RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PC11
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2C_(2), RESERVED_, E_SPI_(3), E_USRT(3), E_UART(4), RESERVED_, RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PC12
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PC13
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PC14
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PC15

		//   0           1          2          3          4         5           6         7          8           9          10        11         12          13        14          15
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), E_SPI_(3), RESERVED_, RESERVED_, E_CAN_(1), RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD0
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(2), RESERVED_, E_CAN_(1), RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD1
		{{ RESERVED_, RESERVED_, E_TMR_(3), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_UART(5), RESERVED_, RESERVED_, RESERVED_, E_SDIO(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PD2
		{{ E_TRAC(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(2), RESERVED_, E_USRT(2), RESERVED_, E_QSPI(1), RESERVED_, RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PD3
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD4
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD5
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(3), E_I2S_(1), E_USRT(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PD6
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(2), E_SPDF(1), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD7
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(3), E_SPDF(1), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD8
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(3), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD9
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(3), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD10
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMP_(1), RESERVED_, RESERVED_, E_USRT(3), RESERVED_, E_QSPI(1), E_I2S_(2), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD11
		{{ RESERVED_, RESERVED_, E_TMR_(4), RESERVED_, E_FMP_(1), RESERVED_, RESERVED_, E_USRT(3), RESERVED_, E_QSPI(1), E_I2S_(2), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD12
		{{ RESERVED_, RESERVED_, E_TMR_(4), RESERVED_, E_FMP_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_QSPI(1), E_I2S_(2), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD13
		{{ RESERVED_, RESERVED_, E_TMR_(4), RESERVED_, E_FMP_(1), RESERVED_, RESERVED_, RESERVED_, E_I2S_(2), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD14
		{{ RESERVED_, RESERVED_, E_TMR_(4), RESERVED_, E_FMP_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PD15

		//   0           1          2          3          4         5           6         7          8           9          10        11         12          13        14          15
		{{ RESERVED_, RESERVED_, E_TMR_(4), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(2), RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PE0
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PE1
		{{ E_TRAC(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), E_I2S_(1), RESERVED_, RESERVED_, E_QSPI(1), RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE2
		{{ E_TRAC(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE3
		{{ E_TRAC(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), E_I2S_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PE4
		{{ E_TRAC(1), RESERVED_, RESERVED_, E_TMR_(9), RESERVED_, E_SPI_(4), E_I2S_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PE5
		{{ E_TRAC(1), RESERVED_, RESERVED_, E_TMR_(9), RESERVED_, E_SPI_(4), E_I2S_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PE6
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_UART(5), RESERVED_, E_QSPI(1), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE7
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_UART(5), RESERVED_, E_QSPI(1), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE8
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_QSPI(1), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE9
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_QSPI(1), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE10
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(2), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE11
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(2), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE12
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(2), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE13
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(2), RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE14
		{{ RESERVED_, E_TMR_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PE15

		//   0           1          2          3          4         5           6         7          8           9          10        11         12          13        14          15
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2C_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF0
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2C_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF1
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2C_(2), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF2
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF3
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF4
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF5
		{{ RESERVED_, RESERVED_, RESERVED_, E_TMR(10), RESERVED_, RESERVED_, E_I2S_(1), RESERVED_, RESERVED_, E_QSPI(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PF6
		{{ RESERVED_, RESERVED_, RESERVED_, E_TMR(11), RESERVED_, RESERVED_, E_I2S_(1), RESERVED_, RESERVED_, E_QSPI(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PF7
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(1), RESERVED_, RESERVED_, E_TMR(13), E_QSPI(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PF8
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(1), RESERVED_, RESERVED_, E_TMR(14), E_QSPI(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PF9
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PF10
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(2), RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PF11
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF12
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMP_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF13
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMP_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF14
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMP_(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PF15

		//   0           1          2          3          4         5           6         7          8           9          10        11         12          13        14          15
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG0
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG1
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG2
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG3
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG4
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG5
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_QSPI(1), RESERVED_, RESERVED_, E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PG6
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(6), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PG7
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPDF(1), E_USRT(6), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG8
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPDF(1), E_USRT(6), E_QSPI(1), E_I2S_(2), RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PG9
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_I2S_(2), RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PG10
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), E_SPDF(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PG11
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), E_SPDF(1), E_USRT(6), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG12
		{{ E_TRAC(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), RESERVED_, E_USRT(6), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG13
		{{ E_TRAC(1), RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SPI_(4), RESERVED_, E_USRT(6), E_QSPI(1), RESERVED_, RESERVED_, E_FMC_(1), RESERVED_, RESERVED_, E_SYS_(1) }}, //PG14
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_USRT(6), RESERVED_, RESERVED_, RESERVED_, E_FMC_(1), E_LCD_(1), RESERVED_, E_SYS_(1) }}, //PG15


		//   0           1          2          3          4         5           6         7          8           9          10        11         12          13        14          15
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PH0
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }} //PH1

		/*
		//   0           1          2          3          4         5           6         7          8           9          10        11         12          13        14          15
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX0
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX1
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX2
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX3
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX4
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX5
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX6
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX7
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX8
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX9
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX10
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX11
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX12
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX13
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX14
		{{ RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, RESERVED_, E_SYS_(1) }}, //PX15
		 */


};


int hal_get_alternate_function(int gpio_port, int pin, core_periph_t function, int periph_port){
	int i;
	alternate_function_entry_t entry;
	u16 value = gpio_port * 16 + pin;
	i = -1;
	if( value < TOTAL_PINS ){
		entry = alternate_function_table[value];
		value = -1;
		for(i = 0; i < TOTAL_ENTRIES; i++){
			if ( (function == ENTRY_GET_FUNCTION(entry.entry[i])) &&
					(periph_port == ENTRY_GET_PORT(entry.entry[i])) ){
				//this is a valid pin
				value = i;
				break;
			}
		}
	}
	return i;
}

int hal_set_alternate_pin_function(mcu_pin_t pin, core_periph_t function, int periph_port, int mode, int speed, int pull){
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_TypeDef * gpio_regs;
	int alternate_function;

	gpio_regs = hal_get_pio_regs(pin.port);
	if( gpio_regs == 0 ){
		return -1;
	}

	alternate_function =	hal_get_alternate_function(pin.port, pin.pin, function, periph_port);

	if( alternate_function < 0 ){
		return -1;
	}


	GPIO_InitStruct.Pin = (1<<pin.pin);
	GPIO_InitStruct.Mode = mode;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	GPIO_InitStruct.Alternate = alternate_function;
	HAL_GPIO_Init(gpio_regs, &GPIO_InitStruct);
	return 0;
}

int mcu_core_set_pinsel_func(const mcu_pin_t * pin, core_periph_t function, int periph_port){
	int mode;
	int speed = GPIO_SPEED_FREQ_LOW;
	int pull = GPIO_NOPULL;
	switch(function){
	default:
		mode = GPIO_MODE_AF_PP;
		break;
	case CORE_PERIPH_I2C:
		mode = GPIO_MODE_AF_OD;
		speed = GPIO_SPEED_FREQ_HIGH;
		break;
	case CORE_PERIPH_ADC:
	case CORE_PERIPH_DAC:
		mode = GPIO_MODE_ANALOG;
		break;
	case CORE_PERIPH_USB:
		mode = GPIO_MODE_AF_PP;
		speed = GPIO_SPEED_FREQ_VERY_HIGH;
		pull = GPIO_NOPULL;
		break;
	}
	return hal_set_alternate_pin_function(*pin, function, periph_port, mode, speed, pull);
}

#endif
