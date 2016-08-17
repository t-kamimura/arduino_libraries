#ifndef Motor_h_
#define Motor_h_
#include "arduino.h"

class Motor
{
public:
	Motor(int analogPin1, int analogPin2, int analogPin3, int analogPin4);
	void forward(int power);
	void backward(int power);
	void spin_right(int power);
	void spin_left(int power);
	void stop();
	void move(int left_power,int right_power);
  
private:
	int motor_pin[4];
	int r_pwr[2];
	int l_pwr[2];
};

#endif