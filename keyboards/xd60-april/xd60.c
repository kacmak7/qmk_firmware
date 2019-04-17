#include "xd60.h"


extern inline void xd60_caps_led_on(void);
extern inline void xd60_bl_led_on(void);

extern inline void xd60_caps_led_off(void);
extern inline void xd60_bl_led_off(void);

extern struct cRGB led[12];

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)
    matrix_scan_user();
    uint8_t layer = biton32(layer_state);
 
	    int red 	= 20;
	    int green 	= 28;
	    int blue 	= 0;
    switch (layer) {
        case 1:
            led[5].r = 255;
            led[5].g = 255;
            led[5].b = 255;

            led[4].r = 255;
            led[4].g = 255;
            led[4].b = 255;
            ws2812_setleds(led, 12);
            break;       
	default:
            /*led[11].r = 45;
            led[11].g = 195;
            led[11].b = 145;

            led[10].r = 255;
            led[10].g = 60;
            led[10].b = 0;

            led[9].r = 255;
            led[9].g = 75;
            led[9].b = 0;

            led[8].r = 255;
            led[8].g = 90;
            led[8].b = 0;

            led[7].r = 255;
            led[7].g = 105;
            led[7].b = 0;
            
	    led[6].r = 255;
            led[6].g = 120;
	    led[6].b = 0;
         
	    led[5].r = 255;
            led[5].g = 120;
            led[5].b = 0;
            
	    led[4].r = 255;
            led[4].g = 105;
            led[4].b = 0;
            
	    led[3].r = 255;
            led[3].g = 90;
            led[3].b = 0;
            
	    led[2].r = 255;
            led[2].g = 75;
            led[2].b = 0;

            led[1].r = 255;
            led[1].g = 60;
            led[1].b = 0;

            led[0].r = 255;
            led[0].g = 45;
            led[0].b = 0;
	    */
	    
	    /*
	    led[11].r = 255;
            led[11].g = 120;
            led[11].b = 0;

            led[10].r = 255;
            led[10].g = 105;
            led[10].b = 0;

            led[9].r = 255;
            led[9].g = 90;
            led[9].b = 0;

            led[8].r = 255;
            led[8].g = 90;
            led[8].b = 0;

            led[7].r = 255;
            led[7].g = 105;
            led[7].b = 0;
            
	    led[6].r = 255;
            led[6].g = 120;
	    led[6].b = 0;
         
	    led[5].r = 255;
            led[5].g = 120;
            led[5].b = 0;
            
	    led[4].r = 255;
            led[4].g = 105;
            led[4].b = 0;
            
	    led[3].r = 255;
            led[3].g = 90;
            led[3].b = 0;
            
	    led[2].r = 255;
            led[2].g = 90;
            led[2].b = 0;

            led[1].r = 255;
            led[1].g = 105;
            led[1].b = 0;

            led[0].r = 255;
            led[0].g = 120;
            led[0].b = 0;
	    */


	    for(i = 0; i < 12; i++) {
		    led[i].r = 45;
		    led[i].g = 195;
		    led[i].b = 145;
	    }
	   
	    /*

	    led[11].r = red;
            led[11].g = green;
            led[11].b = blue;

            led[10].r = red;
            led[10].g = green;
            led[10].b = blue;

            led[9].r = red;
            led[9].g = green;
            led[9].b = blue;

            led[8].r = red;
            led[8].g = green;
            led[8].b = blue;

            led[7].r = red;
            led[7].g = green;
            led[7].b = blue;
            
	    led[6].r = red;
            led[6].g = green;
	    led[6].b = blue;
	    //
	    led[5].r = red;
            led[5].g = green;
            led[5].b = blue;
            
	    led[4].r = red;
            led[4].g = green;
            led[4].b = blue;
            
	    led[3].r = red;
            led[3].g = green;
            led[3].b = blue;
            
	    led[2].r = red;
	    led[2].g = green;
            led[2].b = blue;

            led[1].r = red;
            led[1].g = green;
            led[1].b = blue;

            led[0].r = red;
            led[0].g = green;
            led[0].b = blue;
		*/





            ws2812_setleds(led, 12);
            break;
    }
 
};

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
		xd60_caps_led_on();
	} else {
		xd60_caps_led_off();
  }

  // if (usb_led & (1<<USB_LED_NUM_LOCK)) {
	// xd60_esc_led_on();
	// } else {
	// xd60_esc_led_off();
  // }

  // if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
	// xd60_fn_led_on();
	// } else {
	// xd60_fn_led_off();
  // }

	led_set_user(usb_led);
}
