#include <Servo.h>
#include <nrf24l01.h>
#include <RF24.h>

// Inizializziamo gli oggetti Servo per ciascun motore
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

// Inizializziamo gli oggetti nrf24l01 per la comunicazione wireless
nrf24l01 radio;
const uint64_t pipe = 0xE8E8F0F0E1LL;

// Inizializziamo le variabili per il valore di velocità dei motori
int velocita_motore1 = 0;
int velocita_motore2 = 0;
int velocita_motore3 = 0;
int velocita_motore4 = 0;

void setup() {
  // Assegniamo gli oggetti Servo ai pin dei motori
  motor1.attach(9);
  motor2.attach(10);
  motor3.attach(11);
  motor4.attach(12);

  // Inizializziamo il modulo nrf24l01 e stabiliamo la connessione
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
}

void loop() {
  // Verifichiamo se sono disponibili dati da leggere dal modulo nrf24l01
  if (radio.available()) {
    // Leggiamo i dati dal modulo nrf24l01
    char velocita[4];
    radio.read(&velocita, sizeof(velocita));

    // Convertiamo i dati in valori interi
    velocita_motore1 = atoi(velocita[0]);
    velocita_motore2 = atoi(velocita[1]);
    velocita_motore3 = atoi(velocita[2]);
    velocita_motore4 = atoi(velocita[3]);
  }

  // Inviamo il segnale PWM agli ESC per impostare la velocità dei motori
  motor1.writeMicroseconds(velocita_motore1);
  motor2.writeMicroseconds(velocita_motore2);
  motor3.writeMicroseconds(velocita_motore3);
  motor4.writeMicroseconds(velocita_motore4);

  // Aspettiamo 20ms prima di aggiornare nuovamente la velocità dei motori
  delay(20);
}
