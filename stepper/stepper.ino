#include <Stepper.h>

#define steps 2038
Stepper stepper(steps, 9, 11, 10, 12);

void setup() {
  
}

void loop() {
  stepper.setSpeed(7);
  stepper.step(-600);
  stepper.setSpeed(7);
  stepper.step(600);
}
