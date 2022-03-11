#include "MyStm32f407xx.h"

void delay(void)
{
	for (uint32_t i=0; i<500000; i++);
}

int main(void)
{
	int a=0;
	GPIO_Handle_t Gpiobtn;
	Gpiobtn.pGPIOx = GPIOA;
	Gpiobtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	Gpiobtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	Gpiobtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpiobtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&Gpiobtn);

	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))
		{
			a++;
		}
		if(a==1)
		{
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 1);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 1);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 1);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 1);
		}
		else if(a==2)
		{
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0);
		}
		else if(a==3)
		{
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 1);
		}
		else if(a<=4)
		{
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 1);
			a=0;
		}
	}
}