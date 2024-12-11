#include "BUTTON.h"
int button[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON - 1] = BUTTON_RELEASED};

int flag_pressed[NUMBER_OF_BUTTON] = {0};
int flag_pressed_3s[NUMBER_OF_BUTTON] = {0};

int is_pressed(int index){
	if(index > NUMBER_OF_BUTTON) return 0;
	if(flag_pressed[index]){
		flag_pressed[index] = 0;
		return 1;
	}
	return 0;
}
int is_pressed_3s(int index){
	if(index > NUMBER_OF_BUTTON) return 0;
	if(flag_pressed_3s[index]){
		flag_pressed_3s[index] = 0;
		return 1;
	}
	return 0;
}
int is_button_released(int index){
	if(button_buffer[index] == BUTTON_IS_RELEASED) return 1;
	return 0;
}

int register0[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
int register1[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
int register2[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
int button_buffer[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
void read_input(){
	for(int i = 0 ; i < NUMBER_OF_BUTTON; ++i){
		register0[i] = register1[i];
		register1[i] = register2[i];
		switch(i){
		case 0 :
			 register2[i] = HAL_GPIO_ReadPin(GPIOB, BUTTON0_Pin);
			break;
		case 1:
			register2[i] = HAL_GPIO_ReadPin(GPIOB, BUTTON1_Pin);
			break;
		case 2:
			register2[i] = HAL_GPIO_ReadPin(GPIOB, BUTTON2_Pin);
			break;
		default:
			break;
		}
		if(register0[i] == register1[i] && register1[i] == register2[i]){
			button_buffer[i] = register2[i];
		}
	}
}

void fsm_for_button(){
	for(int i = 0; i < NUMBER_OF_BUTTON; ++i){
		switch(button[i]){
		case BUTTON_RELEASED:
			if(button_buffer[i] == BUTTON_IS_PRESSED){
				flag_pressed[i] = 1;
				set_timer(i, 3000);
				button[i] = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if(is_timer_timeout(i)){
				flag_pressed_3s[i] = 1;
				button[i] = BUTTON_PRESSED_3S;
			}

			if(button_buffer[i] == BUTTON_IS_RELEASED){
				clear_timer(i);
				button[i] = BUTTON_RELEASED;
			}
			break;
		case BUTTON_PRESSED_3S:

			if(button_buffer[i] == BUTTON_IS_RELEASED){
				button[i] = BUTTON_RELEASED;
			}
			break;
		default:
			break;

		}
	}
}
