void emergenza() {
  while (!radio.available()) {
    int sensore_distanza_Z = 0;
    if (sensore_distanza_Z == 0) {
      //ESC1.writeMicroseconds(900);
      //ESC2.writeMicroseconds(900); 
      //ESC3.writeMicroseconds(900); 
      //ESC4.writeMicroseconds(900);  
      //Serial.println(potenza1_rotazione);
    }
  }
  Serial.println("Ripresa");
}