// DC MOTOR HANDLING
#include<DC_Motor.h>
DC_Motor motor(6, 7);

// STEPPER HANDLING
#define numSteps 20  //2038 is the number of steps in one revolution of motor (28BYJ-48)

#define stepA 8 // Stepper pin 1 ORANGE
#define stepB 9 // Stepper pin 2 BLUE
#define stepD 10 // Stepper pin 3 YELLOW
#define stepC 11 // Stepper pin 4 PINK

// LIMITS
#define limitL 4
#define limitR 5

// LDRs HANDELING
#define ldrlt 1 //LDR top left - BOTTOM LEFT    <--- BDG
#define ldrrt 4 //LDR top right - BOTTOM RIGHT
#define ldrld 3 //LDR down left - TOP LEFT
#define ldrrd 2 //ldr down right - TOP RIGHT

int lt = analogRead(ldrlt); // top left
int rt = analogRead(ldrrt); // top right
int ld = analogRead(ldrld); // down left
int rd = analogRead(ldrrd); // down right

int avt; // average value top
int avd; // average value down
int avl; // average value left
int avr; // average value right
int dvertical; // check the difference of up and down
int dhorizontal;// check the difference og left and right

// OTHER VARIABLES
int tolerance = 25;
