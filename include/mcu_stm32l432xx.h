/* Copyright 2011-2018 Tyler Gilbert;
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
 * along with Stratify OS.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef MCU_STM32L432XX_H_
#define MCU_STM32L432XX_H_

#include <mcu/types.h>
#include "cmsis/stm32l4xx.h"
#include "cmsis/stm32l432xx.h"


#define MCU_NO_HARD_FAULT 1

#define MCU_ADC_API 0
#define MCU_ADC_PORTS 1
#define MCU_ADC_REGS { ADC1 }
#define MCU_ADC_IRQS { ADC1_IRQn }
#define MCU_ADC_CHANNELS 21

#define MCU_DAC_API 0
#define MCU_DAC_PORTS 2
#define MCU_DAC_REGS { DAC, DAC }
#define MCU_DAC_IRQS { TIM6_DAC_IRQn, TIM6_DAC_IRQn }
#define MCU_DAC_PORTS 2


#define MCU_ENET_PORTS 1
#define MCU_FLASH_PORTS 1
#define MCU_MEM_PORTS 1

#define MCU_I2C_API 0
#define MCU_I2C_PORTS 3
#define MCU_I2C_REGS { I2C1, 0, I2C3 }
#define MCU_I2C_IRQS { I2C1_EV_IRQn, -1, I2C3_EV_IRQn }
#define MCU_I2C_ER_IRQS { I2C1_ER_IRQn, -1, I2C3_ER_IRQn }

#define MCU_CORE_PORTS 1
#define MCU_EEPROM_PORTS 0
#define MCU_SPI_API 0
#define MCU_SPI_PORTS 3
#define MCU_SPI_REGS { SPI1, 0, SPI3 }
#define MCU_SPI_IRQS { SPI1_IRQn, -1, SPI3_IRQn }

//I2S is available on 2 SPI ports SPI2 and SPI3
#define MCU_I2S_SPI_PORTS 0


#define MCU_SAI_API 0
#define MCU_SAI_PORTS 0

#define MCU_SDIO_API 0
#define MCU_SDIO_PORTS 0
#define MCU_SDIO_REGS { SDMMC1 }
#define MCU_SDIO_IRQS { SDMMC1_IRQn }
#define SDIO_TypeDef SDMMC_TypeDef

#define MCU_TMR_PORTS 7
#define MCU_TMR_REGS { TIM1, TIM2, 0, 0, 0, TIM6, TIM7  }
#define MCU_TMR_IRQS { TIM1_CC_IRQn, TIM2_IRQn, -1, -1, -1, TIM6_DAC_IRQn, TIM7_IRQn  }

#define MCU_PIO_PORTS 8
#define MCU_PIO_REGS { GPIOA, GPIOB, GPIOC, 0, 0, 0, 0, GPIOH  }
#define MCU_PIO_IRQS { 0 }

#define MCU_UART_PORTS 2
#define MCU_UART_REGS { USART1, USART2 }
#define MCU_UART_IRQS { USART1_IRQn, USART2_IRQn }

#define MCU_USB_API 0
#define MCU_USB_PORTS 1
#define MCU_USB_REGS { USB }
#define MCU_USB_IRQS { USB_IRQn }

#define USB_OTG_GlobalTypeDef USB_TypeDef

#define MCU_DMA_PORTS 2
#define DMA_Stream_TypeDef DMA_Channel_TypeDef
#define DMA_CHANNEL_0 DMA_REQUEST_0
#define DMA_CHANNEL_1 DMA_REQUEST_1
#define DMA_CHANNEL_2 DMA_REQUEST_2
#define DMA_CHANNEL_3 DMA_REQUEST_3
#define DMA_CHANNEL_4 DMA_REQUEST_4
#define DMA_CHANNEL_5 DMA_REQUEST_5
#define DMA_CHANNEL_6 DMA_REQUEST_6
#define DMA_CHANNEL_7 DMA_REQUEST_7

#define MCU_RTC_PORTS 1
#define MCU_RTC_REGS { RTC }
#define MCU_RTC_IRQS { RTC_Alarm_IRQn }

#define DEV_USB_LOGICAL_ENDPOINT_COUNT 4

#define MCU_LAST_IRQ CRS_IRQn
#define MCU_MIDDLE_IRQ_PRIORITY 8


#define MCU_RAM_PAGES 112
#define MCU_DELAY_FACTOR 12
#define MCU_TOTAL_PINS (7*16+2)


#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#endif /* MCU_STM32L432XX_H_ */
