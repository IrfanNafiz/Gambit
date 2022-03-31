void SonarSensorRead() 
{
  for (int i=0; i<sonar_max; i++) {
    // Clears the trigPin condition
    digitalWrite(trigs[i], LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigs[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigs[i], LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echos[i], HIGH);
    
    // Calculating the distance
    d[i] = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

    //convert distance[i] to 1s and 0s, 0 means object close, 1 means object far
    for (int i = 0; i<sonar_max; i++) {
      if (distance[i] <= d_threshold)  {d[i] = 0;}
    }

    //using 1/0 distance values to calculate binary
    d_binary = d[0]*32 + d[1]*16 + d[2]*8 + d[3]*4 + d[4]*2 + d{5}*1 //(top, left, center, right), left right
    
    // Displays the distance on the Serial Monitor
    //    Serial.print("Distance: ");
    //    Serial.print(distance);
    //    Serial.println(" cm");
  }


}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
