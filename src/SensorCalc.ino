 void TCRTSensorRead() {
  s1 = analogRead(sensor1);
  s2 = analogRead(sensor2);
  s3 = analogRead(sensor3);
  s4 = analogRead(sensor4);
  s5 = analogRead(sensor5);
  s6 = analogRead(sensor6);
//  s7 = analogRead(sensor7);
//  s8 = analogRead(sensor8);

//Serial.print(s1);


  
  if (s1 < threshold)
  {
    v1 = 0;
  }
  if (s1 > threshold)
  {
    v1 = 1;
  }
  
  if (s2 < threshold)
  {
    v2 = 0;
  }
  if (s2 > threshold)
  {
    v2 = 1;
  }
  
  if (s3 < threshold)
  {
    v3 = 0;
  }
  if (s3 > threshold)
  {
    v3 = 1;
  }
  
  if (s4 < threshold)
  {
    v4 = 0;
  }
  if (s4 > threshold)
  {
    v4 = 1;
  }
  
  if (s5 < threshold)
  {
    v5 = 0;
  }
  if (s5 > threshold)
  {
    v5 = 1;
  }
  
  if (s6 < threshold)
  {
    v6 = 0;
  }
  if (s6 > threshold)
  {
    v6 = 1;
  }
  
//  if (s7 < threshold)
//  {
//    s7 = 0;
//  }
//  if (s7 > threshold)
//  {
//    s7 = 1;
//  }
//  
//  if (s8 < threshold)
//  {
//    s8 = 0;
//  }
//  if (s8 > threshold)
//  {
//    s8 = 1;
//  }    
  
//  sdata = s1*108 + s2*64 + s3*32 + s4*16 + s5*8 + s6*4 + s7*2 + s8*1; //8 sensors
  sdata = v6*32 + v5*16 + v4*8 + v3*4 + v2*2 + v1*1; //6 sensors
}
