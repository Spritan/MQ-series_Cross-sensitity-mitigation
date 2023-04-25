// These constants won't change. They're used to give names to the pins used:
const int MQ4Pin1 = A0;  
const int MQ4Pin2 = A1;
const int MQ4Pin3 = A2;
const int MQ7Pin1 = A3;  
const int MQ7Pin2 = A4;
const int MQ7Pin3 = A5;

int MQ4value1 = 0;  
int MQ4value2 = 0;
int MQ4value3 = 0;
int MQ7value1 = 0;  
int MQ7value2 = 0;
int MQ7value3 = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {

  // read the analog in value:
  MQ4value1 = analogRead(MQ4Pin1);  
  MQ4value2 = analogRead(MQ4Pin2);
  MQ4value3 = analogRead(MQ4Pin3);
  MQ7value1 = analogRead(MQ7Pin1);  
  MQ7value2 = analogRead(MQ7Pin2);
  MQ7value3 = analogRead(MQ7Pin3);
  char buffer[553];
  // String = "MQ4-1 ="+String(MQ4value1)+";"+"MQ4-2 ="+String(MQ4value2)+";"+"MQ4-3 ="+String(MQ4value3)+";"+"MQ4-1 ="+String(MQ4value1)+";"+"MQ7-2 ="+String(MQ7value2)+";"+"MQ7-3 ="+String(MQ7value3)+";"
  // sprintf(buffer, "MQ4-1 =%s;MQ4-2 =%s;MQ4-3 =%s;MQ7-1 =%s;MQ7-2 =%s;MQ7-3 =%s;", String(MQ4value1), String(MQ4value2), String(MQ4value3), String(MQ7value1), String(MQ7value2), String(MQ7value3));
  // print the results to the Serial Monitor:
  Serial.print("MQ4-1 =");
  Serial.print(MQ4value1);
  Serial.print(";MQ4-2 =");
  Serial.print(MQ4value2);
  Serial.print(";MQ4-3 =");
  Serial.print(MQ4value3);
  Serial.print(";MQ7-1 =");
  Serial.print(MQ7value1);
  Serial.print(";MQ7-2 =");
  Serial.print(MQ7value2);
  Serial.print(";MQ7-3 =");
  Serial.print(MQ7value3);
  Serial.print(";\n");
  // Serial.println(buffer);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  delay(2);

}