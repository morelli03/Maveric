void potenziometri() {
Lx = map(analogRead(JoyLx), 75, 1023, 0, 600);  if(Lx < 0) Lx = 0;
Ly = map(analogRead(JoyLy), 55, 1023, 0, 600);  if(Ly < 0) Ly = 0;
Rx = map(analogRead(JoyRx), 92, 1023, 0, 600);  if(Rx < 0) Rx = 0;
Ry = map(analogRead(JoyRy), 60, 1023, 0, 600);  if(Ry < 0) Ry = 0;






/*Serial.print("Lx:"); Serial.print(analogRead(JoyLx)); Serial.print(" ");
Serial.print("Ly:"); Serial.print(analogRead(JoyLy)); Serial.print(" ");
Serial.print("Rx:"); Serial.print(analogRead(JoyRx)); Serial.print(" ");
Serial.print("Ry:"); Serial.print(analogRead(JoyRy)); Serial.println(" ");
*/

dtostrf(Lx, 1, 0, matrice_nano_comunicante[0]);
dtostrf(Ly, 1, 0, matrice_nano_comunicante[1]);
dtostrf(Rx, 1, 0, matrice_nano_comunicante[2]);
dtostrf(Ry, 1, 0, matrice_nano_comunicante[3]);

/*
Serial.print("Lx:"); Serial.print(matrice_nano_comunicante[0]); Serial.print(" ");
Serial.print("Ly:"); Serial.print(matrice_nano_comunicante[1]); Serial.print(" ");
Serial.print("Rx:"); Serial.print(matrice_nano_comunicante[2]); Serial.print(" ");
Serial.print("Ry:"); Serial.print(matrice_nano_comunicante[3]); Serial.println(" ");
*/
}

void ingressi() {
 statoPulsOK = !digitalRead(PulsOK);
 statoPulsPIU = !digitalRead(PulsPIU);
 statoPulsMENO = !digitalRead(PulsMENO);
 batteriaTel = map(analogRead(SensBatt), 0, 1023, 0, 25);
 batteriaTel = map(batteriaTel, 4.8, 5.7, 0, 99);
 if(batteriaTel >= 99) batteriaTel = 99;

  if(statoPulsOK && !premutoPulsOK) {TempoOK = millis(); premutoPulsOK = 1;}
  if(millis() - TempoOK <= (attesa500 * 4)){
    if(statoPulsPIU && !premutoPulsPIU) {premutoPulsPIU = 1; page++; if(page > 3) page = 1;}
    if(statoPulsMENO && !premutoPulsMENO) {premutoPulsMENO = 1; page--; if(page < 1) page = 3;}
  }
  else{
    premutoPulsOK = 0;
    premutoPulsPIU = 0;
    premutoPulsMENO = 0;
  }


  digitalWrite(pinVibro, statoVibro);
  statoVibro = 0;

}