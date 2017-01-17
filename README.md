# C++ Swerve Library
### Functions
##### Constructor
` swerve = new swervelib(`***`wheel base`***`,`***`track width`***`); `

##### Wheel Vector Calculation
` swerve->calcWheelVect(`***`x`***`, `***`y`***`, `***`rudder`***`); `

##### Casting Values to Motors
The servwelib vector calculation returns a struct with variables for wheel speed and wheel angle.
Variables are named such that their number coincides with that quadrant of the robot.

| Variable Names    | Physical Location |
|-------------------|-------------------|
| speed1 and angle1 | Front Right       |
| speed2 and angle2 | Front Left        |
| speed3 and angle3 | Back Left         |
| speed4 and angle4 | Back Right        |

***`PID Controller`***`->SetSetpoint(swerveLib->whl-> `***`variable name`***`);`
