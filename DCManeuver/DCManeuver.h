#ifndef DCMANEUVER_H
#define DCMANEUVER_H

#include <Arduino.h>

class DCManeuver {
public:
	DCManeuver(uint8_t LMF = 4, uint8_t LMB = 2, uint8_t RMF = 8, uint8_t RMB = 7, uint8_t LMS = 3, uint8_t RMS = 6, uint16_t initSpeed = 255, uint16_t max_pwm_value = 255);
	~DCManeuver();
	void setSpeedLeft(uint16_t newSpeed);
	void setSpeedRight(uint16_t newSpeed);
	void setSpeed(uint16_t newSpeed);
	void equalizeSpeed();
	void setMaxPwm(uint16_t max_pwm);
	uint16_t getMaxPwm();
	uint16_t getSpeedLeft();
	uint16_t getSpeedRight();
	void forward();
	void backward();
	void leftTurn();
	void rightTurn();
	void frontLeftCurve();
	void frontRightCurve();
	void backLeftCurve();
	void backRightCurve();
	void brake();
	void coast();
	void joystick(int16_t x, int16_t y);
private:
	uint8_t _leftMotorForward;
	uint8_t _leftMotorBackward;
	uint8_t _rightMotorForward;
	uint8_t _rightMotorBackward;
	uint8_t _leftMotorSpeed;
	uint8_t _rightMotorSpeed;
	uint16_t _leftMotorSpeedSetting = 255;
	uint16_t _rightMotorSpeedSetting = 255;
	uint16_t _maxPwm = 255;
};

#endif