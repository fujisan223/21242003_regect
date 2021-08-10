#include "mbed.h"

class motordrive{
    public:
    static int motor1_1;
    static int motor1_2;
 
    static int motor2_1;
    static int motor2_2;

    static void motorForward() {
        motor1_1 = 1;
        motor1_2 = 0;
        motor2_1 = 1;
        motor2_2 = 0;
    }
 
    static void motorReverse() {
        motor1_1 = 0;
        motor1_2 = 1;
        motor2_1 = 0;
        motor2_2 = 1;
    }
 
    static void motorStop() {
        motor1_1 = 1;
        motor1_2 = 1;
        motor2_1 = 1;
        motor2_2 = 1;
    }

    static void motorRight() {
        motor1_1 = 0;
        motor1_2 = 1;
        motor2_1 = 1;
        motor2_2 = 0;
    }

    static void motorLeft() {
        motor1_1 = 1;
        motor1_2 = 0;
        motor2_1 = 0;
        motor2_2 = 1;
    }

};