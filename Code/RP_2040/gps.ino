void gps(){
  if(millis() - TempoGps >= 1000){
  while (ss.available() > 0){
    if (GPS.encode(ss.read())) {
      if (GPS.location.isValid()) {
        //Serial.print("Latitude: ");
        latitudine = (GPS.location.lat(), 6);
        //Serial.print("Longitude: ");
        longitudine = (GPS.location.lng(), 6);
        //Serial.print("Altitude: ");
        altitudine = (GPS.altitude.meters(), 0);
      }
    }
  }

  sprintf(matrice_rp_2040_comunicante3[0], "%lf", latitudine);
  sprintf(matrice_rp_2040_comunicante3[1], "%lf", longitudine);

  itoa(altezza, matrice_rp_2040_comunicante1[1], 10);
  itoa(velocita, matrice_rp_2040_comunicante1[2], 10);

  TempoGps = millis();
  }
}