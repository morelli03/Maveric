#include <nrf24l01.h>
#include <RF24.h>

// Inizializziamo gli oggetti nrf24l01 per la comunicazione wireless
nrf24l01 radio;
const uint64_t pipe = 0xE8E8F0F0E1LL;

// Inizializziamo le variabili per il valore dei potenziometri
int potenziometro1 = 0;
int potenziometro2 = 0;

void setup() {
  // Impostiamo i pin dei potenziometri come ingresso
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  // Inizializziamo il modulo nrf24l01 e stabiliamo la connessione
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop() {
  // Leggiamo il valore dei potenziometri dai pin analogici
  potenziometro1 = analogRead(A0);
  potenziometro2 = analogRead(A1);

  // Convertiamo i valori dei potenziometri in stringhe
  String velocita1 = String(potenziometro1);
  String velocita2 = String(potenziometro2);

  // Creiamo una stringa che contiene entrambi i valori
  String velocita = velocita1 + "," + velocita2;

  // Inviamo i valori dei potenziometri all'altro Arduino tramite il modulo nrf24l01
  radio.write(&velocita, sizeof(velocita));

  // Aspettiamo 20ms prima di inviare nuovamente i valori dei potenziometri
  delay(20);
}
