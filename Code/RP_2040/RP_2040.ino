/*Arduino SLAVE ( quello che subisce la comunicazione )*/
//GPS-------------------------------------------------|
#include <TinyGPS++.h>
TinyGPSPlus GPS;
#include <SoftwareSerial.h>

SoftwareSerial ss(2, 3); // definisci il pin 2 come RX e il pin 3 come TX
TinyGPSPlus gps;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <string.h>
#include <Servo.h>
#include <Arduino_LSM6DSOX.h>

//Comunicazione----------------------------------------|
RF24 radio(9, 10);                                         // CE, CSN
                                                           //MISO = 50 -  MOSI = 51 -  SCK = 52
const byte address[][6] = {"00001" , "00002"};              //numero accoppiamento scheda wirless WPASS
int Lx; //512 valore neutro 
int Ly; // ""
int Rx; // ""
int Ry; // ""
char matrice_rp_2040_ricevente[4][5] = {{"0000"}, {"0000"}, {"0000"}, {"0000"}};
bool presenza_radio = 1;
unsigned long UltimaRicezione; // per emergenza
int conteggio = 0; // conta quante volte ha salvato le informazione dal giroscopio
//-----------------------------------------------------|
int batteriaDrone = 69;
double latitudine = 46.045825;
double longitudine  = 11.137513;
int altezza = 267;
int velocita = 0;
int Pm1 = 100;
int Pm2 = 100;
int Pm3 = 100;
int Pm4 = 100;
int asseX = 10;
int asseY = 10;
char matrice_rp_2040_comunicante1[7][4] = {{"0"},{"0"},{"0"},{"0"},{"0"},{"0"},{"0"}};
char matrice_rp_2040_comunicante2[2][6] = {{"0"},{"0"}};
char matrice_rp_2040_comunicante3[2][10] = {{"0"},{"0"}};
//batteriaDrone, latitudine, longitudine, altezza, velocita, Pm1, Pm2, Pm3, Pm4, asseX, asseY


//Map--------------------------------------------------|
int potenza_map = 0;

//Gps--------------------------------------------------|
long TempoGps;

//Rotazione--------------------------------------------|
bool X_orario = 0;
bool X_anti_orario = 0;
int percentualeXa;
int percentualeXo;
int potenza1_rotazione;
int potenza2_rotazione;
int potenza3_rotazione;
int potenza4_rotazione;
//-----------------------------------------------------|

//Inclinazione-----------------------------------------|
float gradiEst;
float gradiOvest;
float gradiNord;
float gradiSud;
int potenza1_stabilizzazione;
int potenza2_stabilizzazione;
int potenza3_stabilizzazione;
int potenza4_stabilizzazione;
int potenza1_stabilizzazione2;
int potenza2_stabilizzazione2;
int potenza3_stabilizzazione2;
int potenza4_stabilizzazione2;
int potenza1_finale;
int potenza2_finale;
int potenza3_finale;
int potenza4_finale;
//-----------------------------------------------------|

//Giroscopio--------------------------------------------------|
float rotX; //(roll, rollio)
float rotY; //(pitch, beccheggio)
float rotXin;
float rotYin;
float x, y, z;
//-----------------------------------------------------|

//Stabilizzazione--------------------------------------|
/*int potenza1_stabilizzazione;
int potenza2_stabilizzazione;
int potenza3_stabilizzazione;
int potenza4_stabilizzazione;
int potenza1_stabilizzazione2;
int potenza2_stabilizzazione2;
int potenza3_stabilizzazione2;
int potenza4_stabilizzazione2;*/
int percentualeRotX;
int percentualeRotY;
//-----------------------------------------------------|

//Motori-----------------------------------------------|
Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;
//-----------------------------------------------------|
int fg1 = 40;
int fg2 = 40;
int fg3 = 40;
int fg4 = 28;


void setup() {
  //Comunicazione ---------------------------------------|
  Serial.begin(115200);

  //Gps-----------|
  ss.begin(9600);

  radio.begin();                                            //accendo la ricetrasmittente
  radio.openWritingPipe(address[0]);                        //configuro il numero di accoppiamento "00001" per scrivere
  radio.openReadingPipe(1, address[1]);                     //dichiaro che ci sarà una sola comunicazione e configuro il numero di accoppiamento "00002" per leggere
                                                            //gli accoppiamenti drovranno essere scambiati nell'altro arduino per permettere il giusto accoppiamento fra il writing del primo e il reading del secondo arduino
  radio.setPALevel(RF24_PA_MIN);                            //imposto la potenza della ricetrasmittente al minimo
                                                           //gli accoppiamenti drovranno essere scambiati nell'altro arduino per permettere il giusto accoppiamento fra il writing del primo e il reading del secondo arduino
  

  //Motori-----------------------------------------------|
  ESC1.attach(2);  // collega l'ESC al pin 2 di Arduino
  ESC2.attach(3);  // collega l'ESC al pin 3 di Arduino
  ESC3.attach(4);  // collega l'ESC al pin 4 di Arduino
  ESC4.attach(5);  // collega l'ESC al pin 5 di Arduino

  //-----------------------------------------------------|
  ESC1.writeMicroseconds(2100);
  ESC2.writeMicroseconds(2100);
  ESC3.writeMicroseconds(2100);
  ESC4.writeMicroseconds(2100);

  delay(3000);

  
  //-----------------------------------------------------|
  ESC1.writeMicroseconds(900);
  ESC2.writeMicroseconds(900);
  ESC3.writeMicroseconds(900);
  ESC4.writeMicroseconds(900);

  delay(2000);
  
  
  //-----------------------------------------------------|
  //while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  
}


void loop() {
  itoa(batteriaDrone, matrice_rp_2040_comunicante1[0], 10);
  gps();
  comunicazione();
  map();
  rotazione();
  giroscopio();
  inclinazione();
  stabilizzazione();
  if (presenza_radio == 0) emergenza();
  motori();
  
  /*Serial.print(potenza1_inclinazione2); Serial.print("P1 ");
  Serial.print(potenza2_inclinazione2); Serial.print("P2 ");
  Serial.print(potenza3_inclinazione2); Serial.print("P3 ");
  Serial.print(potenza4_inclinazione2); Serial.println("P4 ");*/
} 
