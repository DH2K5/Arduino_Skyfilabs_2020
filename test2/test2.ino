void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

void loop() {
  int p1 = digitalRead(4);
  int p2 = digitalRead(5);
  int p3 = digitalRead(6);
  int p4 = digitalRead(7);
  Serial.println(p1 + p2 + p3 + p4);
}
