void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  //controllerSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(3, 170);
  //analogWrite(5, 200);
  /*
  for (int i = 0; i < 57; i++) {
   analogWrite(3, 247-i);
   analogWrite(5, 127 +i);
   delay(500); 
  }
  */
  if (Serial.available() > 0) {
    int num = Serial.read() - '0';
    if (num == 1) {
      forward();
    } else if (num == 2) {
      right();
    } else if (num == 3) {
      reverse();
    } else if (num == 4) {
      left();
    } else if (num == 5) {
      halt();
    }
  }
}


void controllerSetup() {
  //analogWrite(3, 0);
  //analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
  delay(300);
  //analogWrite(3, 255);
  //analogWrite(5, 255);
  analogWrite(6, 255);
  analogWrite(9, 255);
  delay(300);
  Serial.println("writing med");
  Serial.println("Release now");
  //analogWrite(3, 128);
  //analogWrite(5, 128);
  analogWrite(6, 128);
  analogWrite(9, 128);
  delay(3000);
}

void demo() {
 analogWrite(3, 174);  //184 stop - 190 reverse
 analogWrite(5, 200);  //back
 analogWrite(6, 200);  //184 stop - 190 reverse
 analogWrite(9, 174);
 delay(10000);
 analogWrite(3, 200);
 analogWrite(5, 174);
 analogWrite(6, 174);
 analogWrite(9, 200);
 delay(10000);
/*
 analogWrite(3, 174);
 analogWrite(5, 174);
 analogWrite(6, 174);
 analogWrite(9, 174);
 delay(10000);
 analogWrite(3, 200);
 analogWrite(5, 200);
 analogWrite(6, 200);
 analogWrite(9, 200);
 delay(10000);
 //analogWrite(
 */
}

void forward() {
 analogWrite(3, 174);  //184 stop - 190 reverse
 analogWrite(5, 200);  //back
 analogWrite(6, 200);  //184 stop - 190 reverse
 analogWrite(9, 174);
}

void reverse() {
 analogWrite(3, 200);
 analogWrite(5, 174);
 analogWrite(6, 174);
 analogWrite(9, 200);
}

void left() {
 analogWrite(3, 174);
 analogWrite(5, 174);
 analogWrite(6, 174);
 analogWrite(9, 174); 
  
}

void right() {
   analogWrite(3, 200);
 analogWrite(5, 200);
 analogWrite(6, 200);
 analogWrite(9, 200);
}

void halt() {
  analogWrite(3, 184);
 analogWrite(5, 184);
 analogWrite(6, 184);
 analogWrite(9, 184);
}
