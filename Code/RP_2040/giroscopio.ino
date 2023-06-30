void giroscopio() {
  conteggio = 0;
  rotXin = 0;
  rotYin = 0;
  while(conteggio != 2){
    if (IMU.accelerationAvailable()) {
      conteggio++;
      IMU.readAcceleration(x, y, z);
      rotXin = rotXin + ((atan2(y, z) * 180.0 / PI) + 1.5);
      rotYin = rotYin + ((atan2(-x, sqrt(y * y + z * z)) * 180.0 / PI) + 0.5);
      //Serial.println(" CALibrazione ");
    }
  }
  rotX = rotXin / 2;
  rotY = rotYin / 2;
  //Serial.print("Roll: "); Serial.print(rotX);
  //Serial.print(" Pitch: "); Serial.println(rotY);

  //__tolgo la virgola
  asseX = rotX * 100;
  asseY = rotY * 100;
  
  itoa(asseX, matrice_rp_2040_comunicante2[0], 10);
  itoa(asseY, matrice_rp_2040_comunicante2[1], 10);

}