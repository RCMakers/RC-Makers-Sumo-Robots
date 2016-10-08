The DCManeuver library simplifies the process of programming Arduino robots that rely on two DC motors to move. The documentation of the class's functions are as such:

**Constructor:**

*`DCManeuver::DCManeuver(uint8_t leftMotorForward = 4, leftMotorBackward = 2, rightMotorForward = 8, rightMotorBackward = 7, leftMotorSpeedControl = 3, rightMotorSpeedControl = 6, initialSpeed = 255)`*

Sets all appropriate pins to "OUTPUT" mode and analog-writes 255 to both speed pins. All arguments besides `initialSpeed` are the numbers of the pins connected to the corresponding functions on the motor controller.

_(**NOTE:** Both `SpeedControl` arguments must be PWM-enabled pins.)_


**Speed Control:**

*`void changeSpeed[Right/Left](uint8_t newSpeed)`*

Sets the value being transmitted to the speed control pins of the left or right motor (or both) to `newSpeed`.


*`DCManeuver::void equalizeSpeed()`*

Sets the value being transmitted to the speed control pins of the left and right motors to the average of their previous values.


*`DCManeuver::uint8_t getSpeed[Right/Left]()`*

Returns the value last written to either motor's speed control pin.
	

**Movement**:

_(**NOTE:** If unspecified, these functions set a movement pin to `LOW`.)_

*`DCManeuver::void forward()`*

Sets the forward pins of both motors to `HIGH`.

	
*`DCManeuver::void backward()`*

Sets the backward pins of both motors to `HIGH`.
	

*`DCManeuver::void leftTurn()`*

Sets the forward pin of the right motor and the backward pin of the left motor to `HIGH`.


*`DCManeuver::void rightTurn()`*

Sets the forward pin of the left motor and the backward pin of the right motor to `HIGH`.


*`DCManeuver::void frontLeftCurve()`*

Sets the forward pin of the right motor to `HIGH`.


*`DCManeuver::void frontRightCurve()`*

Sets the forward pin of the left motor to `HIGH`.


*`DCManeuver::void backLeftCurve()`*

Sets the backward pin of the right motor to `HIGH`.


*`DCManeuver::void backRightCurve()`*

Sets the backward pin of the left motor to `HIGH`.


*`DCManeuver::void brake()`*

Sets all movement pins to `HIGH`.


*`DCManeuver::void coast()`*

Sets all movement pins to `LOW`.
