#include <Arduino.h>

int x;
int s1, s2;

int a = 2, b = 3, c = 4, d = 5, e = 6, f = 7, g = 8, dp = 9;
int digit1 = 11, digit2 = 10;

void lightNumber(int numberToDisplay) {
    switch (numberToDisplay) {
        case 0: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW); 
                digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH); break;
        case 1: digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH); 
                digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
        case 2: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, LOW);
                digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, LOW); break;
        case 3: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);
                digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, LOW); break;
        case 4: digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH);
                digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
        case 5: digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, LOW);
                digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
        case 6: digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, LOW);
                digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
        case 7: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH);
                digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
        case 8: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);
                digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
        case 9: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);
                digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
    }
}

void setup() {
    pinMode(a, OUTPUT); pinMode(b, OUTPUT); pinMode(c, OUTPUT);
    pinMode(d, OUTPUT); pinMode(e, OUTPUT); pinMode(f, OUTPUT);
    pinMode(g, OUTPUT); pinMode(dp, OUTPUT);
    pinMode(digit1, OUTPUT); pinMode(digit2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i <= 20; i++) {
        s1 = i / 10; // Chữ số hàng chục
        s2 = i % 10; // Chữ số hàng đơn vị

        lightNumber(s1);
        digitalWrite(digit1, HIGH);
        digitalWrite(digit2, LOW);
        delay(5);
        
        lightNumber(s2);
        digitalWrite(digit1, LOW);
        digitalWrite(digit2, HIGH);
        delay(5);
        
        Serial.println(i);
        delay(1000);
    }
}
