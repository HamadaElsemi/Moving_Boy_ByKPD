/*
 * main.c
 *
 *  Created on: Mar 18, 2024
 *      Author: Eng Hamada Ahmed
 *
 */
/*************************LIB**************************/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

/*************************MCAL*************************/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Config.h"
#include "MCAL/DIO/DIO_Private.h"

/*************************HAL**************************/
#include"HAL/LCD/LCD_Interface.h"

/*************************Delay*************************/
#include <util/delay.h>


/**************************ARR OF BOY******************/

	u8 Hamada_Arr[8]={
				0b01110,
				0b01110,
				0b00100,
				0b01110,
				0b10101,
				0b00100,
				0b01010,
				0b10001
		};

int main(){

		DIO_Vid_SetPortDirection(Port_C,output);
		DIO_Vid_SetPortDirection(Port_D,output);
		LCD_Vid_Init();

		//Keypad_Init();

		DIO_Vid_SetPortDirection(Port_B,output);   //Column output
		DIO_Vid_SetPortDirection(Port_A,input);    //Row input pull up
		DIO_Vid_SetPortValue(Port_A,0b00001111);         //pullup




	    u8 Horizontal=0;
	    u8 Vertical=0;
    LCD_VidSendSpecaialChar(Hamada_Arr,0,0,0);
		while(1){
u8 Key = Keypad_u8GetPressedKey();
    if (Key != 101) {
        // '6' moves right
        if (Key == '6') {
            if (Vertical < 15) {
                Vertical++;
            }
        }
        // '4' moves left
        else if (Key == '4') {
            if (Vertical > 0) {
                Vertical--;
            }
        }
        // '2' moves down
        else if (Key == '2') {
            if (Horizontal < 1) {
                Horizontal++;
            }
        }
        // '8' moves up
        else if (Key == '8') {
            if (Horizontal > 0) {
                Horizontal--;
            }
        }
        // Clear the display and send the special character to the updated position
        LCD_vid_DisplayClear();
        LCD_VidSendSpecaialChar(Hamada_Arr, 0, Horizontal, Vertical);
        Key=0xFF;
    }

		}
return 0;
}

