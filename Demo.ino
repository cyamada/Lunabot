#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11);

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(115200);
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  //controllerSetup();
}

void loop() {
  /*
  if (Serial.available() > 0) {
    int num = Serial.read() - '0';
    if (num == 1) {
      forward(0);
    } else if (num == 2) {
      right(0);
    } else if (num == 3) {
      reverse(0);
    } else if (num == 4) {
      left(0);
    } else if (num == 5) {
      halt();
    }
  }
  */
  //forward(0);
  if (mySerial.available() > 0) {
    char num = mySerial.read();
    Serial.println(num);
    if (num == '1') {
      forward(0);
    } else if (num == '2') {
      right(0);
    } else if (num == '3') {
      reverse(0);
    } else if (num == '4') {
      left(0);
    } else if (num == '5') {
      halt();
    }
  }
  
}


void controllerSetup() {
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
  delay(300);
  analogWrite(3, 255);
  analogWrite(5, 255);
  analogWrite(6, 255);
  analogWrite(9, 255);
  delay(300);
  Serial.println("writing med");
  Serial.println("Release now");
  analogWrite(3, 128);
  analogWrite(5, 128);
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
}

void forward(int spd) {
 analogWrite(3, 174);  //184 stop - 190 reverse
 analogWrite(5, 200);  //back
 analogWrite(6, 200);  //184 stop - 190 reverse
 analogWrite(9, 174);
}

void reverse(int spd) {
 analogWrite(3, 200);
 analogWrite(5, 174);
 analogWrite(6, 174);
 analogWrite(9, 200);
}

void left(int spd) {
 analogWrite(3, 174);
 analogWrite(5, 174);
 analogWrite(6, 174);
 analogWrite(9, 174); 
  
}

void right(int spd) {
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

void something(){
  while( mySerial.available() ){
    char inchar = (char) mySerial.read();//
    Serial.println(inchar);
  }
}
