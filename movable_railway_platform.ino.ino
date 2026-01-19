// -------- Pin Definitions --------
#define SENSOR_PIN 2      // Digital input from IR sensor
#define MOTOR_IN1 8       // Motor driver input 1
#define MOTOR_IN2 9       // Motor driver input 2

// -------- Setup Function --------
void setup() {
  // Configure sensor pin as input
  pinMode(SENSOR_PIN, INPUT);

  // Configure motor driver pins as output
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

  // Initial state: platform in normal position
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
}

// -------- Loop Function --------
void loop() {
  // Read sensor value
  int trainDetected = digitalRead(SENSOR_PIN);

  if (trainDetected == HIGH) {
    // Train detected → move platform to safe position
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
  } 
  else {
    // No train → return platform to normal position
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
  }

  // Small delay for stability
  delay(500);
}