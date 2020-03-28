/*const byte REL1 = 32;
const byte REL2 = 23;
const byte REL3 = 17;
const byte REL4 = 2;

const byte REL5 = 27;
const byte REL6 = 26;
const byte REL7 = 25;
const byte REL8 = 33;
*/

const byte REL[] = {32, 23,17,2,27,26,25,33};

void setup() {
  // put your setup code here, to run once:
  pinMode(REL1, OUTPUT);
  pinMode(REL2, OUTPUT);
  pinMode(REL3, OUTPUT);
  pinMode(REL4, OUTPUT);

  pinMode(REL5, OUTPUT);
  pinMode(REL6, OUTPUT);
  pinMode(REL7, OUTPUT);
  pinMode(REL8, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("on all");
    for(int i=0; i<8; i++){
      digitalWrite(REL[i], HIGH);
      delay(1000);
    }
    delay(2000);
    Serial.println("off all");
    for(int i=0; i<8; i++){
      digitalWrite(REL[i], LOW);
      delay(1000);
    }
    delay(2000);
}
