void init_BT() {
  
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
//  Serial.begin(9600);
  mySerial.println("Hello Bluetooth");
  Serial.println("Hello USB");
}

void com_BT() {
  mySerial.print("Sonar: ");
  mySerial.println(distance);

  mySerial.print("Analog: ");
  mySerial.print(s1);
  mySerial.print(" ");
  mySerial.print(s2);
  mySerial.print(" ");
  mySerial.print(s3);
  mySerial.print(" ");
  mySerial.print(s4);
  mySerial.print(" ");
  mySerial.print(s5);
  mySerial.print(" ");
  mySerial.print(s6);
  mySerial.print(" ");

  mySerial.print("BIN: ");
  mySerial.print(v1);
  mySerial.print(" ");
  mySerial.print(v2);
  mySerial.print(" ");
  mySerial.print(v3);
  mySerial.print(" ");
  mySerial.print(v4);
  mySerial.print(" ");
  mySerial.print(v5);
  mySerial.print(" ");
  mySerial.print(v6);
  mySerial.print(" ");
} 
