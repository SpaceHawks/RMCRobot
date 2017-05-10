#include <Sabertooth.h>
Sabertooth ST(130);
TimerClass sabertoothTimer;
void SabertoothTestSetup()
{
	SabertoothTXPinSerial.begin(9600);
}
void SabertoothTestLoop()
{
	driveStraight();
}
void driveStraight()
{
	int power;

	// Ramp motor 1 from -127 to 127 (full reverse to full forward),
	// waiting 20 ms (1/50th of a second) per value.
	for (power = -127; power <= 127; power++)
	{
		ST.motor(1, power);
		ST.motor(2, power);
		delay(20);
	}

	// Now go back the way we came.
	for (power = 127; power >= -127; power--)
	{
		ST.motor(1, power); // Tip for SyRen users: Typing ST.motor(power) does the same thing as ST.motor(1, power).
		ST.motor(2, power); // Tip for SyRen users: Typing ST.motor(power) does the same thing as ST.motor(1, power).
		delay(20);          //                      Since SyRen doesn't have a motor 2, this alternative can save you typing.
	}
}