void moveforward(){
  digitalWrite(8, HIGH); 
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void moveright(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void moveleft(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void movestop(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW); 
}
void left(){
  int midt = 700;
  moveleft();
  delay(200);
  while (midt > 600){
    moveleft();
    midt = analogRead(A2);
  }
}
void rightm(){
  int midt = 700;
  moveright();
  delay(200);
  while (midt > 600){
    moveright();
    midt = analogRead(A2);
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}
void loop() {
  int right = analogRead(A0);
  int left = analogRead(A1);
  int mid = analogRead(A2);
  if((right > 600) && (left > 600) && (mid < 600)){ //straight line
    moveforward();
  }
  else if((right > 600) && (left > 600) && (mid > 600)){ //dead end --- veer off
    moveright();
    delay(200);
    if((right > 600) && (left > 600) && (mid < 600)){
      moveforward();
    }
    else{
      moveleft();
      delay(400);
      if((right > 600) && (left > 600) && (mid < 600)){
        moveforward();
      }
      else{
        int midt = 700;
        moveleft();
        delay(200);
        while (midt > 600){
         moveleft();
         midt = analogRead(A2);
        }
      }
    }
  }
  else if((right > 600) && (left < 600) && (mid > 600)){ //left turn
    int midt = 700;
    moveleft();
    delay(200);
    while (midt > 600){
      moveleft();
      midt = analogRead(A2);
    }
  }
  else if((right < 600) && (left > 600) && (mid > 600)){ //right turn
    rightm();
  }
  else if((right < 600) && (left > 600) && (mid < 600)){ //right T
    moveforward();
  }
  else if((right > 600) && (left < 600) && (mid < 600)){ //left T
    int midt = 700;
    moveleft();
    delay(200);
    while (midt > 600){
      moveleft();
      midt = analogRead(A2);
    }
  }
  else if((right < 600) && (left < 600) && (mid > 600)){ //straight T
    int midt = 700;
      moveleft();
      delay(200);
      while (midt > 600){
        moveleft();
        midt = analogRead(A2);
      }
  }
  else if((right < 600) && (left < 600) && (mid < 600)){ //four way --- end
    moveforward();
    delay(200);
    if((right < 600) && (left < 600) && (mid < 600)){
      movestop();
      delay(100000);
    }
    else{
      int midt = 700;
      moveleft();
      delay(200);
      while (midt > 600){
        moveleft();
        midt = analogRead(A2);
      }
    }
  }
}
