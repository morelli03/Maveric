void schermo() {
  display.clearDisplay();

 //--linea orizzontale di divisione
  display.drawFastHLine(0, 18, 128, SH110X_WHITE);

 //--batteria 1 Telecomando sx
  display.drawBitmap(0, 1, batteria1, 18, 13, 1);
  if(batteriaDrone <= 99 && batteriaDrone >=10){ display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(3, 4); display.println(batteriaTel);}
  else{ display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(6, 4); display.println(batteriaTel);}
  display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(20, 4); display.println("T");

 //--batteria 2 Drone dx
  display.drawBitmap(110, 1, batteria2, 18, 13, 1);
  if(batteriaDrone <= 99 && batteriaDrone >=10){ display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(114, 4); display.println(batteriaDrone);}
  else{ display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(117, 4); display.println(batteriaDrone);}
  display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(103, 4); display.println("D");

 //--icona segnale o segnale perso
  if(segnale)  display.drawBitmap(57, 0, wifi, 15, 15, 1);
  if(!segnale) {display.drawBitmap(57, 0, wifi_off, 15, 15, 1); page = 1;}
  


  switch (page) {
    //--localizzazione
    case 1:
     //immagine gps
      display.drawBitmap(0, 28, gps, 25, 25, 1);
     //--Latitudine
      display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(30, 23); display.println("Lat:");
      display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(54, 23); display.println(matrice_nano_ricevente3[0]);
     //--Longitudine
      display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(30, 38); display.println("Lon:");
      display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(54, 38); display.println(matrice_nano_ricevente3[1]);
     //--Altitudione
      display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(30, 53); display.println("Alt:");
      display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(54, 53); display.println(altezza);
      break;

    //--Potenze per singolo motore
    case 2:
     //immagine drone
      display.drawBitmap(49, 26, drone, 30, 30, 1);
     //--Potenza Motore 1
      if(Pm1 == 100){
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(40, 27); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(21, 27); display.println(Pm1);}
      else if(Pm1 >= 10 && Pm1 <=99){
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(40, 27); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(27, 27); display.println(Pm1);}
      else {
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(40, 27); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(33, 27); display.println(Pm1);}
     //--Potenza Motore 2
      if(Pm2 == 100){
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(101, 27); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(82, 27); display.println(Pm2);}
      else if(Pm2 >= 10 && Pm2 <=99){
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(95, 27); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(82, 27); display.println(Pm2);}
      else {
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(89, 27); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(82, 27); display.println(Pm2);}

     //--Potenza Motore 3
      if(Pm3 == 100){
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(101, 48); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(82, 48); display.println(Pm3);}
      else if(Pm3 >= 10 && Pm3 <=99){
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(95, 48); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(82, 48); display.println(Pm3);}
      else {
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(89, 48); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(82, 48); display.println(Pm3);}

     //--Potenza Motore 4
      if(Pm4 == 100){
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(40, 48); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(21, 48); display.println(Pm4);}
      else if(Pm4 >= 10 && Pm4 <=99){
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(40, 48); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(27, 48); display.println(Pm4);}
      else {
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(40, 48); display.println("%");
        display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(33, 48); display.println(Pm4);}

      break;

    //--inclinazione drone
    case 3:
      //immagine giroscopio
      display.drawBitmap(49, 32, giroscopio, 30, 30, 1);
      display.drawFastHLine(76, 46, 3, SH110X_WHITE);
      display.drawFastHLine(76, 47, 3, SH110X_WHITE);
      display.drawFastVLine(64, 32, 3, SH110X_WHITE);
      display.drawFastVLine(65, 32, 3, SH110X_WHITE);

      //asseX
      if(asseY >= 10 || (asseY < 0 && asseY > -10)){display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(42, 23); display.println("Y "); display.setCursor(50, 23); display.println(asseY);}
      else if(asseY <= -10){display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(36, 23); display.println("Y "); display.setCursor(44, 23); display.println(asseY);}
      else {display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(48, 23); display.println("Y "); display.setCursor(56, 23); display.println(asseY);}
      display.setCursor(80, 23); display.println("'");
      //asseY
      display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(80, 43); display.println("X "); display.setCursor(88, 43); display.println(asseX); 
      if(asseX >= 10 || (asseX < 0 && asseX > -10)) {display.setCursor(118, 43); display.println("'");}
      else if(asseX <= -10) {display.setCursor(122, 43); display.println("'");}
      else {display.setCursor(113, 43); display.println("'");}
      break;
  }

  //visualizzazione numero pagina più lampeggio prima di cambiare pagina
  if(millis() - TempoOK >= attesa200 * 11 || (millis() - TempoOK >= attesa200 && millis() - TempoOK <= attesa200 * 2) || (millis() - TempoOK >= attesa200 * 3 && millis() - TempoOK <= attesa200 * 4) || (millis() - TempoOK >= attesa200 * 5 && millis() - TempoOK <= attesa200 * 6) || (millis() - TempoOK >= attesa200 * 7 && millis() - TempoOK <= attesa200 * 8) || (millis() - TempoOK >= attesa200 * 9 && millis() - TempoOK <= attesa200 * 10)){
    display.setTextSize(1); display.setTextColor(SH110X_WHITE); display.setCursor(121,57); display.println(page);}
  

  display.display();
}