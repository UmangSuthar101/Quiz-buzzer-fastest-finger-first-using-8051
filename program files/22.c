#include<reg51.h>

unsigned int digi_val[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};     

// Hex value corresponding to the digits 0 to 9

sbit output_on_pin = P3^0;        // Enable pin to enable the seven segment.

sbit stop_pin = P3^1;        // Stop pin to reset the buzzer.

sbit buzzer_pin=P0^0;        //  Buzzer pin to sound the buzzer.

int flag;


void delay()        // Time delay function

{

    int i,j;

    for(i=0;i<200;i++)

    for(j=0;j<1275;j++);

}


void display(unsigned int current_dig)     

// Function to display the resultant digit on the seven segment and sound the buzzer.

{

    P2=digi_val[current_dig];

    output_on_pin = 1;

    buzzer_pin=0;

    delay();

    buzzer_pin=1;

    while(stop_pin != 0);

}  


void buzzer() //Function to monitor the input switches

{

    flag = 0;

    while(1)

    {

        while (P1 == 0xFF);

        

        while (P1 == 0xFE)        //Check if switch 1 is pressed

        {

            flag = 1;

            display(1);

        }


        while (P1 == 0xFD)        //Check if switch 2 is pressed

        {

            flag = 2;

            display(2);

        }    


        while (P1 == 0xFB )        //Check if switch 3 is pressed

        {

            flag = 3;

            display(3);

        }


        while (P1 == 0xF7 )        //Check if switch 4 is pressed

        {

            flag = 4;

            display(4);

        }


        while (P1 == 0xEF )        //Check if switch 5 is pressed

        {

            flag = 5;

            display(5);

        }


        while (P1 == 0xDF)        //Check if switch 6 is pressed

        {

            flag = 6;

            display(6);

        }


        while (P1 == 0xBF )        //Check if switch 7 is pressed

        {

            flag = 7;

            display(7);

        }


        while (P1 == 0x7F )        //Check if switch 8 is pressed

        {

            flag = 8;

            display(8);

        }

      

        P1 = 0xFF;

        stop_pin = 1;

        output_on_pin = 0;

    }

}


void main()

{

    output_on_pin=0;

    stop_pin = 1;

    P1 = 0xFF;

    buzzer();


}