void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

void loop() {
  int b1 = digitalRead(4);
  int b2 = digitalRead(5);
  int b3 = digitalRead(6);
  int b4 = digitalRead(7);
  Serial.println(String(b1) + String(b2) + String(b3) + String(b4));
}
