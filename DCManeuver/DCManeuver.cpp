#include "DCManeuver.h"

DCManeuver::DCManeuver(uint8_t LMF = 4, uint8_t LMB = 2, uint8_t RMF = 8, uint8_t RMB = 7, uint8_t LMS = 3, uint8_t RMS = 6, uint8_t initSpeed = 255) {
	pinMode(LMF, OUTPUT);
	pinMode(LMB, OUTPUT);
	pinMode(RMF, OUTPUT);
	pinMode(RMB, OUTPUT);
	analogWrite(RMS, initSpeed);
	analogWrite(LMS, initSpeed);
	_leftMotorForward = LMF;
	_rightMotorForward = RMF;
	_leftMotorBackward = LMB;
	_rightMotorBackward = RMB;
	_leftMotorSpeed = LMS;
	_rightMotorSpeed = RMS;
	_leftMotorSpeedSetting = initSpeed;
	_rightMotorSpeedSetting = initSpeed;
}

DCManeuver::~DCManeuver() {
	analogWrite(_leftMotorSpeed, 0);
	analogWrite(_rightMotorSpeed, 0);
	digitalWrite(_leftMotorForward, LOW);
	digitalWrite(_rightMotorForward, LOW);
	digitalWrite(_leftMotorBackward, LOW);
	digitalWrite(_rightMotorBackward, LOW);
	pinMode(_leftMotorForward, INPUT);
	pinMode(_leftMotorBackward, INPUT);
	pinMode(_rightMotorForward, INPUT);
	pinMode(_rightMotorBackward, INPUT);
}

void DCManeuver::setSpeedLeft(uint8_t newSpeed) {
	if(newSpeed <= 255 && newSpeed >= 0) {
		_leftMotorSpeedSetting = newSpeed;
		analogWrite(_leftMotorSpeed, _leftMotorSpeedSetting);
	}
}

void DCManeuver::setSpeedRight(uint8_t newSpeed) {
	if(newSpeed <= 255 && newSpeed >= 0) {
		_rightMotorSpeedSetting = newSpeed;
		analogWrite(_rightMotorSpeed, _rightMotorSpeedSetting);
	}
}

void DCManeuver::setSpeed(uint8_t newSpeed) {
	setSpeedLeft(newSpeed);
	setSpeedRight(newSpeed);
}

void DCManeuver::equalizeSpeed() {
	if(_rightMotorSpeedSetting > _leftMotorSpeedSetting) {
		uint8_t diff = (_rightMotorSpeedSetting-_leftMotorSpeedSetting)/2;
		setSpeed(_rightMotorSpeedSetting-diff);
	}
	if(_leftMotorSpeedSetting > _rightMotorSpeedSetting) {
		uint8_t diff = (_leftMotorSpeedSetting-_rightMotorSpeedSetting)/2;
		setSpeed(_leftMotorSpeedSetting-diff);
	}
}

uint8_t DCManeuver::getSpeedLeft() {
	return _leftMotorSpeedSetting;
}

uint8_t DCManeuver::getSpeedRight() {
	return _rightMotorSpeedSetting;
}

void DCManeuver::forward() {
	equalizeSpeed();
	digitalWrite(_leftMotorForward, HIGH);
	digitalWrite(_rightMotorForward, HIGH);
	digitalWrite(_leftMotorBackward, LOW);
	digitalWrite(_rightMotorBackward, LOW);
}

void DCManeuver::backward() {
	equalizeSpeed();
	digitalWrite(_leftMotorForward, LOW);
	digitalWrite(_rightMotorForward, LOW);
	digitalWrite(_leftMotorBackward, HIGH);
	digitalWrite(_rightMotorBackward, HIGH);
}

void DCManeuver::leftTurn() {
	digitalWrite(_leftMotorForward, LOW);
	digitalWrite(_rightMotorForward, HIGH);
	digitalWrite(_leftMotorBackward, HIGH);
	digitalWrite(_rightMotorBackward, LOW);
}

void DCManeuver::rightTurn() {
	digitalWrite(_leftMotorForward, HIGH);
	digitalWrite(_rightMotorForward, LOW);
	digitalWrite(_leftMotorBackward, LOW);
	digitalWrite(_rightMotorBackward, HIGH);
}

void DCManeuver::frontLeftCurve() {
	digitalWrite(_leftMotorForward, LOW);
	digitalWrite(_rightMotorForward, HIGH);
	digitalWrite(_leftMotorBackward, LOW);
	digitalWrite(_rightMotorBackward, LOW);
}

void DCManeuver::frontRightCurve() {
	digitalWrite(_leftMotorForward, HIGH);
	digitalWrite(_rightMotorForward, LOW);
	digitalWrite(_leftMotorBackward, LOW);
	digitalWrite(_rightMotorBackward, LOW);
}

void DCManeuver::backLeftCurve() {
	digitalWrite(_leftMotorForward, LOW);
	digitalWrite(_rightMotorForward, LOW);
	digitalWrite(_leftMotorBackward, LOW);
	digitalWrite(_rightMotorBackward, HIGH);
}

void DCManeuver::backRightCurve() {
	digitalWrite(_leftMotorForward, LOW);
	digitalWrite(_rightMotorForward, LOW);
	digitalWrite(_leftMotorBackward, HIGH);
	digitalWrite(_rightMotorBackward, LOW);
}

void DCManeuver::brake() {
	digitalWrite(_leftMotorForward, HIGH);
	digitalWrite(_rightMotorForward, HIGH);
	digitalWrite(_leftMotorBackward, HIGH);
	digitalWrite(_rightMotorBackward, HIGH);
}

void DCManeuver::coast() {
	digitalWrite(_leftMotorForward, LOW);
	digitalWrite(_rightMotorForward, LOW);
	digitalWrite(_leftMotorBackward, LOW);
	digitalWrite(_rightMotorBackward, LOW);
}