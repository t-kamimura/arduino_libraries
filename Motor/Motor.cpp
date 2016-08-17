#include "Arduino.h"
#include "Motor.h"

// COMMENTS...please read carefully
// right motor	：analogPin1,2
// left motor	：analogPin3,4
/*		1	2	
right	L	H	で前回転
left	H	L	で前回転
*/

Motor::Motor(int analogPin1, int analogPin2, int analogPin3, int analogPin4)
{
	
	pinMode(analogPin1, OUTPUT);
	pinMode(analogPin2, OUTPUT);
	pinMode(analogPin3, OUTPUT);
	pinMode(analogPin4, OUTPUT);
	
	motor_pin[0] = analogPin1;
	motor_pin[1] = analogPin2;
	motor_pin[2] = analogPin3;
	motor_pin[3] = analogPin4;
}

void Motor::forward(int power)
{
	analogWrite(motor_pin[0], 0);     	//ピン1はL
	analogWrite(motor_pin[1], power); 	//ピン2はH
	analogWrite(motor_pin[2], power);   //ピン3はH
	analogWrite(motor_pin[3], 0); 		//ピン4はL
}
void Motor::backward(int power)
{
  analogWrite(motor_pin[0], power);     //ピン1はH
  analogWrite(motor_pin[1], 0);         //ピン2はL
  analogWrite(motor_pin[2], 0);     	//ピン1はH
  analogWrite(motor_pin[3], power);     //ピン2はL
}

void Motor::spin_left(int power)
{
  analogWrite(motor_pin[0], 0);
  analogWrite(motor_pin[1], power);
  analogWrite(motor_pin[2], 0);
  analogWrite(motor_pin[3], power);
}

void Motor::spin_right(int power)
{
  analogWrite(motor_pin[0], power);
  analogWrite(motor_pin[1], 0);
  analogWrite(motor_pin[2], power);
  analogWrite(motor_pin[3], 0);
}

void Motor::stop()
{
	analogWrite(motor_pin[0], 255);
	analogWrite(motor_pin[1], 255);
	analogWrite(motor_pin[2], 255);
	analogWrite(motor_pin[3], 255);
}

void Motor::move(int left_power,int right_power)
{
  if(right_power == 0){
	  r_pwr[0] = 255;
	  r_pwr[1] = 255;
  }else if(right_power > 0){
	  r_pwr[0] = 0;
	  r_pwr[1] = right_power;
  }else{
	  r_pwr[0] = -1*right_power;
	  r_pwr[1] = 0;
  }
  
  if(left_power == 0){
	  l_pwr[0] = 255;
	  l_pwr[1] = 255;
  }else if(left_power > 0){
	  l_pwr[0] = left_power;
	  l_pwr[1] = 0;
  }else{
	  l_pwr[0] = 0;
	  l_pwr[1] = -1*left_power;
  }
  
  analogWrite(motor_pin[0], r_pwr[0]);
  analogWrite(motor_pin[1], r_pwr[1]);
  analogWrite(motor_pin[2], l_pwr[0]);
  analogWrite(motor_pin[3], l_pwr[1]);
}