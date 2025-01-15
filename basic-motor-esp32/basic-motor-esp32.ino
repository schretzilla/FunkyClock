#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

// 8-step half-stepping sequence for smoother operation
int steps[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

// Total steps for one full rotation
const int STEPS_PER_REVOLUTION = 2048;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  // Rotate one full revolution clockwise
  rotateStepper(STEPS_PER_REVOLUTION, true);
  delay(1000);  // Pause for 1 second

  // Rotate one full revolution counterclockwise
  rotateStepper(STEPS_PER_REVOLUTION, false);
  delay(1000);  // Pause for 1 second
}

void rotateStepper(int steps, bool clockwise) {
  for (int i = 0; i < steps; i++) {
    int stepIndex = clockwise ? (i % 8) : (7 - (i % 8));
    stepMotor(stepIndex);
    delay(2);  // Adjust delay for motor speed (lower = faster)
  }
}

void stepMotor(int step) {
  digitalWrite(IN1, steps[step][0]);
  digitalWrite(IN2, steps[step][1]);
  digitalWrite(IN3, steps[step][2]);
  digitalWrite(IN4, steps[step][3]);
}
