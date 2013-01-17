#include "WPILib.h"
#include <iostream>
/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class ourRobot : public SimpleRobot
{
	RobotDrive ourRobotDrive; // robot drive system
	Joystick ourJoystick; // only joystick

public:
	ourRobot(void):
		//The values passed to RobotDrive correspond to the motor controllers.
		//This is why MecanumDrive wasn't working; only controllers 1 and 2 were passed. -Chris
//		drive(1,2,3,4),	//these must be initialized in the same order
		ourRobotDrive(1,3,2,4),
		ourJoystick(1)
	//	// as they are declared above.
		{
			ourRobotDrive.SetExpiration(0.1);
			ourRobotDrive.SetInvertedMotor(ourRobotDrive.kFrontLeftMotor,true);
			ourRobotDrive.SetInvertedMotor(ourRobotDrive.kBackLeftMotor,true);
		}
//stick(1);
	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{
		ourRobotDrive.SetSafetyEnabled(false);
		//myRobot.MecanumDrive_Polar(1.0,45.0,12.0);
		//Wait(0.5)
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void)
	{
		ourRobotDrive.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{	
			// drive with arcade style (use right stick)
			//myRobot.ArcadeDrive(stick,true);
//			std::cout << "X " << ourJoystick.GetAxis( ourJoystick.kXAxis) << "\n" << "Y " << ourJoystick.GetAxis( ourJoystick.kYAxis) << "\n";
			//Drive using MecanumDrive; The button input for the last argument controls rotation. 
			//TODO: Tweak the angle to get the lateral movement working; Also ensure the motor controllers correspond correctly. 
			ourRobotDrive.MecanumDrive_Cartesian(ourJoystick.GetAxis(ourJoystick.kXAxis),ourJoystick.GetAxis(ourJoystick.kYAxis), 0, 0);
			//Wait(0.005);				// wait for a motor update time
		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(ourRobot);

