/* Battle Bot
 *  Author: Afif Al Mamun
 *  Address: https://afifaniks.github.io
 *  Date: December 11, 2019
 */

int onState = 0;
int NUMBER_OF_MOTORS = 2;
int MOTOR1_PIN1 = 3;
int MOTOR1_PIN2 = 4;
int MOTOR2_PIN1 = 5;
int MOTOR2_PIN2 = 6;
int POWER_LED_PIN = 12;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  pinMode(POWER_LED_PIN, OUTPUT);

}

void loop() {
  // digitalWrite(POWER_LED_PIN, HIGH);
  if (Serial.available()) {
    char command = Serial.read();
        Serial.println(command);
    if (command == 'o') {
      Serial.println("OOOO");
      digitalWrite(POWER_LED_PIN, HIGH);
      delay(200);
      onState = 1;
    } else if (command == 'f') {
      digitalWrite(POWER_LED_PIN, LOW);
      onState = 0; // Resetting to neutral
      
      // Turning motors off
      for (int pin = 3; pin <= 6; pin++)
        digitalWrite(pin, LOW);
    }

    if (onState) {
      switch (command) {
        case '0':
          digitalWrite(MOTOR1_PIN1,0);
          digitalWrite(MOTOR1_PIN2,0);
          digitalWrite(MOTOR2_PIN1,1);
          digitalWrite(MOTOR2_PIN2,0);
          Serial.println("Left");
          break;
        case '2':
          // Forward
          digitalWrite(MOTOR1_PIN1,1);
          digitalWrite(MOTOR1_PIN2,0);
          digitalWrite(MOTOR2_PIN1,1);
          digitalWrite(MOTOR2_PIN2,0);
          Serial.println("Forward");
          break;
        case '4':
        // Right
          digitalWrite(MOTOR1_PIN1,1);
          digitalWrite(MOTOR1_PIN2,0);
          digitalWrite(MOTOR2_PIN1,0);
          digitalWrite(MOTOR2_PIN2,0);
          Serial.println("Right");
          break;
        case '6':
          // Backward
          digitalWrite(MOTOR1_PIN1,0);
          digitalWrite(MOTOR1_PIN2,1);
          digitalWrite(MOTOR2_PIN1,0);
          digitalWrite(MOTOR2_PIN2,1);
          Serial.println("Backward");
          break;
      }
    }
  }
}
