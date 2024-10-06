void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  int right = analogRead(A0);
  int left = analogRead(A1);
  if((right > 600) && (left > 600)){
    digitalWrite(8, HIGH); 
    digitalWrite(9, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  if((right < 600) && (left < 600)){
    digitalWrite(8, LOW); 
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  if((right < 600) && (left > 600)){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  if((right > 600) && (left < 600)){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH); 
  }
}
