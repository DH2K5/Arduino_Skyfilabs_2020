#define B1 4
#define B2 5
#define B3 6
#define B4 7
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  pinMode(B3, INPUT);
  pinMode(B4, INPUT);
}

void loop() {
  int D1 = digitalRead(B1);
  int D2 = digitalRead(B2);
  int D3 = digitalRead(B3);
  int D4 = digitalRead(B4);
  Serial.println(String(D1) + String(D2) + String(D3) + String(D4));
  if ((D1 == 1) && (D2 == 0) && (D3 == 1) && (D4 == 0)){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    Serial.println("Forward");
  }
  if ((D1 == 0) && (D2 == 0) && (D3 == 0) && (D4 == 0)){
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    Serial.println("Stop");
  }
  if ((D1 == 0) && (D2 == 1) && (D3 == 1) && (D4 == 0)){
    digitalWrite(8, HIGH); 
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    Serial.println("Right");
  }
  if ((D1 == 1) && (D2 == 0) && (D3 == 0) && (D4 == 1)){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    Serial.println("Left");
  }
  delay(1000);
}
