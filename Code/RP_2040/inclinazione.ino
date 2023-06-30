void inclinazione() {

  //Est
  gradiEst = map(Rx, 0, 330, 2000, 0); //crea la percentuale di attuazione del joystick destro asse x verso destra, in valori compatibili con l'ESC
  gradiEst = gradiEst / 100;
  if (gradiEst < 0) gradiEst = 0; //impedisce che il valore vada in negativo
  //Ovest
  gradiOvest = map(Rx, 600, 340, -2000, 0); //crea la percentuale di attuazione del joystick destro asse x verso destra, in valori compatibili con l'ESC
  gradiOvest = gradiOvest / 100;
  if (gradiOvest > 0) gradiOvest = 0; //impedisce che il valore vada in positivo

  //Nord
  gradiNord = map(Ry, 325, 600, 0, 2000); //crea la percentuale di attuazione del joystick destro asse x verso destra, in valori compatibili con l'ESC
  gradiNord = gradiNord / 100;
  if (gradiNord < 0) gradiNord = 0; //impedisce che il valore vada in negativo

  //Sud
  gradiSud = map(Ry, 0, 315, -2000, 0); //crea la percentuale di attuazione del joystick destro asse x verso destra, in valori compatibili con l'ESC
  gradiSud = gradiSud / 100;
  if (gradiSud > 0) gradiSud = 0; //impedisce che il valore vada in positivo


  rotY = rotY + gradiSud + gradiNord;
  rotX = rotX + gradiEst + gradiOvest;

  //Serial.print("Roll: "); Serial.print(rotX);
  //Serial.print(" Pitch: "); Serial.println(rotY);
}