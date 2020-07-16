
const int  BTN_OPEN_INPUT_PIN  = 2; // D2;
const int  BTN_CLOSE_INPUT_PIN  = 4; //D4;
const int  RELAY_OPEN_OUTPUT_PIN  = 10; //D10;
const int  RELAY_CLOSE_OUTPUT_PIN  = 12; //D12;



void setup()
{
    pinMode(BTN_OPEN_INPUT_PIN, INPUT);
    pinMode(BTN_CLOSE_INPUT_PIN, INPUT);
    pinMode(RELAY_OPEN_OUTPUT_PIN, OUTPUT);
    pinMode(RELAY_CLOSE_OUTPUT_PIN, OUTPUT);

}

void loop()
{
    if (digitalRead(BTN_OPEN_INPUT_PIN) == HIGH && digitalRead(BTN_CLOSE_INPUT_PIN) == LOW) // Extend actuator
    {
        digitalWrite(RELAY_OPEN_OUTPUT_PIN, HIGH);
        digitalWrite(RELAY_CLOSE_OUTPUT_PIN, LOW);
    } else if (digitalRead(BTN_OPEN_INPUT_PIN) == LOW && digitalRead(BTN_CLOSE_INPUT_PIN) == HIGH) { // Retract actuator
        digitalWrite(RELAY_OPEN_OUTPUT_PIN, LOW);
        digitalWrite(RELAY_CLOSE_OUTPUT_PIN, HIGH);
    } else {
      // both buttons are pressed or unpressed at the same time -> don't switch any relay.
      // NOTE: we don't want to switch both relays when both buttons are pressed to avoid a short-circuit
        digitalWrite(RELAY_OPEN_OUTPUT_PIN, LOW);
        digitalWrite(RELAY_CLOSE_OUTPUT_PIN, LOW);
    }
    delay(100);
}
