void setup() {
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
  if (b1 == 1 && b2 == 0 && b3 == 1 && b4 == 0)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if (b1 == 1 && b2 == 0 && b3 == 0 && b4 == 1)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  if (b1 == 0 && b2 == 1 && b3 == 1 && b4 == 0)
  {
    digitalWrite(8, HIGH); 
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
