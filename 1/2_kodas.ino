const int DATA = 10;
const int CLOCK = 11;
const int LATCH = 12;

const byte states[11] = {
    191, 134, 219, 207, 230,
    237, 253, 135, 255, 239,
    0
};

void display(int left, int right) {
    digitalWrite(LATCH, LOW);

    shiftOut(DATA, CLOCK, MSBFIRST, states[left]);
    shiftOut(DATA, CLOCK, MSBFIRST, states[right]);

    digitalWrite(LATCH, HIGH);
}

void explode() {
    // Rodo skaičių nuo 10 iki 0
    for (int i = 10; i >= 0; i--) {
        display(i / 10, i % 10);
        delay(500);
    }

    // 0 mirksi 5 kartus ir kolonėlė pypsi
    for (int i = 0; i < 5; i++) {
        display(10, 10);

        for (int j = 0; j < 250; j++) {
            digitalWrite(A0, HIGH);
            delay(1);
            digitalWrite(A0, LOW);
            delay(1);
        }

        display(0, 0);
        delay(500);
    }
}

void setup() {
    pinMode(DATA, OUTPUT);
    pinMode(CLOCK, OUTPUT);
    pinMode(LATCH, OUTPUT);

    pinMode(A0, OUTPUT);
    pinMode(8, INPUT_PULLUP);

    display(10, 10);
}

void loop() {
    if (digitalRead(8) == LOW)
        explode();
}
