#include "led_7_seg.h"

int led_7_seg_buffer[4] = {0};
int index_led_7_seg = 0;

void turn_on_led_7seg(int id){
	switch(id){
	case 0:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, RESET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, RESET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, RESET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, RESET);
		break;
	default:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, SET);
		break;
	}
}

void display_led_7seg(int n){
	switch(n){
	case 0:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	default:
		break;
	}
}

void update_2_buffer_led_7seg_left(int n1){
		led_7_seg_buffer[0] = (n1/1000)/10;
		led_7_seg_buffer[1] = (n1/1000)%10;
}
void update_2_buffer_led_7seg_right(int n2){
		led_7_seg_buffer[2] =( n2/1000)/10;
		led_7_seg_buffer[3] = ( n2/1000)%10;
}
void led_7seg_run(){
	// enable the ENi pin ( when index = 0, EN0 = RESET ...);
	turn_on_led_7seg(index_led_7_seg);
	display_led_7seg(led_7_seg_buffer[index_led_7_seg]);
	//switch index after 500ms, index increase 1 and index assign 0 when index = 4;
	if(timer1_flag == 1)//each LED_7SEG run25ms-> 4LED = 1S
	{
		index_led_7_seg= (index_led_7_seg+1)%4;
		set_timer1(25);
	}
}

