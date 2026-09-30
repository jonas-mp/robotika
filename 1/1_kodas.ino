void explode() {
	// Rodo sk nuo 10 iki 0
    for (int i = 10; i >= 0; i--) {
        display(i / 10, 0);
        display(i % 10, 7);

        delay(500);
    }

    // 0 mirksi 5 kartus ir kolonele pypsi
    for (int i = 0; i < 5; i++) {
        display(10, 0);
        display(10, 7);

        for (int j = 0; j < 250; j++) {
            digitalWrite(A0, HIGH);
            delay(1);
            digitalWrite(A0, LOW);
            delay(1);
        }

        display(0, 0);
        display(0, 7);

        delay(500);
    }
}

const int states[11] = { 191, 134, 219, 207, 230, 237, 253, 135, 255, 239, 0 };
void display(int number, int pinOffset) {
    for (int segment = 0; segment < 7; segment++) {
        digitalWrite(segment + pinOffset, states[number] & (1 << segment));
    }
}

void setup() {
    for (int i = 0; i <= 13; i++)
        pinMode(i, OUTPUT);

    pinMode(A0, OUTPUT);
  	pinMode(A5, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(A5) == LOW) explode();
}
