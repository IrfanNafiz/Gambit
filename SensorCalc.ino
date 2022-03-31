 void TCRTSensorRead() {
  s1 = analogRead(sensor1);
  s2 = analogRead(sensor2);
  s3 = analogRead(sensor3);
  s4 = analogRead(sensor4);
  s5 = analogRead(sensor5);
  s6 = analogRead(sensor6);
//  s7 = analogRead(sensor7);
//  s8 = analogRead(sensor8);
  
  if (s1 < threshold)
  {
    s1 = 0;
  }
  if (s1 > threshold)
  {
    s1 = 1;
  }
  
  if (s2 < threshold)
  {
    s2 = 0;
  }
  if (s2 > threshold)
  {
    s2 = 1;
  }
  
  if (s3 < threshold)
  {
    s3 = 0;
  }
  if (s3 > threshold)
  {
    s3 = 1;
  }
  
  if (s4 < threshold)
  {
    s4 = 0;
  }
  if (s4 > threshold)
  {
    s4 = 1;
  }
  
  if (s5 < threshold)
  {
    s5 = 0;
  }
  if (s5 > threshold)
  {
    s5 = 1;
  }
  
  if (s6 < threshold)
  {
    s6 = 0;
  }
  if (s6 > threshold)
  {
    s6 = 1;
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
    
  
//  data = s1*108 + s2*64 + s3*32 + s4*16 + s5*8 + s6*4 + s7*2 + s8*1; //8 sensors
  data = s1*32 + s2*16 + s3*8 + s4*4 + s5*2 + s6*1; //6 sensors
}
