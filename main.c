
//CCS version 10.2.0.00009
#include <msp430.h>
#include <I2C.h>

char text1[17]="  FELIZ NATAL!";
char text2[17]=" Partiu ADC";

int main(void)
{
     WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    //Set LED1 for test routines
    // Set P1.0 as output direction [J7 needs to be connected]
    // LED White: Port P1 / Pin 0
    P1SEL0 &= ~BIT0;
    P1SEL1 &= ~BIT0;
    P1DIR |= BIT0; // Set LED1 as Output
    P1OUT &= ~BIT0; // turn off LED1

    PM5CTL0 &= ~LOCKLPM5;       //to apply the GPIO configurations disable the LOCKLPM5 bit in PM5CTL0

    start_I2C_B1();
    start_LCD_I2C();

    send_LCD_text_I2C(text1,1,0);
    send_LCD_text_I2C(text2,2,0);

   /* while(1){
        P1OUT ^= BIT0;
    }*/
    return 0;
}





