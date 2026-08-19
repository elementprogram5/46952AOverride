#include "setup.hpp"

/*
Controller
3 - Left Drive
2 - Right Drive

// Sensors
pros::Optical optical(9);
pros::Imu imu(17);
pros::Rotation vertical_encoder(14);

11,12,13 - Left Motor Group
18,19,20 - Right Motor Group
21 - Radio
*/

// Sensora
pros::Optical optical(9);
pros::Imu imu(17);
pros::Rotation vertical_encoder(14);

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain motors
pros::MotorGroup left_motors({-11, -12, -13}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({18, 19, 20}, pros::MotorGearset::blue);

// LemLib drivetrain
lemlib::Drivetrain drivetrain(
    &left_motors,
    &right_motors,
    12, // trackwidth
    lemlib::Omniwheel::NEW_325,
    450, // rpm
    2    // drift
);

// PID controllers
lemlib::ControllerSettings lateral_controller(
    5.5, 
    0,
    18,
    0,
    0,
    00,
    0, 
    00, 
    0
);

lemlib::ControllerSettings angular_controller(
    3.5, 
    0, 
    17, 
    3, 
    1, 
    100, 
    3, 
    500, 
    0
);

// Tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(
    &vertical_encoder,
    lemlib::Omniwheel::NEW_2,
    -0.875
);

// Drive curves
lemlib::ExpoDriveCurve throttle_curve(3, 10, 1.019);
lemlib::ExpoDriveCurve steer_curve(3, 10, 1.019);

// Odom sensors
lemlib::OdomSensors sensors(
    &vertical_tracking_wheel,
    nullptr,
    nullptr,
    nullptr,
    &imu
);

// Chassis
lemlib::Chassis chassis(
    drivetrain,
    lateral_controller,
    angular_controller,
    sensors,
    &throttle_curve,
    &steer_curve
);