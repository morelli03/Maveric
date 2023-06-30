void comunicazione(){
delay(5);
  radio.startListening();                                   //metto la ricetrasmittente in modalità ricezione
  if (radio.available()) {                                 //controllo se è arrivato qualcosa
    presenza_radio = 1;
    UltimaRicezione = millis();                                                              //dischiarazione varibiile
    while (radio.available()) { 
    radio.read(&matrice_rp_2040_ricevente, sizeof(matrice_rp_2040_ricevente));                      //leggo, e inserisco la lettura nella varibile e poi dichiaro quanto sarà grande e di che tipo è la variabile grazie a "sizeof()"
    Lx = String(matrice_rp_2040_ricevente[0]).toInt();
    Ly = String(matrice_rp_2040_ricevente[1]).toInt();
    Rx = String(matrice_rp_2040_ricevente[2]).toInt();
    Ry = String(matrice_rp_2040_ricevente[3]).toInt();     
    }

    delay(5);                                               //aspetto 5 per far avvenire la ricezione
    
    radio.stopListening();                                  //metto la ricetrasmittente in modalità trasmissione
    radio.write(&matrice_rp_2040_comunicante1, sizeof(matrice_rp_2040_comunicante1));                       //spedisco il contenuto della varibile e poi dichiaro la sua grandezza grazie a "sizeof()"
    delay(5);
    radio.write(&matrice_rp_2040_comunicante2, sizeof(matrice_rp_2040_comunicante2));
    delay(5);
    radio.write(&matrice_rp_2040_comunicante3, sizeof(matrice_rp_2040_comunicante3));

  }
  else {
    if(millis() - UltimaRicezione >= 500){ 
      presenza_radio = 0;
      Serial.println("EMERGENZA");
    }
  } 


}










/*
radio.startListening();                                   //metto la ricetrasmittente in modalità ricezione
  if (radio.available()) {                                 //controllo se è arrivato qualcosa
  Serial.println("i");
    presenza_radio = 1;
    UltimaRicezione = millis();
    while (radio.available()) {                                                              //dischiarazione varibiile
      radio.read(&matrice_rp_2040_ricevente, sizeof(matrice_rp_2040_ricevente));                      //leggo, e inserisco la lettura nella varibile e poi dichiaro quanto sarà grande e di che tipo è la variabile grazie a "sizeof()"
      Lx = String(matrice_rp_2040_ricevente[0]).toInt();
      Ly = String(matrice_rp_2040_ricevente[1]).toInt();
      Rx = String(matrice_rp_2040_ricevente[2]).toInt();
      Ry = String(matrice_rp_2040_ricevente[3]).toInt();     
    }
   
    delay(2);                                               //aspetto 5 per far avvenire la ricezione
    
    radio.stopListening();                                  //metto la ricetrasmittente in modalità trasmissione
    radio.write(&matrice_rp_2040_comunicante, sizeof(matrice_rp_2040_comunicante));                       //spedisco il contenuto della varibile e poi dichiaro la sua grandezza grazie a "sizeof()"
  }
  else {
    if(millis() - UltimaRicezione >= 500){ 
      presenza_radio = 0;
      Serial.println("EMERGENZA");
    }
  } 

  */
