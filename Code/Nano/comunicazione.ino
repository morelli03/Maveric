void comunicazione() {
  radio.stopListening();                                    //metto la ricetrasmittente in modalità trasmissione
  radio.write(&matrice_nano_comunicante, sizeof(matrice_nano_comunicante));                         //spedisco il contenuto della varibile e poi dichiaro la sua grandezza grazie a "sizeof()"
  delay(5);                                                 //aspetto 2 per far avvenire la trasmissione
  
  radio.startListening();                                   //metto la ricetrasmittente in modalità ricezione
  while (radio.available()) {                               //controllo e processo ciò che arriva

  /*char text1[32] = "";                                     //dischiarazione varibiile
  radio.read(&text1, sizeof(text1));                        //leggo, e inserisco la lettura nella varibile e poi dichiaro quanto sarà grande e di che tipo è la variabile grazie a "sizeof()"
  Serial.println(text1);*/
    radio.read(&matrice_nano_ricevente1, sizeof(matrice_nano_ricevente1));                        //leggo, e inserisco la lettura nella varibile e poi dichiaro quanto sarà grande e di che tipo è la variabile grazie a "sizeof()"
    batteriaDrone = String(matrice_nano_ricevente1[0]).toInt();
    altezza = String(matrice_nano_ricevente1[1]).toInt();
    velocita = String(matrice_nano_ricevente1[2]).toInt();
    Pm1 = String(matrice_nano_ricevente1[3]).toInt();
    Pm2 = String(matrice_nano_ricevente1[4]).toInt();
    Pm3 = String(matrice_nano_ricevente1[5]).toInt();
    Pm4 = String(matrice_nano_ricevente1[6]).toInt();

    delay(4.1);
    radio.read(&matrice_nano_ricevente2, sizeof(matrice_nano_ricevente2));
    asseX = String(matrice_nano_ricevente2[0]).toInt(); asseX = asseX / 100;
    asseY = String(matrice_nano_ricevente2[1]).toInt(); asseY = asseY / 100;

    delay(4.1);
    radio.read(&matrice_nano_ricevente3, sizeof(matrice_nano_ricevente3));


    UltimaRicezione = millis();
    segnale = 1;
    delay(5);                                                 //aspetto 2 per far avvenire la ricezione
  }
  
  if(millis() - UltimaRicezione >= 1000){ 
      Serial.println("EMERGENZA");
      segnale = 0;
      //segnalazione intermittenza 2 volte poi pausa del vibro
      if(millis() - TempoVibro < attesa200 || (millis() - TempoVibro >= attesa200 * 2 && millis() - TempoVibro < attesa200 * 3)) statoVibro = 1;
      else if((millis() - TempoVibro >= attesa200 && millis() - TempoVibro < attesa200 * 2) || (millis() - TempoVibro >= attesa200 * 3 && millis() - TempoVibro < attesa200 * 5)) statoVibro = 0;
      else {TempoVibro = millis();}
      
  }
}




/*
radio.stopListening();                                    //metto la ricetrasmittente in modalità trasmissione
  radio.write(&matrice_nano_comunicante, sizeof(matrice_nano_comunicante));                         //spedisco il contenuto della varibile e poi dichiaro la sua grandezza grazie a "sizeof()"
  delay(2);                                                 //aspetto 2 per far avvenire la trasmissione
  
  radio.startListening();                                   //metto la ricetrasmittente in modalità ricezione
  while (radio.available()) {                               //controllo e processo ciò che arriva
    radio.read(&matrice_nano_ricevente, sizeof(matrice_nano_ricevente));                        //leggo, e inserisco la lettura nella varibile e poi dichiaro quanto sarà grande e di che tipo è la variabile grazie a "sizeof()"
    batteriaDrone = String(matrice_nano_ricevente[0]).toInt();
    latitudine = String(matrice_nano_ricevente[1]).toInt();
    longitudine = String(matrice_nano_ricevente[2]).toInt();
    altezza = String(matrice_nano_ricevente[3]).toInt();
    velocita = String(matrice_nano_ricevente[4]).toInt();
    Pm1 = String(matrice_nano_ricevente[5]).toInt();
    Pm2 = String(matrice_nano_ricevente[6]).toInt();
    Pm3 = String(matrice_nano_ricevente[7]).toInt();
    Pm4 = String(matrice_nano_ricevente[8]).toInt();
    asseX = (String(matrice_nano_ricevente[9]).toInt()) / 100;
    asseY = (String(matrice_nano_ricevente[10]).toInt()) / 100;
    
    UltimaRicezione = millis();
    segnale = 1;
  }
  delay(2);                                                 //aspetto 2 per far avvenire la ricezione

  if(millis() - UltimaRicezione >= 1000){ 
      Serial.println("EMERGENZA");
      segnale = 0;
      //segnalazione intermittenza 2 volte poi pausa del vibro
      if(millis() - TempoVibro < attesa200 || (millis() - TempoVibro >= attesa200 * 2 && millis() - TempoVibro < attesa200 * 3)) digitalWrite(pinVibro, 1);
      else if((millis() - TempoVibro >= attesa200 && millis() - TempoVibro < attesa200 * 2) || (millis() - TempoVibro >= attesa200 * 3 && millis() - TempoVibro < attesa200 * 5)) digitalWrite(pinVibro, 0);
      else {TempoVibro = millis();}
  }
*/