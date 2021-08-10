#include "mbed.h"
#include "hcsr04.h"
#include <vector>
#include "motordrive.hpp"

Serial pc(USBTX, USBRX);
DigitalOut myled(LED1);
HCSR04 usensor1(D2, D3); // Trigger(DO), Echo(PWMIN)
HCSR04 usensor2(D4, D5);
HCSR04 usensor3(D6, D7);

DigitalOut motorDir1(D10);
DigitalOut motorDir2(D11);
 
DigitalOut motorDir3(D8);
DigitalOut motorDir4(D9);
 
void motorForward(void);
void motorStop(void);
void motorReverse(void);
void motorRight(void);
void motorLeft(void);

int borderline = 10;

int motordrive::motor1_1=0;
int motordrive::motor1_2=0;

int motordrive::motor2_1=0;
int motordrive::motor2_2=0;

int main()
{
    pc.baud(115200);
    pc.printf("Start!\r\n");
    std::vector<unsigned int> d(3);
    while(1) {
        usensor1.start();
        usensor2.start();
        usensor3.start();
        wait_ms(100);
        unsigned int dist1 = usensor1.get_dist_cm();
        unsigned int dist2 = usensor2.get_dist_cm();
        unsigned int dist3 = usensor3.get_dist_cm();
        
        myled = !myled;
        wait_ms(500);
        
        d[0] = dist1;
        d[1] = dist2;
        d[2] = dist3;
        
        pc.printf("dist1=%ldcm\r\n", d[0] );
        pc.printf("dist2=%ldcm\r\n", d[1] );
        pc.printf("dist3=%ldcm\r\n", d[2] );
        
        if(*d.begin() <= borderline && *d.begin() >= borderline/2){
            motordrive::motorLeft();
        }
        else if(d[1] <= borderline && d[1] >= borderline/2){
            motordrive::motorForward();
        }
        else if(d[2] <= borderline && d[2] >= borderline/2){
            motordrive::motorRight();
        }  
        else if(dist1 <= borderline/2 || dist2 <= borderline/2 || dist3 <= borderline/2 && dist1 > 0 && dist2 > 0 && dist3 > 0){
            motordrive::motorReverse();
        }  
        else{
            motordrive::motorStop();
        }
        
        motorDir1 = motordrive::motor1_1;
        motorDir2 = motordrive::motor1_2;
        motorDir3 = motordrive::motor2_1;
        motorDir4 = motordrive::motor2_2;
        wait_ms(10);
        
    }
}
