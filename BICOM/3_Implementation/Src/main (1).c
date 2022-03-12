/* contibutions
   Abhishek- Main function,delay_function, counter_function, two(2)_pin_configuration, two(2) functions
   Vinayak- two(2)_pin_configuration, Two_functions, driver header_files , virtual implementation(qemu)
   */ 
#include "MyStm32f407xx.h"                              // Written  by Abhishek
#define Button ENABLE
void delay()
{
    for(int i=0; i<12000000; i++);
}
void onetime_press(int);
void twotime_press(int);
void threetime_press(int);
void fourtime_press(int);

int  main(){                  
	int a = 0;

	 GPIO_Handle_t Gpiobtn;      // All settings and configuration for switch
	    Gpiobtn.pGPIOx = GPIOA;                              
	    Gpiobtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;  //  configuration pin number 0 
	    Gpiobtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;     //  setting pinmode to input
	    Gpiobtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST; 
	    Gpiobtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD; 
	    GPIO_PeriClockControl(GPIOA, ENABLE); // setting clock to enable
	    GPIO_Init(&Gpiobtn);


    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Handle_t GpioLED1;
    GpioLED1.pGPIOx = GPIOD;  // setting GPIO to port D
    GpioLED1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12; // configuration pin number 0 (green_led)
    GpioLED1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;   // setting pin_mode to output
    GpioLED1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLED1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_Init(&GpioLED1);

    GPIO_Handle_t GpioLED2;                                            // Written by Vinayak
    GpioLED2.pGPIOx = GPIOD;  // setting GPIO to port D
    GpioLED2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13; //   configuration pin number 0 (orange_led)
    GpioLED2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;    // setting pin_mode to output
    GpioLED2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLED2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_Init(&GpioLED2);

    GPIO_Handle_t GpioLED3;
    GpioLED3.pGPIOx = GPIOD;  // setting GPIO to port D
    GpioLED3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;  //   configuration pin number 0 (red_led)
    GpioLED3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;      // setting pin_mode to output
    GpioLED3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLED3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_Init(&GpioLED3);

    GPIO_Handle_t GpioLED4;
    GpioLED4.pGPIOx = GPIOD; // setting GPIO to port D 
    GpioLED4.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;  //   configuration pin number 0 (blue_led)
    GpioLED4.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;     // setting pin_mode to output
    GpioLED4.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLED4.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_Init(&GpioLED4);




    while(1){
    if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == Button)          // Written by Abhishek
    { 
        
        delay();  // To nullify the debouncing effect
        a += 1;
    }

    if (a == 1){
        delay();  // To nullify the debouncing effect
        onetime_press(a - 1);
    }

    if (a == 6){
        delay(); // To nullify the debouncing effect
        twotime_press(a - 1);
    }

    if (a == 11){
        delay(); // To nullify the debouncing effect
        threetime_press(a - 1);
    }

    if (a == 14){
        delay(); // To nullify the debouncing effect
        fourtime_press(a - 1);
    }

    }


}


void onetime_press(int num){                         
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 1);  // making green_led ON
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 1);  // making orange_led ON
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 1);  // making red_led ON
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 1);  // making blue_led ON
}

void twotime_press(int num){
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);  // making green_led OFF
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);  // making orange_led OFF
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);  // making red_led OFF
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0);  // making blue_led OFF
}

void threetime_press(int num){                        // Written By Vinayak
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12); // Toggling green_led  (Clockwise working)
    delay();                                  // Providing Delay

    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);  // Toggling orange_led
    delay();                                // Providing Delay

    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);  // Toggling red_led
    delay();                               // Providing Delay

    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);  // Toggling blue_led
    delay();                          // Providing Delay

}

void fourtime_press(int num){
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15); // Toggling blue_led (Anticlockwise working)
    delay();                                  // Providing Delay

    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);  // Toggling green_led
    delay();                                   // Providing Delay

    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);  // Toggling green_led
    delay();                                  // Providing Delay

    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12); // Toggling green_led
    delay();                                  // Providing Delay

}
