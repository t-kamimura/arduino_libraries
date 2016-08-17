#include "Arduino.h"
#include "Motor.h"

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
  analogWrite(motor_pin[2], 0);     //ピン1はH
  analogWrite(motor_pin[3], power);         //ピン2はL
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
