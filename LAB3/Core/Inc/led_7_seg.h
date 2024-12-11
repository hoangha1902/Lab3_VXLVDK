#ifndef INC_LED_7_SEG_H_
#define INC_LED_7_SEG_H_

#include "global.h"
#include "main.h"
#include "software_timer.h"


extern int led_7_seg_buffer[4];
extern int index_led_7_seg;



void turn_on_led_7seg(int id);

void display_led_7seg(int n);


void update_2_buffer_led_7seg_left(int n1);

void update_2_buffer_led_7seg_right(int n2);

void led_7seg_run();

#endif /* INC_LED_7_SEG_H_ */
