// Define GPIO pins connected to ULN2003 IN1, IN2, IN3, IN4
#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

// Step sequence for 28BYJ-48
int steps[4][4] = {
  {1, 0, 0, 0},  // Coil 1
  {0, 1, 0, 0},  // Coil 2
  {0, 0, 1, 0},  // Coil 3
  {0, 0, 0, 1}   // Coil 4
};

void setup() {
  // Set motor pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize all pins to LOW
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  // Rotate the motor in one direction
  for (int i = 0; i < 512; i++) { // 512 steps for one full revolution
    stepMotor(i % 4);             // Activate one step at a time
    delay(2);                     // Delay controls motor speed
  }

  delay(1000); // Wait 1 second

  // Rotate the motor in the opposite direction
  for (int i = 0; i < 512; i++) {
    stepMotor(3 - (i % 4));       // Reverse step sequence
    delay(2);
  }

  delay(1000); // Wait 1 second
}

void stepMotor(int step) {
  // Set the GPIO pins for the given step
  digitalWrite(IN1, steps[step][0]);
  digitalWrite(IN2, steps[step][1]);
  digitalWrite(IN3, steps[step][2]);
  digitalWrite(IN4, steps[step][3]);
}
