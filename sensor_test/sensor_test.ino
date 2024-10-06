void setup() {
  Serial.begin(9600);
}

void loop() {
  int l = analogRead(A0);
  int m = analogRead(A1);
  int r = analogRead(A2);
  Serial.println(l, m, r);
  delay(500);
}
