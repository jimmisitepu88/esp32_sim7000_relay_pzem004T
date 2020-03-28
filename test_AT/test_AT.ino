  #define RXD1 13
  #define TXD1 14

void setup() {
    // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(19200, SERIAL_8N1, RXD1, TXD1);
  pinMode(19, OUTPUT);
  digitalWrite(19, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("kirim AT");
    Serial1.println("AT+CPIN?");delay(100);
    while(Serial1.available()>0){
      Serial.println(Serial1.readString());
    }
    delay(2000);
}
