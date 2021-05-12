#include "initOfVals.h"
#include "basicFunctions.h" 

void setup(){
    Serial.begin(9600);

    // LIMITS
    pinMode(limitL, INPUT);
    pinMode(limitR, INPUT);

    // LDRs
    pinMode(ldrlt, INPUT);
    pinMode(ldrrt, INPUT);
    pinMode(ldrld, INPUT);
    pinMode(ldrrd, INPUT);

    // STEPPER
    pinMode(stepA, OUTPUT);
    pinMode(stepB, OUTPUT);
    pinMode(stepC, OUTPUT);
    pinMode(stepD, OUTPUT);

    // DC MOTOR is covered in the library code for it in initialisation

    Serial.print("\n####################\nStartup\n####################\n");
    delay(3000);
}

void loop(){
    // Measure function
    int lt = analogRead(ldrlt); // top left
    int rt = analogRead(ldrrt); // top right
    int ld = analogRead(ldrld); // down left
    int rd = analogRead(ldrrd); // down right

    int dvertical = ((lt + rt) / 2) - ((ld + rd) / 2); // check the difference of up and down with left top and right top average minus the bottom average
    int dhorizontal = ((lt + ld) / 2) - ((rt + rd) / 2);// check the difference of left and right with left top and left down average minus the right average

    // Check the difference and move VERTICAL AXIS
    if (-1*tolerance > dvertical || dvertical > tolerance){ // check if the difference is in the tolerance else change vertical angle
        if (avt > avd){
            halfDrive(10, true);     
        }
        else if (avt < avd){
            halfDrive(10, false);     
        }
    }

    // Check the difference and move HORIZONTAL AXIS
    if (-1*tolerance > dhorizontal || dhorizontal > tolerance){ // check if the difference is in the tolerance else change horizontal angle
        if (avl > avr){
            if (digitalRead(limitL) == HIGH){  
                motor.forward();
                delay(10);             
                motor.stop_motor();
            }
        }
        else if (avl < avr){
            if (digitalRead(limitR) == HIGH){  
                motor.reverse();
                delay(10);            
                motor.stop_motor();
            }
        }
    }   
}
