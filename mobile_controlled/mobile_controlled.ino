void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop() {
  int p0 = analogRead(A0);
  int p1 = analogRead(A1);
  int p2 = analogRead(A2);
  int p3 = analogRead(A3);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  if ((p0 < 600) && (p1 > 600) && (p2 < 600) && (p3 < 600)){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if ((p0 < 600) && (p1 < 600) && (p2 < 600) && (p3 > 600)){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  if ((p0 < 600) && (p1 < 600) && (p2 > 600) && (p3 < 600)){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  if ((p0 < 600) && (p1 > 600) && (p2 > 600) && (p3 < 600)){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    
  }
}
