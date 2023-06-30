void rotazione(){
  percentualeXo = map(Lx, 325, 0, 0, 100);
  if (percentualeXo < 0) percentualeXo = 0;
  percentualeXa = map(Lx, 335, 600, 0, 100);
  if (percentualeXa < 0) percentualeXa = 0;
  
  potenza2_rotazione = potenza_map + percentualeXa - (percentualeXo / 2);
  potenza4_rotazione = potenza_map + percentualeXa - (percentualeXo / 2);

  potenza1_rotazione = potenza_map + percentualeXo - (percentualeXa / 2);
  potenza3_rotazione = potenza_map + percentualeXo - (percentualeXa / 2);
}