
/********************************************************************************
*    File Name    :    
*    Copyright    :
*    Module Name  :
*
*    CPU          :
*    RTOS         :
*  
*    Creste Date  :
*    Author       :
*
*    Abstract Description
********************************************************************************/
#include "bsp_i2c.h"

void I2C_Conf(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  I2C_InitTypeDef I2C_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;//SCL
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&GPIO_InitStruct);
	
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;//SDA
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
  I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStruct.I2C_ClockSpeed = 400000;
	I2C_InitStruct.I2C_OwnAddress1 = 0xaa;
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2; 
	I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	
  I2C_Init(I2C1,&I2C_InitStruct);
  I2C_Cmd(I2C1,ENABLE);
  
	/* The following data byte as a data which will be stored at the GDDRAM */
	I2C_SendData(I2C1,0xc0);//Send the control byte(0xc0)
  while (!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));//EV8_2 


  while(1)
  {
		I2C_SendData(I2C1,0x55);//Send the control byte(0x00)
    while (!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));//EV8_2 
		
	}

}

/**/
void I2C_WrSr(void)
{
	I2C_GenerateSTART(I2C1,ENABLE);//W_START_BIT
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT)); //EV5
  I2C_Send7bitAddress(I2C1,0x78,I2C_Direction_Transmitter);//W_ADDR
  while (!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)){}//EV6

}

void I2C_WrStp(void)
{
	I2C_GenerateSTOP(I2C1, ENABLE);//W_STOP_BIT
	
}






