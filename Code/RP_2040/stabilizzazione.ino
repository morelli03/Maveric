void stabilizzazione() {
  //sarà una merda da programmare, per fortuna sono il miglior programmatore esistente nell'universo
  //if (rotX > 2) potenza1 & potenza4 = (potenza1 & potenza4) + %di inclinazione
  if(rotX >= 0.5 || rotX <= -0.5 || rotY >= 0.5 || rotY <= -0.5){
    if (rotX >= 0.5) {
     percentualeRotX = map(rotX, 0.5, 45, 10, 500);
      //if (percentualeRotX < 0) percentualeRotX = 0;
      potenza2_stabilizzazione = potenza2_rotazione - percentualeRotX;
      potenza3_stabilizzazione = potenza3_rotazione - percentualeRotX;

      potenza1_stabilizzazione = potenza1_rotazione + (percentualeRotX / 2);
      potenza4_stabilizzazione = potenza4_rotazione + (percentualeRotX / 2);
      //Serial.println("Roll sinistra");
    }
    else if (rotX <= -0.5) {
      percentualeRotX = map(rotX, -0.5, -45, 10, 500);
      //if (percentualeRotX < 0) percentualeRotX = 0;
      potenza1_stabilizzazione = potenza1_rotazione - percentualeRotX;
      potenza4_stabilizzazione = potenza4_rotazione - percentualeRotX;

      potenza2_stabilizzazione = potenza2_rotazione + (percentualeRotX / 2);
      potenza3_stabilizzazione = potenza3_rotazione + (percentualeRotX / 2);
      //Serial.println("Roll destra");
    }
    else{
      potenza1_stabilizzazione = potenza1_rotazione;
      potenza4_stabilizzazione = potenza4_rotazione;

      potenza2_stabilizzazione = potenza2_rotazione;
      potenza3_stabilizzazione = potenza3_rotazione;
    }

    if (rotY >= 0.5) {
      percentualeRotY = map(rotY, 0.5, 45, 10, 500);
      //if (percentualeRotY < 0) percentualeRotY = 0;
      potenza1_stabilizzazione2 = potenza1_stabilizzazione - percentualeRotY;
      potenza2_stabilizzazione2 = potenza2_stabilizzazione - percentualeRotY;

      potenza3_stabilizzazione2 = potenza3_stabilizzazione + (percentualeRotY / 2);
      potenza4_stabilizzazione2 = potenza4_stabilizzazione + (percentualeRotY / 2);
      //Serial.println("Pitch indietro");
    }
    else if (rotY <= -0.5) {
      percentualeRotY = map(rotY, -0.5, -45, 10, 500);
      //if (percentualeRotY < 0) percentualeRotY = 0;
      potenza1_stabilizzazione2 = potenza1_stabilizzazione + (percentualeRotY / 2);
      potenza2_stabilizzazione2 = potenza2_stabilizzazione + (percentualeRotY / 2);

      potenza3_stabilizzazione2 = potenza3_stabilizzazione - percentualeRotY;
      potenza4_stabilizzazione2 = potenza4_stabilizzazione - percentualeRotY;
      //Serial.println("Pitch avanti");
    }
    else {
      potenza1_stabilizzazione2 = potenza1_stabilizzazione;
      potenza2_stabilizzazione2 = potenza2_stabilizzazione;

      potenza3_stabilizzazione2 = potenza3_stabilizzazione;
      potenza4_stabilizzazione2 = potenza4_stabilizzazione;
    }
  }
  else {
    potenza1_stabilizzazione2 = potenza1_rotazione;
    potenza2_stabilizzazione2 = potenza2_rotazione;

    potenza3_stabilizzazione2 = potenza3_rotazione;
    potenza4_stabilizzazione2 = potenza4_rotazione;
  }
  
  //if (rotY > 2) potenza4 & potenza3 = (potenza4 & potenza3) + %di inclinazione
  //if (rotY < -2) potenza1 & potenza2 = (potenza1 & potenza2) + %di inclinazione
}