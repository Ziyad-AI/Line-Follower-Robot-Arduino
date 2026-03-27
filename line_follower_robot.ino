#define LEFT_SENSOR 2
#define RIGHT_SENSOR 3

#define MOTOR_LEFT_FORWARD 9
#define MOTOR_LEFT_BACKWARD 10
#define MOTOR_RIGHT_FORWARD 11
#define MOTOR_RIGHT_BACKWARD 12

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
  pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);
}

void loop() {

  int left = digitalRead(LEFT_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);

  if(left == LOW && right == LOW){
    // Move forward
    digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
    digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
  }
  else if(left == HIGH && right == LOW){
    // Turn right
    digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
    digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
  }
  else if(left == LOW && right == HIGH){
    // Turn left
    digitalWrite(MOTOR_LEFT_FORWARD, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
  }
  else{
    // Stop
    digitalWrite(MOTOR_LEFT_FORWARD, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
  }
}
