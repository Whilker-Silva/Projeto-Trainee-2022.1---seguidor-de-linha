//função para atualizar valores das leituras nas respctiva variáveis
void ATUALIZA_SENSORES() {
  l_ep = analogRead(ep);
  l_em = analogRead(em);
  l_c = analogRead(c);
  l_dm = analogRead(dm);
  l_dp = analogRead(dp);
}

//Função para mostra valor das leituras no serial
void MOSTRA_SENSORES() {
  ATUALIZA_SENSORES();
  Serial.print(l_ep);
  Serial.print(" | ");
  Serial.print(l_em);
  Serial.print(" | ");
  Serial.print(l_c);
  Serial.print(" | ");
  Serial.print(l_dm);
  Serial.print(" | ");
  Serial.print(l_dp);
  Serial.print("      distancia: ");

  Serial.println(ultra.distancia_cm());

}

//Função pra seguimento de linha
void SEGUELINHA(byte potfrente, byte potcurva) {

  ATUALIZA_SENSORES();

  //Se o sensor central não estiver na linha
  if (l_c < preto) {

    //Verifica se esta deslinhado para esquerda, se sim realiza correção
    if (l_ep > preto || l_em > preto) {
      ESQUERDA_FRENTE(potcurva, 100, 1);
    }

    //Verifica se esta deslinhado para direita, se sim realiza correção
    else if (l_dp > preto || l_dm > preto) {
      DIREITA_FRENTE(potcurva, 100, 1);
    }

    //Caso todos sensores esteja no branco continua realizando movimento para frente mantendo o sentido da curva anterior
    else if (l_dp < preto && l_dm < preto && l_ep < preto && l_em < preto) {
      FRENTE(potcurva, 1);
    }
  }


  //se o sensor central estiver no frente, segue para frente em linha reta
  else {
    FRENTE_RETO(potfrente, 1);
  }
}
