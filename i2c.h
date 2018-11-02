/********************************************************************************
*    Muti-include-prevent Section  
********************************************************************************/
#ifndef _BSP_I2C_H_
#define _BSP_I2C_H_
/********************************************************************************
*    Include File Section
********************************************************************************/
#include "stm32f10x.h"

/********************************************************************************
*    Macro Define Section
********************************************************************************/
#define RCC_I2C_ClockCmd     RCC_APB1PeriphClockCmd
#define RCC_GPIO_ClockCmd    RCC_APB2PeriphClockCmd

#define SCL_GPIO_MODE    GPIO_Mode_AF_OD
#define SCL_GPIO_Pin     GPIO_Pin_6
#define SCL_GPIO_Speed   GPIO_Speed_50Mhz
#define SCL_RCC_CLK      RCC_APB2Periph_GPIOC
#define SCL_PORT         GPIOA

#define SDA_GPIO_MODE    GPIO_Mode_AF_OD
#define SDA_GPIO_Pin     GPIO_Pin_7
#define SDA_GPIO_Speed   GPIO_Speed_50Mhz
#define SDA_RCC_CLK      RCC_APB2Periph_GPIOC  
#define SDA_PORT         GPIOA

#define Macro_Mode                   I2C_Mode_I2C
#define	Macro_ClockSpeed             400000
#define	Macro_OwnAddress1            0xaa
#define Macro_DutyCycle              I2C_DutyCycle_2
#define Macro_Ack                    I2C_Ack_Enable 
#define Macro_AcknowledgedAddress    I2C_AcknowledgedAddress_7bit

/********************************************************************************
*    Prototype Declare Section
********************************************************************************/

void I2C_Conf(void);

void I2C_WrSr(void);/*  */
void I2C_WrStp(void);/*  */
void I2C_WrAddr(uint8_t page_addr,uint8_t column_addr);
void I2C_WrCmd(uint8_t byte);/* Write the Command to SSD1306 in i2c protocol */
void I2C_WrByte(uint8_t byte);/* Write the Data to SSD1306 in i2c protocol */
void I2C_DisplayInit(void);/* Init the oled display */

#endif
