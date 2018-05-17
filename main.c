/*
 * File:   main.c
 * Author: Phil
 *
 * Created on 04 May 2018, 21:28
 */


#include <xc.h>
#include "config.h"
#include <stdio.h>
#include <stdbool.h>
#include "debounce.h"
#include "main.h"
#include "init_ports.h"
#include "config_osc.h"
#include "write_command.h"
#include "config_oled.h"
#include "set_page.h"
#include "set_columns.h"
#include "write_data.h"
#include "clear_oled.h"
#include "putch.h"
#include "set_usart.h"
#include "ioc_enable.h"
#include "init_TMR1.h"
#include "init_TMR0.h"
#include "write_character.h"
#include "splash_screen.h"
#include "setup_vol_scrn.h"
#include "bar_graph.h"
#include "split_digits.h"
#include "state_of_machine.h"

#include "debounce.h"

void main(void) 
{
    init_ports();       // set port directions and SPI setup
    config_osc();       // set osccon bits to generate a 4MHz internal clock
    set_usart();        // setup USART for serial comms with the PC terminal
    init_TMR1();
   // init_TMR0();
    ioc_enable();
    config_oled();      // oled now talking to PIC, but with garbage pixels illuminated on oled
    clear_oled();
    splash_screen();
    __delay_ms(1000);
    clear_oled();
     setup_vol_scrn();
    printf (" Hello world!\n");
    int current_state = VOL;
    count = 1;          // initial volume set to -94dB
    while(1)
    {
        //button_stateCLK = debounce(CLK);   // button state is the debounced version of CLK
        //button_stateDT = debounce(DT);   // button state is the debounced version of DT
        state_of_machine(&current_state);
        if(CLK == 0)
        {
            printf("\n");
            printf("CLK = %d\n",CLK);
            printf("\n");
            printf("count = %d\n", count);
            printf("\n");
            //printf("button_state = %d\n",button_state);
            printf("\n");
        }
    }
        
}
