/*Função para verificar existencia de obstaculo e
  realizar o desvio caso necessario*/
void OBSTACULO() {

  byte cont = 0;

  //Se a leitura do ultrassonico for menor que 10 realiza o desvio
  if (ultra.distancia_cm() < 15) {
    PARAR(10);
    for (byte x = 0; x < 20; x++) {
      if (ultra.distancia_cm() < 15) {
        cont++;
      }
    }

    if (cont > 10) {
      DESVIO();
    }
  }
  cont = 0;
}

//função de como vai ser feito o desvio quando o sensor ultrassônico encontra um objeto
void DESVIO() {

  ESQUERDA_TRAS(80, 100, 1000);
  DIREITA_FRENTE(80, 100, 1300);
  ATUALIZA_SENSORES();
  while (l_dp < preto && l_dm < preto && l_ep < preto && l_em < preto) {
    ATUALIZA_SENSORES();
    ESQUERDA_FRENTE(90, 100, 1);
  }
}
