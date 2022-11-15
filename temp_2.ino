
int setLed = 13;
String setPattern = "Input Pattern number 1-3";
int previousLED;
int timeout = 100;
char serialData;
char serialDataPrev;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println();
  Serial.println("Welcome my brothers & sister!");
  Serial.println("Opened the Seriel Monitor");
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
    pinMode(setLed, OUTPUT);

}



void turn_on_all_led(){
for(int ledPin = 2; ledPin<=9;ledPin++){
    digitalWrite(ledPin, HIGH);    
  }
  }

 void turn_off_all_led(){
  for(int ledPin = 2; ledPin<=9;ledPin++){
    digitalWrite(ledPin, LOW);    
  }
  }
void turnAllDataLeD3() {
  for (int ledPin = 2; ledPin <= 9; ledPin++) {
    digitalWrite(ledPin, HIGH);
  }
}
void turnAllDataLedOff3() {
  for (int ledPin = 2; ledPin <= 9; ledPin++) {
    digitalWrite(ledPin, LOW);
  }
}
void turnRowLed1() {
  for (int ledPin = 2; ledPin <= 9; ledPin++) {
    digitalWrite(previousLED, LOW);

    //  Serial.println(previousLED);
    digitalWrite(ledPin, HIGH);
    delay(100);
    previousLED = ledPin;

  }
}
void turnRowLedReverse1() {

  for (int ledPin = 9; ledPin >= 2; ledPin--) {
    digitalWrite(previousLED, LOW);
    //  Serial.println(previousLED);
    digitalWrite(ledPin, HIGH);
    delay(100);
    previousLED = ledPin;

  }
}
void loop() {
  // put your main code here, to run repeatedly:
     serialData = Serial.read();

     
     if(serialData == '1' ||  serialData == '2' || serialData == '3'){
     serialDataPrev = serialData;
     }
   

     if (serialDataPrev == '1' ) {
    for(int ledPin = 2; ledPin<=9;ledPin++){
    digitalWrite(ledPin, HIGH);
    delay(1000);
    previousLED=ledPin;
    if(ledPin==9){
      turn_on_all_led();
      delay(100*3);
      turn_off_all_led();
     }
  }
  delay(200);
    }

    if (serialDataPrev == '2') {

      delay(200);
      turnRowLed1();
      delay(200);
      turnRowLedReverse1();
      digitalWrite(setLed, LOW);

    }
    if (serialDataPrev) {

      turnAllDataLeD3();
      delay(timeout * 2);
      turnAllDataLedOff3();
      delay(timeout * 2);
      digitalWrite(setLed, HIGH);

    }

  
    
}
