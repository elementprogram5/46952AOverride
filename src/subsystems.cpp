#include "subsystems.hpp"

void detectApriltags(){
    aivision.reset();
    aivision.enable_detection_types(pros::AivisionModeType::tags);
    while (true) {
        auto objects = aivision.get_all_objects();
        for (auto &object : objects) {
            pros::lcd::print(1, "tag\n");
            pros::lcd::print(2, "id: %d", object.id);
            pros::lcd::print(3, "%d %d %d %d %d %d %d %d\n", object.object.tag.x0, object.object.tag.y0, object.object.tag.x1, object.object.tag.y1, object.object.tag.x2, object.object.tag.y2, object.object.tag.x3, object.object.tag.y3);
        }
        pros::delay(20);
    }
}

void runLift(int speed){
    lift_motors.move(speed);
}

void runClaw(double angle, int speed){
    claw_motors.move_absolute(angle, speed);
}


void stopAll() {
    lift_motors.move(0);
}