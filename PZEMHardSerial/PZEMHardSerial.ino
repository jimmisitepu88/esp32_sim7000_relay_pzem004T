#include <PZEM004Tv30.h>
PZEM004Tv30 pzem(&Serial2);
#define RXD2 18 
#define TXD2 16

#define TXD1 14
#define RXD1 13
#define RST 19

void setup() {
  pinMode(RST, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial1.begin(19200, SERIAL_8N1, RXD1, TXD1);
  rst_sim7000();
}

void loop() {
    baca_pzem();
    Serial.println(test_at("AT"));
    Serial.println(test_at("AT+CPIN?"));
    Serial.println(test_at("AT+IPR?"));
}

void baca_pzem(){
    Serial.println("baca pzem");
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();
    Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
    Serial.print("Current: "); Serial.print(current); Serial.println("A");
    Serial.print("Power: "); Serial.print(power); Serial.println("W");
    Serial.print("Energy: "); Serial.print(energy,3); Serial.println("kWh");
    Serial.print("Frequency: "); Serial.print(frequency, 1); Serial.println("Hz");
    Serial.print("PF: "); Serial.println(pf);
    Serial.println();
    delay(2000);
}

String test_at(String cmd){
    int i;
    String bufAT, resAT;
    Serial.println(cmd);
    Serial1.println(cmd);delay(100);
    while(Serial1.available()>0){
      bufAT = Serial1.readString();
    }
    resAT = bufAT; bufAT = "";
    delay(1000);
    return resAT;
}

void rst_sim7000(){
  Serial.println("rst sim7000");
  digitalWrite(RST, HIGH);
  delay(1000);
  digitalWrite(RST, LOW);
  delay(1000);
  digitalWrite(RST, HIGH);
  delay(5000);
}
