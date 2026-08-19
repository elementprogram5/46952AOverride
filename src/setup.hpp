#pragma once
#include "main.h"
#include "lemlib/api.hpp"

// Sensors
extern pros::Optical optical;
extern pros::Imu imu;
extern pros::Rotation vertical_encoder;

// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern lemlib::Drivetrain drivetrain;
extern lemlib::TrackingWheel vertical_tracking_wheel;
extern lemlib::OdomSensors sensors;
extern lemlib::Chassis chassis;

// Drive curves
extern lemlib::ExpoDriveCurve throttle_curve;
extern lemlib::ExpoDriveCurve steer_curve;