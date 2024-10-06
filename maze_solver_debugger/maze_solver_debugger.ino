void moveforward(){
  digitalWrite(8, HIGH); 
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void moveleft(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH );
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void moveright(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
void movestop(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
void left(){
  int mt = 700;
  while(mt > 600){
    moveleft();
    mt = analogRead(A2);
  }
}
void right(){
  int lt = 700;
  while(lt > 600){
    moveright();
    lt = analogRead(A1);
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop() {
  int l = analogRead(A1);
  int m = analogRead(A2);
  int r = analogRead(A0);
  if ((l < 600) && (m < 600) && (r > 600)){ // Left T
    left();
  }
  else if ((l < 600) && (m > 600) && (r < 600)){ // Vertical T
    left();
  }
  else if ((l < 600) && (m > 600) && (r > 600)){ // Left turn
    left();
  }
  else if ((l > 600) && (m < 600) && (r < 600)){ // Right T
    moveforward();
  }
  else if ((l > 600) && (m < 600) && (r > 600)){ // Straight line
    moveforward();
  }
  else if ((l > 600) && (m > 600) && (r < 600)){ // Right turn
    moveforward();
    delay(1000);
    movestop();
    delay(100);
    right();
  }
  else if ((l > 600) && (m > 600) && (r > 600)){ // off path / dead end
    moveright();
    delay(150);
    int rt = analogRead(A1);
    int lt = analogRead(A2);
    int mt = analogRead(A0);
    if ((l > 600) && (m > 600) && (r > 600)){ // dead end
      left();
    }
  }
  else if ((l < 600) && (m < 600) && (r < 600)){ // 4 way / end
    moveforward();
    delay(500);
    int rt = analogRead(A1);
    int lt = analogRead(A2);
    int mt = analogRead(A0);
    if ((lt < 600) && (mt < 600) && (rt < 600)){ // end
      movestop();
      delay(10000);
    }
    else{ // 4 way
      moveleft();
      delay(500);
      left();
    }
  }
}
