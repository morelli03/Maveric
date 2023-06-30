void motori() {
  potenza1_finale = potenza1_stabilizzazione2 - 4;
  potenza2_finale = potenza2_stabilizzazione2 - 0;
  potenza3_finale = potenza3_stabilizzazione2 + 1;
  potenza4_finale = potenza4_stabilizzazione2 - 0;

  if(potenza1_finale < 900) potenza1_finale = 900;  if(potenza2_finale < 900) potenza2_finale = 900;  if(potenza3_finale < 900) potenza3_finale = 900;  if(potenza4_finale < 900) potenza4_finale = 900;
  
  if(potenza1_finale > 2100) potenza1_finale = 2100;  if(potenza2_finale > 2100) potenza2_finale = 2100;  if(potenza3_finale > 2100) potenza3_finale = 2100;  if(potenza4_finale > 2100) potenza4_finale = 2100;
  
  Pm1 = map(potenza1_finale, 900, 2100, 0, 100);
  Pm2 = map(potenza2_finale, 900, 2100, 0, 100);
  Pm3 = map(potenza3_finale, 900, 2100, 0, 100);
  Pm4 = map(potenza4_finale, 900, 2100, 0, 100);


  itoa(Pm1, matrice_rp_2040_comunicante1[3], 10);
  itoa(Pm2, matrice_rp_2040_comunicante1[4], 10);
  itoa(Pm3, matrice_rp_2040_comunicante1[5], 10);
  itoa(Pm4, matrice_rp_2040_comunicante1[6], 10);

  //Serial.print("esc1 = "); Serial.println(potenza1_finale);
  //Serial.print("esc2 = "); Serial.println(potenza2_finale);
  //Serial.print("esc3 = "); Serial.println(potenza3_finale);
  //Serial.print("esc4 = "); Serial.println(potenza4_finale);


  //___ESC1.writeMicroseconds(potenza1_finale);
  //___ESC2.writeMicroseconds(potenza2_finale); 
  //___ESC3.writeMicroseconds(potenza3_finale); 
  //___ESC4.writeMicroseconds(potenza4_finale);  
}