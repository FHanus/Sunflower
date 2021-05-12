
// Stepper motor half step stepping function for each position
void pulseWrite(int pos) {
    switch (pos){
        case 0:
            digitalWrite(stepA, HIGH);
            digitalWrite(stepB, LOW);
            digitalWrite(stepC, LOW);
            digitalWrite(stepD, HIGH);
            //Serial.print("\n1001");
            break;

        case 1:
            digitalWrite(stepA, HIGH);
            digitalWrite(stepB, LOW);
            digitalWrite(stepC, LOW);
            digitalWrite(stepD, LOW);
            //Serial.print("\n1000");
            break;

        case 2:
            digitalWrite(stepA, HIGH);
            digitalWrite(stepB, HIGH);
            digitalWrite(stepC, LOW);
            digitalWrite(stepD, LOW);
            //Serial.print("\n1100");
            break;

        case 3:
            digitalWrite(stepA, LOW);
            digitalWrite(stepB, HIGH);
            digitalWrite(stepC, LOW);
            digitalWrite(stepD, LOW);
            //Serial.print("\n0100");
            break;

        case 4:
            digitalWrite(stepA, LOW);
            digitalWrite(stepB, HIGH);
            digitalWrite(stepC, HIGH);
            digitalWrite(stepD, LOW);
            //Serial.print("\n0110");
            break;

        case 5:
            digitalWrite(stepA, LOW);
            digitalWrite(stepB, LOW);
            digitalWrite(stepC, HIGH);
            digitalWrite(stepD, LOW);
            //Serial.print("\n0010");
            break;

        case 6:
            digitalWrite(stepA, LOW);
            digitalWrite(stepB, LOW);
            digitalWrite(stepC, HIGH);
            digitalWrite(stepD, HIGH);
            //Serial.print("\n0011");
            break;

        case 7:
            digitalWrite(stepA, LOW);
            digitalWrite(stepB, LOW);
            digitalWrite(stepC, LOW);
            digitalWrite(stepD, HIGH);
            //Serial.print("\n0001");
            break;
    }
}

// Half drive calling function for stepper
void halfDrive(int stepDelay, bool backwards) {
    int stepIndex = 0;

    if(backwards == false){
        for (int i = 1; i < numSteps; i++) {
            if(stepIndex==8){
                stepIndex=0;
            }
            Serial.print("\n\n");
            Serial.print(stepIndex);
            if(stepIndex<8){
                pulseWrite(stepIndex);
                stepIndex = stepIndex+1;
            }
            delay(stepDelay);
        }
    }
    if(backwards == true){
        for (int i = 1; i < numSteps; i++) {
            if(stepIndex==-1){
                stepIndex=7;
            }
            Serial.print("\n\n");
            Serial.print(stepIndex);
            if(stepIndex>-1){
                pulseWrite(stepIndex);
                stepIndex = stepIndex-1;
            }
            delay(stepDelay);
        }
    }
}
